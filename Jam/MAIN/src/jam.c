/*
 * /+\
 * +\	Copyright 1993 Christopher Seiwald.
 * \+/
 *
 * Permission is granted to use this software and distribute it
 * freely, as long as this notice is retained and modifications are
 * clearly marked.
 *
 * The author assumes no liability for the consequences of using this
 * software.
 */

# include "jam.h"
# include "option.h"
# include "make.h"

/*
 * jam.c - make redux
 *
 * See jam(1) and Jambase(5) for usage information.
 *
 * The top half of the code is structured such:
 *
 *                       jam 
 *                      / | \
 *                 +---+  |  \
 *                /       |   \
 *         jamgram     option  \
 *        /  |   \              \
 *       /   |    \              \
 *      /    |     \             |
 *  scan     |     compile      make
 *           |    /    \       / |  \
 *           |   /      \     /  |   \
 *           |  /        \   /   |    \
 *         parse         rules  search execute
 *                               |
 *                               |
 *                               |
 *                           timestamp
 *
 *
 * The support routines are called by all of the above, but themselves
 * are layered thus:
 *
 *                     variable|expand
 *                      /  |   |   |
 *                     /   |   |   |
 *                    /    |   |   |
 *                 lists   |   |   filesys
 *                    \    |   |
 *                     \   |   |
 *                      \  |   |
 *                     newstr  |
 *                        \    |
 *                         \   |
 *                          \  |
 *                          hash
 *
 * Roughly, the modules are:
 *
 *	compile.c - compile parsed jam statements
 *	execunix.c - execute a shell script on UNIX
 *	execvms.c - execute a shell script, ala VMS
 *	expand.c - expand a buffer, given variable values
 *	fileunix.c - manipulate file names and scan directories on UNIX
 *	filevms.c - manipulate file names and scan directories on VMS
 *	hash.c - simple in-memory hashing routines 
 *	headers.c - handle #includes in source files
 *	lists.c - maintain lists of strings
 *	make.c - bring a target up to date, once rules are in place
 *	newstr.c - string manipulation routines
 *	option.c - command line option processing
 *	parse.c - make and destroy parse trees as driven by the parser
 *	regexp.c - Henry Spencer's regexp
 *	rules.c - access to RULEs, TARGETs, and ACTIONs
 *	scan.c - the jam yacc scanner
 *	search.c - find a target along $(SEARCH) or $(LOCATE) 
 *	timestamp.c - get the timestamp of a file or archive member
 *	variable.c - handle jam multi-element variables
 *	jamgram.yy - jam grammar
 */

struct globs globs = {
	1,			/* debug */
	0			/* noexec */
} ;

/* Symbols to be defined as true for use in Jambase */

static char *othersyms[] = { OTHERSYMS, 0 } ;
extern char **environ;

char *usage = 
	"jam [-n] [-f<Jambase>] [-d<debuglevel>] [-t<target>...] [target...]";

main( argc, argv )
char	**argv;
{
	int		n;
	char		*s;
	struct option	optv[N_OPTS];
	char		*ruleset = JAMBASE;
	char		*all = "all";

	argc--, argv++;

	if( ( n = getoptions( argc, argv, "d:f:t:n", optv ) ) < 0 )
	{
		printf( "usage: %s\n", usage );
		exit( 1 );
	}

	argc -= n, argv += n;

	/* Pick up interesting options */

	if( ( s = getoptval( optv, 'n', 0 ) ) )
	    globs.noexec++;

	if( ( s = getoptval( optv, 'd', 0 ) ) )
	    globs.debug = atoi( s );

	/* load up environment variables */

	var_defines( othersyms );
	var_defines( environ );

	/* Parse ruleset */

	for( n = 0; s = getoptval( optv, 'f', n ); n++ )
	{
	    yyfparse( s );
	    yyparse();
	}

	if( !n )
	{
	    yyfparse( ruleset );
	    yyparse();
	}

	/* Manually touch -t targets */

	for( n = 0; s = getoptval( optv, 't', n ); n++ )
	    touchtarget( s );

	/* Now make target */

	if( argc )
	    make( argc, argv );
	else
	    make( 1, &all );

	/* Widely scattered cleanup */

	var_done();
	donerules();
	donestamps();
	donestr();

	return EXITOK;
}
