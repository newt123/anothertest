/* 
 * Copyright 1993 Christopher Seiwald.
 */

# ifdef VMS

# include "jam.h"
# include "execcmd.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iodef.h>
#include <ssdef.h>
#include <descrip.h>
#include <dvidef.h>
#include <clidef.h>

/*
 * execvms.c - execute a shell script, ala VMS
 */

#define WRTLEN 240

#define MIN( a, b )	((a) < (b) ? (a) : (b))

    /* macros to allocate and initialize VMS descriptors
     */
#define DESCALLOC( name ) struct dsc$descriptor_s \
	(name) = { 0, DSC$K_DTYPE_T, DSC$K_CLASS_D, NULL }


int
execcmd( string )
char *string;
{
    /* Split string at newlines, and don't execute empty lines */
    /* Bail if any lines fail. */

    while( *string )
    {
	char *s;
	char *os = string;
	int something = 0;

	for( s = string; *s && *s != '\n'; s++ )
	    if( !isspace( *s ) )
		something++;

	string = *s ? s + 1 : s ;

	if( something )
	{
	    int status;
	    int len;

	    *s = '\0';

	    if( ( len = strlen( os ) ) < WRTLEN )
	    {
		status = system( os ) & 0x07;
	    }
	    else
	    {
		FILE *f = fopen( "sys$scratch:jam.com", "w" );

		if( !f )
		{
		    printf( "can't open command file\n" );
		    return EXEC_CMD_FAIL;
		}

	        fputc( '$', f );

		while( len > 0 )
		{
		    int l = MIN( len, WRTLEN );

		    fwrite( os, l, 1, f );

		    if( l < len )
			fputc( '-', f );

		    fputc( '\n', f );

		    len -= l;
		    os += l;
		}

		fclose( f );

		status = system( "@sys$scratch:jam.com" ) & 0x07;

		unlink( "sys$scratch:jam.com" );

	    }		

	    /* Fail for error or fatal error */
	    /* OK on OK, warning, or info exit */

	    if( status == 2 || status == 4 )
		return EXEC_CMD_FAIL;
	}
    }

    return EXEC_CMD_OK;
}

# endif /* VMS */
