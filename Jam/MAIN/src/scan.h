/*
 * Copyright 1993 Christopher Seiwald.
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
