/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

# include "jam.h"
# include "execcmd.h"
# include "lists.h"
# include <errno.h>

# ifdef unix

# if defined(__sgi) || (defined (COHERENT) && defined (_I386))
# define vfork() fork()
# endif

/*
 * execunix.c - execute a shell script on UNIX
 *
 * If $(JAMSHELL) is defined, uses that to formulate execv().
 * The default is:
 *
 *	/bin/sh sh -c %
 *
 * The first word is the pathname of the executable, the subsequent
 * words are the argv[].  % expands to the command string and ! 
 * expands to the slot number for multiprocess (-j) invocations.
 *
 * The words are not part of a single string, but rather individual 
 * elements in a jam variable value.
 *
 * Don't just set JAMSHELL to /bin/sh - it won't work!
 *
 * External routines:
 *	execcmd() - launch an async command execution
 * 	execwait() - wait and drive at most one execution completion
 *
 * Internal routines:
 *	onintr() - bump intr to note command interruption
 *
 * 04/08/94 (seiwald) - Coherent/386 support added.
 * 05/04/94 (seiwald) - async multiprocess interface
 * 01/22/95 (seiwald) - $(JAMSHELL) support
 */

static int intr = 0;

static int cmdsrunning = 0;

static void (*istat)();

static struct
{
	int	pid;
	void	(*func)();
	void 	*closure;
} cmdtab[ MAXJOBS ] = {0};

/*
 * onintr() - bump intr to note command interruption
 */

void
onintr()
{
	intr++;
	printf( "...interrupted\n" );
}

/*
 * execcmd() - launch an async command execution
 */

void
execcmd( string, func, closure, shell )
char *string;
void (*func)();
void *closure;
LIST *shell;
{
	int pid;
	int slot;
	char *argv[ MAXARGC + 1 ];	/* +1 for NULL */

	/* Find a slot in the running commands table for this one. */

	for( slot = 0; slot < MAXJOBS; slot++ )
	    if( !cmdtab[ slot ].pid )
		break;

	if( slot == MAXJOBS )
	{
	    printf( "no slots for child!\n" );
	    exit( 1 );
	}

	/* Forumulate argv */
	/* If shell was defined, be prepared for % and ! subs. */
	/* Otherwise, use stock /bin/sh. */

	if( shell )
	{
	    int i;
	    char jobno[4];
	    int ok = 0;

	    sprintf( jobno, "%d", slot );

	    for( i = 0; shell && i < MAXARGC; i++, shell = list_next( shell ) )
	    {
		switch( shell->string[0] )
		{
		case '%':	argv[i] = string; ok++; break;
		case '!':	argv[i] = jobno; break;
		default:	argv[i] = shell->string;
		}
		if( DEBUG_EXECCMD )
		    printf( "argv[%d] = '%s'\n", i, argv[i] );
	    }

	    argv[i] = 0;

	    if( !ok || i <= 1 )
	    {
		printf( "bungled JAMSHELL value!\n" );
		exit( 1 );
	    }
	}
	else
	{
	    argv[0] = "/bin/sh";
	    argv[1] = "sh";		/* argv[1] is base for execv */
	    argv[2] = "-c";
	    argv[3] = string;
	    argv[4] = 0;
	}

	/* Catch interrupts whenever commands are running. */

	if( !cmdsrunning++ )
	    istat = signal( SIGINT, onintr );

	/* Start the command */

	if ((pid = vfork()) == 0) 
   	{
		execv( argv[0], argv + 1 );
		_exit(127);
	}

	if( pid == -1 )
	{
	    perror( "vfork" );
	    exit( -1 );
	}

	/* Save the operation for execwait() to find. */

	cmdtab[ slot ].pid = pid;
	cmdtab[ slot ].func = func;
	cmdtab[ slot ].closure = closure;

	/* Wait until we're under the limit of concurrent commands. */
	/* Don't trust globs.jobs alone. */

	while( cmdsrunning >= MAXJOBS || cmdsrunning >= globs.jobs )
	    if( !execwait() )
		break;
}

/*
 * execwait() - wait and drive at most one execution completion
 */

int
execwait()
{
	int i;
	int status, w;
	int rstat;

	/* Handle naive make1() which doesn't know if cmds are running. */

	if( !cmdsrunning )
	    return 0;

	/* Pick up process pid and status */
    
	while( ( w = wait( &status ) ) == -1 && errno == EINTR )
		;

	if( w == -1 )
	{
	    printf( "child process(es) lost!\n" );
	    perror("wait");
	    exit( -1 );
	}

	/* Find the process in the cmdtab. */

	for( i = 0; i < MAXJOBS; i++ )
	    if( w == cmdtab[ i ].pid )
		break;

	if( i == MAXJOBS )
	{
	    printf( "waif child found!\n" );
	    exit( -1 );
	}

	/* Drive the completion */

	if( !--cmdsrunning )
	    signal( SIGINT, istat );

	if( intr )
	    rstat = EXEC_CMD_INTR;
	else if( w == -1 || status != 0 )
	    rstat = EXEC_CMD_FAIL;
	else
	    rstat = EXEC_CMD_OK;

	cmdtab[ i ].pid = 0;

	(*cmdtab[ i ].func)( cmdtab[ i ].closure, rstat );

	return 1;
}

# endif /* unix */
