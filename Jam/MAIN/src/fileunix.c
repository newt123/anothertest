/*
 * Copyright 1993 Christopher Seiwald.
 */

# ifndef VMS

# include "jam.h"
# include "filesys.h"

# if defined(_SEQUENT_) || defined(__DGUX__)
# define PORTAR 1
# endif

# include <dirent.h>
# include <ar.h>

/*
 * fileunix.c - manipulate file names and scan directories on UNIX
 *
 * External routines:
 *
 *	file_parse() - split a file name into dir/base/suffix/member
 *	file_build() - build a filename given dir/base/suffix/member
 *	file_dirscan() - scan a directory for files
 *	file_time() - get timestamp of file, if not done by file_dirscan()
 *	file_archscan() - scan an archive for files
 *
 * File_parse() and file_build() just manipuate a string and a structure;
 * they do not make system calls.
 *
 * File_dirscan() and file_archscan() call back a caller provided function
 * for each file found.  A flag to this callback function lets file_dirscan()
 * and file_archscan() indicate that a timestamp is being provided with the
 * file.   If file_dirscan() or file_archscan() do not provide the file's
 * timestamp, interested parties may later call file_time().
 */

/*
 * file_parse() - split a file name into dir/base/suffix/member
 */

void
file_parse( file, f )
char		*file;
FILENAME	*f;
{
	char *p; 
	char *end;
	
	memset( (char *)f, 0, sizeof( *f ) );

	/* Look for <grist> */

	if( file[0] == '<' && ( p = strchr( file, '>' ) ) )
	{
	    f->f_grist.ptr = file + 1;
	    f->f_grist.len = p - file - 1;
	    file = p + 1;
	}

	/* Look for dir/ */

	if( p = strrchr( file, '/' ) )
	{
	    f->f_dir.ptr = file;
	    f->f_dir.len = p - file;
	    file = p + 1;
	}

	end = file + strlen( file );

	/* Look for (member) */

	if( ( p = strchr( file, '(' ) ) && end[-1] == ')' )
	{
	    f->f_member.ptr = p + 1;
	    f->f_member.len = end - p - 2;
	    end = p;
	} 

	/* Look for .suffix */

	if( ( p = strchr( file, '.' ) ) && p < end )
	{
	    f->f_suffix.ptr = p;
	    f->f_suffix.len = end - p;
	    end = p;
	}

	/* Leaves base */

	f->f_base.ptr = file;
	f->f_base.len = end - file;
}

/*
 * file_build() - build a filename given dir/base/suffix/member
 */

void
file_build( f, file )
FILENAME	*f;
char		*file;
{
	if( f->f_grist.len )
	{
	    *file++ = '<';
	    memcpy( file, f->f_grist.ptr, f->f_grist.len );
	    file += f->f_grist.len;
	    *file++ = '>';
	}

	/* Don't prepend root if it's . or directory is rooted */

	if( f->f_root.len 
	    && !( f->f_root.len == 1 && f->f_root.ptr[0] == '.' )
	    && !( f->f_dir.len && f->f_dir.ptr[0] == '/' ) )
	{
	    memcpy( file, f->f_root.ptr, f->f_root.len );
	    file += f->f_root.len;
	    *file++ = '/';
	}
	    
	if( f->f_dir.len )
	{
	    memcpy( file, f->f_dir.ptr, f->f_dir.len );
	    file += f->f_dir.len;
	}

	if( f->f_dir.len && f->f_base.len )
	    *file++ = '/';

	if( f->f_base.len )
	{
	    memcpy( file, f->f_base.ptr, f->f_base.len );
	    file += f->f_base.len;
	}

	if( f->f_suffix.len )
	{
	    memcpy( file, f->f_suffix.ptr, f->f_suffix.len );
	    file += f->f_suffix.len;
	}

	if( f->f_member.len )
	{
	    *file++ = '(';
	    memcpy( file, f->f_member.ptr, f->f_member.len );
	    file += f->f_member.len;
	    *file++ = ')';
	}
	*file = 0;
}

/*
 * file_dirscan() - scan a directory for files
 */

void
file_dirscan( dir, func )
char	*dir;
void	(*func)();
{
	FILENAME f;
	DIR *d;
	struct dirent *dirent;
	char filename[ MAXPATH ];
	struct stat statbuf;

	/* First enter directory itself */

	memset( (char *)&f, '\0', sizeof( f ) );

	f.f_dir.ptr = dir;
	f.f_dir.len = strlen(dir);

	dir = *dir ? dir : ".";

	/* Now enter contents of directory */

	if( !( d = opendir( dir ) ) )
	    return;

	if( DEBUG_BINDSCAN )
	    printf( "scan directory %s\n", dir );

	while( dirent = readdir( d ) )
	{
	    f.f_base.ptr = dirent->d_name;
	    f.f_base.len = strlen( dirent->d_name );

	    file_build( &f, filename );

	    (*func)( filename, 0 /* not stat()'ed */, (time_t)0 );
	}

	closedir( d );
}

/*
 * file_time() - get timestamp of file, if not done by file_dirscan()
 */

int
file_time( filename, time )
char	*filename;
time_t	*time;
{
	struct stat statbuf;

	if( stat( filename, &statbuf ) < 0 )
	    return -1;

	*time = statbuf.st_mtime;
	return 0;
}

/*
 * file_archscan() - scan an archive for files
 */

# ifndef AIAMAG	/* God-fearing UNIX */

# define SARFMAG 2
# define SARHDR sizeof( struct ar_hdr )

void
file_archscan( archive, func )
char *archive;
void (*func)();
{
	struct ar_hdr ar_hdr;
	char buf[ MAXPATH ];
	long offset;
	int fd;

	if( ( fd = open( archive, O_RDONLY, 0 ) ) < 0 )
	    return;

	if( read( fd, buf, SARMAG ) != SARMAG ||
	    strncmp( ARMAG, buf, SARMAG ) )
	{
	    close( fd );
	    return;
	}

	offset = SARMAG;

	if( DEBUG_BINDSCAN )
	    printf( "scan archive %s\n", archive );

	while( read( fd, &ar_hdr, SARHDR ) == SARHDR &&
	       !memcmp( ar_hdr.ar_fmag, ARFMAG, SARFMAG ) )
	{
	    char    lar_name[16];
	    long    lar_date;
	    long    lar_size;
	    char *c;

	    strncpy( lar_name, ar_hdr.ar_name, sizeof(ar_hdr.ar_name) );
	    c = lar_name + sizeof( lar_name );
	    while( *--c == ' ' || *c == '/' )
		    ;
	    *++c = '\0';

	    sscanf( ar_hdr.ar_date, "%ld", &lar_date );
	    sscanf( ar_hdr.ar_size, "%ld", &lar_size );

	    sprintf( buf, "%s(%s)", archive, lar_name );

	    (*func)( buf, 1 /* time valid */, (time_t)lar_date );

	    offset += SARHDR + ( ( lar_size + 1 ) & ~1 );
	    lseek( fd, offset, 0 );
	}

	close( fd );
}

# else /* AIAMAG - RS6000 AIX */

void
file_archscan( archive, func )
char *archive;
void (*func)();
{
	struct fl_hdr fl_hdr;

	struct {
		struct ar_hdr hdr;
		char pad[ 256 ];
	} ar_hdr ;

	char buf[ MAXPATH ];
	long offset;
	int fd;

	if( ( fd = open( archive, O_RDONLY, 0 ) ) < 0 )
	    return;

	if( read( fd, (char *)&fl_hdr, FL_HSZ ) != FL_HSZ ||
	    strncmp( AIAMAG, fl_hdr.fl_magic, SAIAMAG ) )
	{
	    close( fd );
	    return;
	}

	sscanf( fl_hdr.fl_fstmoff, "%ld", &offset );

	if( DEBUG_BINDSCAN )
	    printf( "scan archive %s\n", archive );

	while( offset > 0 &&
	       lseek( fd, offset, 0 ) >= 0 &&
	       read( fd, &ar_hdr, sizeof( ar_hdr ) ) >= sizeof( ar_hdr.hdr ) )
	{
	    long    lar_date;
	    int	    lar_namlen;

	    sscanf( ar_hdr.hdr.ar_namlen, "%d", &lar_namlen );
	    sscanf( ar_hdr.hdr.ar_date, "%ld", &lar_date );
	    sscanf( ar_hdr.hdr.ar_nxtmem, "%ld", &offset );

	    if( !lar_namlen )
		continue;

	    ar_hdr.hdr._ar_name.ar_name[ lar_namlen ] = '\0';

	    sprintf( buf, "%s(%s)", archive, ar_hdr.hdr._ar_name.ar_name );

	    (*func)( buf, 1 /* time valid */, (time_t)lar_date );
	}

	close( fd );
}

# endif /* AIAMAG - RS6000 AIX */

# endif /* UNIX */
