/*
 * Copyright 1993 Christopher Seiwald.
 */

# include "jam.h"
# include "lists.h"
# include "parse.h"
# include "variable.h"
# include "rules.h"
# include "newstr.h"
# include "hash.h"

/*
 * rules.c - access to RULEs, TARGETs, and ACTIONs
 *
 * External routines:
 *
 *    bindrule() - return pointer to RULE, creating it if necessary
 *    bindtarget() - return pointer to TARGET, creating it if necessary
 *    touchtarget() - mark a target to simulate being new
 *    targetlist() - turn list of target names into a TARGET chain
 *    actionlist - for each target, append an ACTION to its action chain
 *    addsettings() - add a deferred "set" command to a target
 *    usesettings() - set all target specific variables
 *    pushsettings() - set all target specific variables
 *    popsettings() - reset target specific variables to their pre-push values
 *    donerules() - free RULE and TARGET tables
 */

static struct hash *rulehash = 0;
static struct hash *targethash = 0;


/*
 * bindrule() - return pointer to RULE, creating it if necessary
 */

RULE *
bindrule( rulename ) 
char 	*rulename;
{
	RULE rule, *r = &rule;

	if( !rulehash )
	    rulehash = hashinit( sizeof( RULE ), "rules" );

	r->name = rulename;

	if( hashenter( rulehash, (HASHDATA **)&r ) )
	{
	    r->name = newstr( rulename );	/* never freed */
	    r->procedure = (PARSE *)0;
	    r->actions = (char *)0;
	    r->flags = 0;
	}

	return r;
}

/*
 * bindtarget() - return pointer to TARGET, creating it if necessary
 */

TARGET *
bindtarget( targetname )
char	*targetname;
{
	TARGET target, *t = &target;

	if( !targethash )
	    targethash = hashinit( sizeof( TARGET ), "targets" );

	t->name = targetname;

	if( hashenter( targethash, (HASHDATA **)&t ) )
	{
	    memset( (char *)t, '\0', sizeof( *t ) );
	    t->name = newstr( targetname );	/* never freed */
	}

	return t;
}

/*
 * touchtarget() - mark a target to simulate being new
 */

void
touchtarget( t )
char *t;
{
	bindtarget( t )->flags |= T_FLAG_TOUCHED;
}

/*
 * targetlist() - turn list of target names into a TARGET chain
 *
 * Inputs:
 *	chain	existing TARGETS to append to
 *	targets	list of target names
 */

TARGETS *
targetlist( chain, targets )
TARGETS	*chain;
LIST 	*targets;
{
	while( targets )
	{
	    TARGETS *c;

	    c = (TARGETS *)malloc( sizeof( TARGETS ) );
	    c->target = bindtarget( targets->string );

	    if( !chain ) chain = c;
	    else chain->tail->next = c;
	    chain->tail = c;
	    c->next = 0;

	    targets = list_next( targets );
	}

	return chain;
}

/*
 * actionlist - for each target, append an ACTION to its action chain
 */

void
actionlist( targets, action )
TARGETS	*targets;
ACTION	*action;
{
	/* Append this action to the actions of each target */

	for( ; targets; targets = targets->next )
	{
	    ACTIONS *actions = (ACTIONS *)malloc( sizeof( ACTIONS ) );
	    TARGET  *target = targets->target;

	    actions->action = action;

	    if( !target->actions ) target->actions = actions;
	    else target->actions->tail->next = actions;
	    target->actions->tail = actions;
	    actions->next = 0;
	}
}

/*
 * addsettings() - add a deferred "set" command to a target
 */

SETTINGS *
addsettings( head, symbol, value )
SETTINGS *head;
char	*symbol;
LIST	*value;
{
	SETTINGS *v;
	
	/* Look for previous setting */

	for( v = head; v; v = v->next )
	    if( !strcmp( v->symbol, symbol ) )
		break;

	/* If previous set, reset.  If not, alloc a new. */

	if( v )
	{
	    list_free( v->value );
	    v->value = value;
	    v = head;
	} 
	else 
	{
	    v = (SETTINGS *)malloc( sizeof( *v ) );
	    v->symbol = newstr( symbol );
	    v->value = value;
	    v->next = head;
	}

	return v;
}

/*
 * pushsettings() - set all target specific variables
 */

void
pushsettings( v )
SETTINGS *v;
{
	for( ; v; v = v->next )
	    v->value = var_swap( v->symbol, v->value );
}

/*
 * popsettings() - reset target specific variables to their pre-push values
 */

void
popsettings( v )
SETTINGS *v;
{
	pushsettings( v );	/* just swap again */
}

/*
 * donerules() - free RULE and TARGET tables
 */

void
donerules()
{
	hashdone( rulehash );
	hashdone( targethash );
}
