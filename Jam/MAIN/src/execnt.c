/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

# if defined( NT ) || defined( __OS2__ )

# include "jam.h"
# include "execcmd.h"
# include "lists.h"

/*
 * execunix.c - execute a shell script on UNIX
 *
 * 05/04/94 (seiwald) - async multiprocess interface; noop on NT
 */

static int intr = 0;

void
onintr( disp )
int disp;
{
	intr++;
	printf( "...interrupted\n" );
}
	
void
execcmd( string, func, closure, shell )
char *string;
void (*func)();
void *closure;
LIST *shell;
{
	int status, pid, w, rstat;
	void (*istat)();

	/* Execute each line separately for dame-brammaged DOS shell. */

	do
	{
	    /* Copy next line to buf. */

	    char buf[ MAXCMD ];
	    char *b = buf;

	    while( *string )
	    	if( ( *b++ = *string++ ) == '\n' )
		    break;

	    if( b == buf )
		break;

	    *b++ = '\0';

	    /* Execute line */

	    istat = signal( SIGINT, onintr );
	    status = system( buf );
	    signal( SIGINT, istat );

	    /* Divine status. */

	    if( intr )
		rstat = EXEC_CMD_INTR;
	    else if( w == -1 || status != 0 )
		rstat = EXEC_CMD_FAIL;
	    else
		rstat = EXEC_CMD_OK;

	} while( rstat == EXEC_CMD_OK );

	/* Signal completion. */

	(*func)( closure, rstat );
}

int 
execwait()
{
	return 0;
}

# endif /* NT */
