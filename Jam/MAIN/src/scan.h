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

int yyerror();
int yyfparse();
int yylex();
void yymode();	/* adjust lexicon of scanner */
int yyparse();

# define SCAN_NORMAL	0	/* normal parsing */
# define SCAN_STRING	1	/* look only for matching } */
# define SCAN_PUNCT	2	/* only punctuation keywords */
