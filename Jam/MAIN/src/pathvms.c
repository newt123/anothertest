/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

# ifdef VMS

/*
 * pathvms.c - manipulate file names on VMS
 *
 * External routines:
 *
 *	file_parse() - split a file name into dir/base/suffix/member
 *	file_build() - build a filename given dir/base/suffix/member
 *
 * File_parse() and file_build() just manipuate a string and a structure;
 * they do not make system calls.
 *
 * WARNING!  This file contains voodoo logic, as black magic is 
 * necessary for wrangling with VMS file name.  Woe be to people
 * who mess with this code.
 *
 * 02/09/95 (seiwald) - bungled R=[xxx] - was using directory length!
 * 05/03/96 (seiwald) - split from filevms.c
 */

# include "jam.h"
# include "filesys.h"

/*
 * file_parse() - split a file name into dir/base/suffix/member
 */

void
file_parse( file, f )
char		*file;
FILENAME	*f;
{
	char *p, *q;
	char *end;
	
	memset( (char *)f, 0, sizeof( *f ) );

	/* Look for <grist> */

	if( file[0] == '<' && ( p = strchr( file, '>' ) ) )
	{
	    f->f_grist.ptr = file + 1;
	    f->f_grist.len = p - file - 1;
	    file = p + 1;
	}

	/* Look for dev:[dir] or dev: */

	if( ( p = strchr( file, ']' ) ) || ( p = strchr( file, ':' ) ) )
	{
	    f->f_dir.ptr = file;
	    f->f_dir.len = p + 1 - file;
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
	/* This would be memrchr() */

	p = 0;
	q = file;

	while( q = memchr( q, '.', end - q ) )
	    p = q++;

	if( p )
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
 * file_flags() - find out what's in a directory name
 *
 * VMS directories get complicated.  Valid combinations of root
 * and dir are:
 *
 *	root		dir		result
 *	----		---		------
 *					
 *	 		[dir]		[dir]
 *	dev				dev:
 *	dev		[dir]		dev:[dir]
 *	dev:				dev:
 *	dev:		[dir]		dev:[dir]
 *	[dir]				[dir]
 *	[dir]		[dir]		[dir.dir]
 *	dev:[dir]			dev:[dir]
 *	dev:[dir]	[dir]		dev:[dir.dir]
 *
 *	*		dev		dev
 *	*		dev:		dev:
 *	*		dev:[dir]	dev:[dir]
 *
 */

# define HAS_NOTHING	0
# define HAS_DEV	0x01
# define HAS_DIR	0x02
# define HAS_COLON	0x04

static int
file_flags( buf, len )
char	*buf;
int	len;
{
	int flags = 0;

	if( len && *buf != '[' )
	    flags |= HAS_DEV;

	while( len-- )
	    switch( *buf++ )
	{
	case ':':	flags |= HAS_COLON; break;
	case '[':	flags |= HAS_DIR; break;
	}

	return flags;
}

/*
 * file_build() - build a filename given dir/base/suffix/member
 */

void
file_build( f, file )
FILENAME	*f;
char		*file;
{
	char *ofile = file;

	int dir_flags = HAS_DEV;
	int root_flags = 0;

	if( f->f_grist.len )
	{
	    *file++ = '<';
	    memcpy( file, f->f_grist.ptr, f->f_grist.len );
	    file += f->f_grist.len;
	    *file++ = '>';
	}

	if( f->f_root.len )
	{
	    root_flags = file_flags( f->f_root.ptr, f->f_root.len );
	    dir_flags = file_flags( f->f_dir.ptr, f->f_dir.len );
	}

	switch( dir_flags & 0x03 )
	{
	case HAS_DIR:
	case HAS_NOTHING:
	    switch( root_flags & 0x03 )
	    {
	    case HAS_NOTHING:
		break;

	    case HAS_DEV:
		memcpy( file, f->f_root.ptr, f->f_root.len );
		file += f->f_root.len;
		if( !( root_flags & HAS_COLON ) )
		    *file++ = ':';
		break;
		
	    case HAS_DIR:
	    case HAS_DEV|HAS_DIR:
		memcpy( file, f->f_root.ptr, f->f_root.len );
		file += f->f_root.len;
		break;
	    }

	    if( dir_flags & HAS_DIR )
	    {
		if( root_flags & HAS_DIR )
		{
		    file[-1] = '.';
		    memcpy( file, f->f_dir.ptr + 1, f->f_dir.len - 1 );
		    file += f->f_dir.len - 1;
		}
		else
		{
		    memcpy( file, f->f_dir.ptr, f->f_dir.len );
		    file += f->f_dir.len;
		}
	    }

	    break;

	case HAS_DEV:
	case HAS_DEV|HAS_DIR:
	    memcpy( file, f->f_dir.ptr, f->f_dir.len );
	    file += f->f_dir.len;
	    break;
	}

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
	else if( f->f_base.len )
	{
	    *file++ = '.';
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

# endif /* VMS */
