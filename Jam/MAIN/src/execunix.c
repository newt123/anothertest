/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

# include "jam.h"
# include "execcmd.h"
# include <errno.h>

# ifdef unix

# if defined(__sgi) || (defined (COHERENT) && defined (_I386))
# define vfork() fork()
# endif

/*
 * execunix.c - execute a shell script on UNIX
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
 */

# define PMAX 64

static int intr = 0;

static int cmdsrunning = 0;

static void (*istat)();

static struct
{
	int	pid;
	void	(*func)();
	void 	*closure;
} cmdtab[ PMAX ];

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
execcmd( string, func, closure  )
char *string;
void (*func)();
void *closure;
{
	int i;
	int pid;

	/* Find a slot in the running commands table for this one. */

	for( i = 0; i < PMAX; i++ )
	    if( !cmdtab[ i ].pid )
		break;

	if( i == PMAX )
	{
	    printf( "no slots for child!\n" );
	    exit( 1 );
	}

	/* Catch interrupts whenever commands are running. */

	if( !cmdsrunning++ )
	    istat = signal( SIGINT, onintr );

	/* Start the command */

	if ((pid = vfork()) == 0) {
		execl("/bin/sh", "sh", "-c", string, 0);
		_exit(127);
	}

	if( pid == -1 )
	{
	    perror( "vfork" );
	    exit( -1 );
	}

	/* Save the operation for execwait() to find. */

	cmdtab[ i ].pid = pid;
	cmdtab[ i ].func = func;
	cmdtab[ i ].closure = closure;

	/* Wait until we're under the limit of concurrent commands. */
	/* Don't trust globs.jobs alone. */

	while( cmdsrunning >= PMAX || cmdsrunning >= globs.jobs )
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

	for( i = 0; i < PMAX; i++ )
	    if( w == cmdtab[ i ].pid )
		break;

	if( i == PMAX )
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
