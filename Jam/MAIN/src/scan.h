/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * scan.h - the jam yacc scanner
 */

/*
 * needed by parser, scanner
 */

# define YYSTYPE YYSYMBOL

typedef struct _YYSTYPE {
	int		type;
	char		*string;
	PARSE		*parse;
	LIST		*list;
	int		number;
} YYSTYPE;

extern YYSTYPE yylval;

extern int scan_asstring;
