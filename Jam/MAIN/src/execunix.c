/*
 * Copyright 1993 Christopher Seiwald.
 */

# ifndef VMS

# include "jam.h"
# include "execcmd.h"

# if defined(__sgi)
# define vfork() fork()
# endif

/*
 * execunix.c - execute a shell script on UNIX
 *
 * Sets "interrupted" if the command was interrupted.
 */

static int intr = 0;

void
onintr()
{
	intr++;
}
	
int
execcmd( string )
char *string;
{
	int status, pid, w, rstat;
	void (*istat)();

	intr = 0;

	if ((pid = vfork()) == 0) {
		execl("/bin/sh", "sh", "-c", string, 0);
		_exit(127);
	}

	istat = signal( SIGINT, onintr );
	while ((w = wait(&status)) != pid && w != -1)
		;
	signal( SIGINT, istat );

	if( intr )
	    return EXEC_CMD_INTR;
	else if( w == -1 || status != 0 )
	    return EXEC_CMD_FAIL;
	else
	    return EXEC_CMD_OK;
}

# endif /* UNIX */
