/*
 * Copyright 1993 Christopher Seiwald.
 */

/*
 * make.c - bring a target up to date, once rules are in place
 *
 * This modules controls the execution of rules to bring a target and
 * its dependencies up to date.  It is invoked after the targets, rules,
 * et. al. described in rules.h are created by the interpreting of the
 * jam files.
 *
 * External routines:
 *	make() - make a target, given its name
 *
 * Internal routines:
 * 	make0() - bind and scan everything to make a TARGET
 * 	make1() - execute commands to update a TARGET
 * 	make1a() - execute all actions to build a target
 *	make1b() - execute single command to update a target
 *	make1c() - execute a (piecemeal) piece of a command to update a target
 *	make1u() - remove targets after interrupted command
 *	makexlist() - turn a list of targets into a LIST, for $(<) and $(>)
 */

# include "jam.h"

# include "lists.h"
# include "parse.h"
# include "variable.h"
# include "rules.h"

# include "search.h"
# include "newstr.h"
# include "make.h"
# include "headers.h"
# include "execcmd.h"

static void make0();
static void make1();
static int make1a();
static int make1b();
static int make1c();
static int make1chunk();
static void make1u();
static LIST *makexlist();

# define max( a,b ) ((a)>(b)?(a):(b))

typedef struct {
	int	temp;
	int	updating;
	int	dontknow;
	int	targets;
	int	made;
} COUNTS ;

# define DONTCARE	0
# define DOCARE		1

static char *target_fate[] = 
{
	"init",
	"making",
	"ok",
	"touched",
	"temp",
	"missing",
	"old",
	"update",
	"can't"
} ;

# define spaces(x) ( "                " + 16 - ( x > 16 ? 16 : x ) )

/*
 * make() - make a target, given its name
 */

void
make( n_targets, targets )
int	n_targets;
char	**targets;
{
	int i;
	COUNTS counts[1];

	memset( (char *)counts, 0, sizeof( *counts ) );

	for( i = 0; i < n_targets; i++ )
	    make0( bindtarget( targets[i] ), (time_t)0, 0, counts );

	if( DEBUG_MAKEQ )
	{
	    if( counts->targets )
		printf( "...found %d target(s)...\n", counts->targets );
	}

	if( DEBUG_MAKE )
	{
	    if( counts->temp )
		printf( "...using %d temp target(s)...\n", counts->temp );
	    if( counts->updating )
		printf( "...updating %d target(s)...\n", counts->updating );
	    if( counts->dontknow )
		printf( "...can't make %d target(s)...\n", counts->dontknow );
	}

	for( i = 0; i < n_targets; i++ )
	    make1( bindtarget( targets[i] ), counts );
}

/*
 * make0() - bind and scan everything to make a TARGET
 *
 * Make0() recursively binds a target, searches for #included headers,
 * calls itself on those headers, and calls itself on any dependents.
 */

static void
make0( t, parent, depth, counts )
TARGET	*t;
time_t	parent;
int	depth;
COUNTS	*counts;
{
	TARGETS	*c;
	int	fate, hfate;
	time_t	last, hlast;
	char	*flag = "";

	if( DEBUG_MAKEPROG )
	    printf( "make\t--\t%s%s\n", spaces( depth ), t->name );

	/* 
	 * Step 1: don't remake if already trying or tried 
	 */

	switch( t->fate )
	{
	case T_FATE_MAKING:
	    printf( "warning: %s depends on itself\n", t->name );
	    return;

	default:
	    return;

	case T_FATE_INIT:
	    break;
	}

	t->fate = T_FATE_MAKING;

	/*
	 * Step 2: under the influence of "on target" variables,
	 * bind the target and search for headers.
	 */

	/* Step 2a: set "on target" variables. */

	pushsettings( t->settings );

	/* Step 2b: find and timestamp the target file (if it's a file). */

	if( t->binding == T_BIND_UNBOUND && !( t->flags & T_FLAG_NOTIME ) )
	{
	    t->boundname = search( t->name, &t->time );
	    t->binding = t->time ? T_BIND_EXISTS : T_BIND_MISSING;
	}

	/* If temp file doesn't exist, use parent */

	if( t->binding == T_BIND_MISSING && t->flags & T_FLAG_TEMP && parent )
	{
	    t->time = parent;
	    t->binding = t->time ? T_BIND_TEMP : T_BIND_MISSING;
	}

	/* Step 2c: If its a file, search for headers. */

	if( t->binding == T_BIND_EXISTS )
	    headers( t );

	/* Step 2d: reset "on target" variables */

	popsettings( t->settings );

	/* 
	 * Step 3: recursively make0() dependents 
	 */

	/* Step 3a: recursively make0() dependents */

	last = 0;
	fate = T_FATE_STABLE;

	for( c = t->deps; c; c = c->next )
	{
	    make0( c->target, t->time, depth + 1, counts );
	    last = max( last, c->target->time );
	    last = max( last, c->target->htime );
	    fate = max( fate, c->target->fate );
	    fate = max( fate, c->target->hfate );
	}

	/* Step 3b: recursively make0() headers */

	hlast = 0;
	hfate = T_FATE_STABLE;

	for( c = t->headers; c; c = c->next )
	{
	    make0( c->target, parent, depth + 1, counts );
	    hlast = max( hlast, c->target->time );
	    hlast = max( hlast, c->target->htime );
	    hfate = max( hfate, c->target->fate );
	    hfate = max( hfate, c->target->hfate );
	}

	/* 
	 * Step 4: aftermath: determine fate and propapate dependents time
	 * and fate.
	 */

	/* Step 4a: determine fate: rebuild target or what? */
	/* If children newer than target or */
	/* If target doesn't exist, rebuild.  */

	if( fate > T_FATE_STABLE )
	{
	    fate = T_FATE_UPDATE;
	}
	else if( t->binding == T_BIND_MISSING )
	{
	    fate = T_FATE_MISSING;
	}
	else if( t->binding == T_BIND_EXISTS && last > t->time )
	{
	    fate = T_FATE_OUTDATED;
	}
	else if( t->binding == T_BIND_TEMP && last > t->time )
	{
	    fate = T_FATE_OUTDATED;
	}
	else if( t->binding == T_BIND_EXISTS && t->flags & T_FLAG_TEMP )
	{
	    fate = T_FATE_ISTMP;
	}
	else if( t->flags & T_FLAG_TOUCHED )
	{
	    fate = T_FATE_TOUCHED;
	}

	/* Step 4b: handle missing files */
	/* If it's missing and there are no actions to create it, boom. */
	/* If we can't make a target we don't care about, 'sokay */

	if( fate == T_FATE_MISSING && !t->actions && !t->deps )
	{
	    if( t->flags & T_FLAG_NOCARE )
	    {
		fate = T_FATE_STABLE;
	    }
	    else
	    {
		fate = T_FATE_DONTKNOW;
		printf( "don't know how to make %s\n", t->name );
	    }
	}

	/* Step 4c: Step 6: propagate dependents' time & fate. */

	t->time = max( t->time, last );
	t->fate = fate;

	t->htime = hlast;
	t->hfate = hfate;

	/* 
	 * Step 5: a little harmless tabulating for tracing purposes 
	 */

	if( !( ++counts->targets % 1000 ) && DEBUG_MAKE )
	    printf( "...patience...\n" );

	if( fate > T_FATE_ISTMP && t->actions )
	    counts->updating++;
	else if( fate == T_FATE_ISTMP )
	    counts->temp++;
	else if( fate == T_FATE_DONTKNOW )
	    counts->dontknow++;

	if( t->binding == T_BIND_EXISTS && parent && t->time > parent )
	    flag = "*";

	if( DEBUG_MAKEPROG )
	    printf( "make%s\t%s\t%s%s\n", 
		flag, target_fate[ t->fate ], 
		spaces( depth ), t->name );
}

/*
 * make1() - execute commands to update a TARGET
 */

static void
make1( t, counts )
TARGET	*t;
COUNTS	*counts;
{
	TARGETS	*c;
	char *failed = "dependents";

	/* Don't remake if already trying or tried */

	if( t->progress != T_MAKE_INIT )
		return;

	t->progress = T_MAKE_STABLE;

	/* recurseively make1() headers */

	for( c = t->headers; c && t->progress != T_MAKE_INTR; c = c->next )
	{
	    make1( c->target, counts );

	    if( c->target->progress > t->progress )
	    {
	    	t->progress = c->target->progress;
		failed = c->target->name;
	    }
	}

	/* recursively make1() dependents */

	for( c = t->deps; c && t->progress != T_MAKE_INTR; c = c->next )
	{
	    make1( c->target, counts );

	    if( c->target->progress > t->progress )
	    {
	    	t->progress = c->target->progress;
		failed = c->target->name;
	    }
	}

	/* If it's missing and there are no actions to create it, boom. */
	/* if reasonable, execute all actions to make target */

	if( t->progress == T_MAKE_FAIL )
	{
	    printf( "%s skipped for lack of %s\n", t->name, failed );
	}
	else if( t->progress == T_MAKE_INTR )
	{
	    return;
	}
	else switch( t->fate )
	{
	case T_FATE_INIT:
	case T_FATE_MAKING:
	    /* shouldn't happen */ ;

	case T_FATE_STABLE:
	    break;

	case T_FATE_ISTMP:
	    if( DEBUG_MAKEQ )
		printf( "using %s\n", t->name );
	    t->progress = T_MAKE_OK;
	    break;

	case T_FATE_MISSING:
	case T_FATE_OUTDATED:
	case T_FATE_UPDATE:
	    /* Set "on target" vars, execute actions, unset vars */

	    pushsettings( t->settings );
	    t->progress = make1a( t->name, t->actions );
	    popsettings( t->settings );

	    if( !( ++counts->made % 100 ) && DEBUG_MAKE )
		printf( "...on %dth target...\n", counts->made );

	    break;

	case T_FATE_DONTKNOW:
	    t->progress = T_MAKE_FAIL;
	    break;
	}
}

/*
 * make1a() - execute all actions to build a target
 *
 * Executes all actions to build a given target, if the actions haven't
 * been executed previously.
 *
 * Returns:
 *	T_MAKE_FAIL	execution of command failed
 *	T_MAKE_OK	execution successful
 */

static int
make1a( name, actions )
char	*name;
ACTIONS *actions;
{
	/* Step through actions */
	/* Actions may be shared with other targets or grouped with */
	/* RULE_TOGETHER, so actions already executed are expected. */

	for( ; actions; actions = actions->next )
	{
	    ACTION  *action = actions->action;
	    RULE    *rule = action->rule;
	    LIST    *targets;
	    LIST    *sources;
	    ACTIONS *a1;

	    /* Only do rules with commands to execute. */
	    /* If this action has already been executed, use saved progress */

	    if( !rule->actions )
		continue;
	    
	    switch( action->progress )
	    {
	    case T_MAKE_OK:	continue;
	    case T_MAKE_FAIL:	return T_MAKE_FAIL;
	    case T_MAKE_INIT:	/* fall through */;
	    }

	    /* Make LISTS of targets and sources */
	    /* If `execute together` has been specified for this rule, tack */
	    /* on sources from each instance of this rule for this target. */

	    targets = makexlist( (LIST *)0, action->targets, 0 );
	    sources = makexlist( (LIST *)0, action->sources, 
					rule->flags & RULE_NEWSRCS );

	    if( rule->flags & RULE_TOGETHER )
		for( a1 = actions->next; a1; a1 = a1->next )
		    if( a1->action->rule == rule )
	    {
		sources = makexlist( sources, a1->action->sources, 
					rule->flags & RULE_NEWSRCS );
	    }

	    /* Execute single command, saving progress */
	    /* If `execute together` has been specified for this rule, */
	    /* distribute progress to each instance of this rule. */

	    if( rule->flags & RULE_QUIETLY ? DEBUG_MAKEQ : DEBUG_MAKE )
		printf( "%s %s\n", rule->name, name );

	    action->progress = make1b( rule, targets, sources );

	    if( rule->flags & RULE_TOGETHER )
		for( a1 = actions->next; a1; a1 = a1->next )
		    if( a1->action->rule == rule )
	    {
		a1->action->progress = action->progress;
	    }

	    /* Free target & source lists */

	    list_free( targets );
	    list_free( sources );

	    /* Abandon target if any rule fails. */

	    if( action->progress != T_MAKE_OK )
		return action->progress;
	}
	
	return T_MAKE_OK;
}

/*
 * make1b() - execute single command to update a target
 *
 * Returns:
 *	T_MAKE_FAIL	execution of command failed
 *	T_MAKE_OK	execution successful
 */

static int
make1b( rule, targets, sources )
RULE	*rule;
LIST	*targets;
LIST	*sources;
{
	int	chunk = 0;
	LIST	*somes;
	int	status = T_MAKE_OK;

	/* If rule is to be cut into (at most) MAXCMD pieces, estimate */
	/* bytes per $(>) element and aim for using MAXCMD minus a two */
	/* element pad. */

	if( rule->flags & RULE_PIECEMEAL )
	    chunk = make1chunk( rule->actions, targets, sources );

	/* If cutting rule up, make separate invocations of make1c() for */
	/* each chunk of $(>).  Otherwise, do it 'ole. */

	if( DEBUG_EXEC && chunk )
	    printf( "%d arguments per invocation\n", chunk );

	if( chunk )
	{
	    int start;

	    for( start = 0;
	         somes = list_sublist( sources, start, chunk );
		 start += chunk )
	    {
		status = make1c( rule, targets, somes );
		list_free( somes );
		
		if( status != T_MAKE_OK )
		    break;
	    }
	}
	else
	{
	    status = make1c( rule, targets, sources );
	}

	/* If the command was interrupted and the target is not */
	/* "precious", remove the targets */

	if( status == T_MAKE_INTR && !( rule->flags & RULE_TOGETHER ) )
	    make1u( targets );

	return status;
}

/* 
 * make1c() - execute a (piecemeal) piece of a command to update a target
 */

static int
make1c( rule, targets, sources )
RULE	*rule;
LIST	*targets;
LIST	*sources;
{
	int	len;
	char    buf[ MAXCMD ];

	len = var_string( rule->actions, buf, targets, sources );
	
	if( len > MAXCMD )
	{
	    /* Can't do much here - we just blew our stack! */
	    printf( "fatal error: command too long\n" );
	    exit( -1 );
	}

	if( DEBUG_EXEC )
	    printf( "%s\n", buf );

	if( globs.noexec )
	    return T_MAKE_OK;

	if( DEBUG_MAKE )
	    fflush( stdout );
	
	switch( execcmd( buf ) )
	{
	case EXEC_CMD_OK:
	    return T_MAKE_OK;

	case EXEC_CMD_FAIL:
	    if( rule->flags & RULE_IGNORE )
		return T_MAKE_OK;

	    return T_MAKE_FAIL;

	case EXEC_CMD_INTR: 
	    printf( "...interrupted\n" );
	    return T_MAKE_INTR;

	default:
	    return T_MAKE_FAIL; /* NOTREACHED */
	}
}

static int
make1chunk( cmd, targets, sources )
char	*cmd;
LIST	*targets;
LIST	*sources;
{
	int onesize;
	int onediff;
	int chunk = 0;
	LIST *somes;
	char buf[ MAXCMD ];

	somes = list_sublist( sources, 0, 1 );
	onesize = var_string( cmd, buf, targets, somes );
	list_free( somes );

	somes = list_sublist( sources, 0, 2 );
	onediff = var_string( cmd, buf, targets, somes ) - onesize;
	list_free( somes );

	if( onediff > 0 )
	    chunk = 3 * ( MAXCMD - onesize ) / 4 / onediff + 1;

	return chunk;
}

/*
 * make1u() - remove targets after interrupted command
 */

static void
make1u( targets )
LIST *targets;
{
	for( ; targets; targets = list_next( targets ) )
	{
	    if( !unlink( targets->string ) )
		printf( "%s removed\n", targets->string );
	}
}

/*
 * makexlist() - turn a list of targets into a LIST, for $(<) and $(>)
 */

static LIST *
makexlist( l, targets, newonly )
LIST	*l;
TARGETS	*targets;
int	newonly;
{
    for( ; targets; targets = targets->next )
    {
	TARGET *t = targets->target;

	/*
	 * spot the kludge!  If a target is not in the dependency tree,
	 * it didn't get bound by make0(), so we have to do it here.
	 * Ugly.
	 */

	if( t->binding == T_BIND_UNBOUND && !( t->flags & T_FLAG_NOTIME ) )
	{
	    printf( "warning: using independent target %s\n", t->name );
	    pushsettings( t->settings );
	    t->boundname = search( t->name, &t->time );
	    t->binding = t->time ? T_BIND_EXISTS : T_BIND_MISSING;
	    popsettings( t->settings );
	}

	if( !newonly || t->fate > T_FATE_STABLE )
		l = list_new( l, copystr( t->boundname ) );
    }

    return l;
}
