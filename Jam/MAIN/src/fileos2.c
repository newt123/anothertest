/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

# include "jam.h"
# include "filesys.h"

# ifdef __OS2__

# include <io.h>
# include <dos.h>

/*
 * fileos2.c - scan directories and archives on NT
 *
 * External routines:
 *
 *	file_dirscan() - scan a directory for files
 *	file_time() - get timestamp of file, if not done by file_dirscan()
 *	file_archscan() - scan an archive for files
 *
 * File_dirscan() and file_archscan() call back a caller provided function
 * for each file found.  A flag to this callback function lets file_dirscan()
 * and file_archscan() indicate that a timestamp is being provided with the
 * file.   If file_dirscan() or file_archscan() do not provide the file's
 * timestamp, interested parties may later call file_time().
 *
 * 07/10/95 (taylor)  Findfirst() returns the first file on NT.
 * 05/03/96 (seiwald) split apart into pathnt.c
 */

/*
 * file_dirscan() - scan a directory for files
 */

void
file_dirscan( dir, func )
char	*dir;
void	(*func)();
{
	FILENAME f;
	char filespec[ MAXJPATH ];
	char filename[ MAXJPATH ];
	long handle;
	int ret;
	struct _find_t finfo[1];

	/* First enter directory itself */

	memset( (char *)&f, '\0', sizeof( f ) );

	f.f_dir.ptr = dir;
	f.f_dir.len = strlen(dir);

	dir = *dir ? dir : ".";

 	/* Special case \ : enter it */
 
 	if( f.f_dir.len == 1 && f.f_dir.ptr[0] == '\\' )
 	    (*func)( dir, 0 /* not stat()'ed */, (time_t)0 );

	/* Now enter contents of directory */

	sprintf( filespec, "%s/*", dir );

	if( DEBUG_BINDSCAN )
	    printf( "scan directory %s\n", dir );

	/* Time info in dos find_t is not very useful.  It consists */
	/* of a separate date and time, and putting them together is */
	/* not easy.  So we leave that to a later stat() call. */

	if( !_dos_findfirst( filespec, _A_NORMAL|_A_RDONLY|_A_SUBDIR, finfo ) )
	{
	    do
	    {
		f.f_base.ptr = finfo->name;
		f.f_base.len = strlen( finfo->name );

		file_build( &f, filename, 0 );

		(*func)( filename, 0 /* not stat()'ed */, (time_t)0 );
	    }
	    while( !_dos_findnext( finfo ) );
	}

}

/*
 * file_time() - get timestamp of file, if not done by file_dirscan()
 */

int
file_time( filename, time )
char	*filename;
time_t	*time;
{
	/* This is called on OS2, not NT.  */
	/* NT fills in the time in the dirscan. */

	struct stat statbuf;

	if( stat( filename, &statbuf ) < 0 )
	    return -1;

	*time = statbuf.st_mtime;

	return 0;
}

void
file_archscan( archive, func )
char *archive;
void (*func)();
{
}

# endif /* OS2 */

