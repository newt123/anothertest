/*
 * Copyright 1993 Christopher Seiwald.
 */

/*
 * option.h - command line option processing
 *
 * {o >o
 *  \ -) "Command line option."
 */

typedef struct option
{
	char	flag;		/* filled in by getoption() */
	char	*val;		/* set to random address if true */
} option;

# define N_OPTS 10

int 	getoptions( /* int argc, char **argv, char *opts, option *optv */ );
char 	*getoptval( /* option *optv, char opt, int subopt */ );
