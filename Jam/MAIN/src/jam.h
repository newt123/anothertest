/*
 * Copyright 1993 Christopher Seiwald.
 */

/*
 * jam.h - includes and globals for jam
 */

# ifdef VMS

# ifdef __ALPHA

# include <types.h>
# include <file.h>
# include <stat.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <time.h>

# define OTHERSYMS "VMS=true","OS=OPENVMS"

# else

# include <types.h>
# include <file.h>
# include <stat.h>
# include <stdio.h>
# include <ctype.h>
# include <signal.h>
# include <string.h>
# include <time.h>

# define OTHERSYMS "VMS=true","OS=VMS"

# endif 

# define MAXCMD	1023 /* longest command */
# define JAMBASE "Jambase.VMS"
# define EXITOK 1

# else

# include <sys/types.h>
# include <sys/file.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef ultrix
# include <stdlib.h>
# endif
# include <stdio.h>
# include <ctype.h>
# ifndef __bsdi__
# include <malloc.h>
# endif
# include <memory.h>
# include <signal.h>
# include <string.h>
# include <time.h>

# ifdef AIX
# define OTHERSYMS "UNIX=true","OS=AIX"
# endif
# ifdef __bsdi__
# define OTHERSYMS "UNIX=true","OS=BSDI"
# endif
# ifdef __DGUX
# define OTHERSYMS "UNIX=true","OS=DGUX"
# endif
# ifdef __hpux
# define OTHERSYMS "UNIX=true","OS=HPUX"
# endif
# ifdef __osf__
# define OTHERSYMS "UNIX=true","OS=OSF"
# endif
# ifdef _SEQUENT_
# define OTHERSYMS "UNIX=true","OS=PTX"
# endif
# ifdef __sgi
# define OTHERSYMS "UNIX=true","OS=IRIX"
# endif
# ifdef sun
# define OTHERSYMS "UNIX=true","OS=SUNOS"
# endif
# ifdef solaris
# undef OTHERSYMS
# define OTHERSYMS "UNIX=true","OS=SOLARIS"
# endif
# ifdef ultrix
# define OTHERSYMS "UNIX=true","OS=ULTRIX"
# endif
# ifndef OTHERSYMS
# define OTHERSYMS "UNIX=true"
# endif

# define JAMBASE "/usr/local/lib/jam/Jambase"
# define MAXCMD	10240	/* longest command */
# define EXITOK 0

# endif /* UNIX */

/* You probably don't need to much with these. */

# define MAXSYM	1024	/* longest symbol in the environment */
# define MAXARG 1024	/* longest single word on a line */
# define MAXPATH 1024	/* longest filename */

/* Jam private definitions below. */

struct globs {
	int	debug;
	int	noexec;
} ;

extern struct globs globs;

# define DEBUG_MAKE	( globs.debug >= 1 )	/* show actions when executed */
# define DEBUG_MAKEQ	( globs.debug >= 2 )	/* show even quiet actions */
# define DEBUG_EXEC	( globs.debug >= 2 )	/* show text of actons */
# define DEBUG_MAKEPROG	( globs.debug >= 3 )	/* show progress of make0 */

# define DEBUG_BIND	( globs.debug >= 4 )	/* show when files bound */
# define DEBUG_COMPILE	( globs.debug >= 5 )	/* show rule invocations */
# define DEBUG_MEM	( globs.debug >= 5 )	/* show memory use */
# define DEBUG_HEADER	( globs.debug >= 6 )	/* show result of header scan */
# define DEBUG_BINDSCAN	( globs.debug >= 6 )	/* show result of dir scan */
# define DEBUG_SEARCH	( globs.debug >= 6 )	/* show attempts at binding */

# define DEBUG_IF	( globs.debug >= 7 )	/* show 'if' calculations */
# define DEBUG_VARSET	( globs.debug >= 7 )	/* show variable settings */
# define DEBUG_VARGET	( globs.debug >= 8 )	/* show variable fetches */
# define DEBUG_VAREXP	( globs.debug >= 8 )	/* show variable expansions */
# define DEBUG_LISTS	( globs.debug >= 9 )	/* show list manipulation */
# define DEBUG_SCAN	( globs.debug >= 9 )	/* show scanner tokens */

