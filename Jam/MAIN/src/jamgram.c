# define _BANG 257
# define _BANG_EQUALS 258
# define _AMPERAMPER 259
# define _LPAREN 260
# define _RPAREN 261
# define _PLUS_EQUALS 262
# define _COLON 263
# define _SEMIC 264
# define _LANGLE 265
# define _LANGLE_EQUALS 266
# define _EQUALS 267
# define _RANGLE 268
# define _RANGLE_EQUALS 269
# define _QUESTION_EQUALS 270
# define ACTIONS 271
# define CASE 272
# define DEFAULT 273
# define ELSE 274
# define EXISTING 275
# define FOR 276
# define IF 277
# define IGNORE 278
# define IN 279
# define INCLUDE 280
# define LOCAL 281
# define ON 282
# define PIECEMEAL 283
# define QUIETLY 284
# define RULE 285
# define SWITCH 286
# define TOGETHER 287
# define UPDATED 288
# define _LBRACE 289
# define _BARBAR 290
# define _RBRACE 291
# define ARG 292
# define STRING 293

# line 63 "jamgram.y"
#include "jam.h"

#include "lists.h"
#include "parse.h"
#include "scan.h"
#include "compile.h"
#include "newstr.h"

# define F0 (void (*)())0
# define P0 (PARSE *)0
# define S0 (char *)0

# define pset( l,r,a ) 	  parse_make( compile_set,P0,P0,S0,S0,l,r,a )
# define pset1( l,p,a )	  parse_make( compile_settings,p,P0,S0,S0,l,L0,a )
# define pstng( p,l,r,a ) pset1( p, parse_make( F0,P0,P0,S0,S0,l,r,0 ), a )
# define prule( s,p )     parse_make( compile_rule,p,P0,s,S0,L0,L0,0 )
# define prules( l,r )	  parse_make( compile_rules,l,r,S0,S0,L0,L0,0 )
# define pfor( s,p,l )    parse_make( compile_foreach,p,P0,s,S0,l,L0,0 )
# define psetc( s,p )     parse_make( compile_setcomp,p,P0,s,S0,L0,L0,0 )
# define psete( s,s1,f )  parse_make( compile_setexec,P0,P0,s,s1,L0,L0,f )
# define pincl( l )       parse_make( compile_include,P0,P0,S0,S0,l,L0,0 )
# define pswitch( l,p )   parse_make( compile_switch,p,P0,S0,S0,l,L0,0 )
# define plocal( l,p )	  parse_make( compile_local,p,P0,S0,S0,l,L0,0 );
# define pcases( l,r )    parse_make( F0,l,r,S0,S0,L0,L0,0 )
# define pcase( s,p )     parse_make( F0,p,P0,s,S0,L0,L0,0 )
# define pif( l,r )	  parse_make( compile_if,l,r,S0,S0,L0,L0,0 )
# define pthen( l,r )	  parse_make( F0,l,r,S0,S0,L0,L0,0 )
# define pcond( c,l,r )	  parse_make( F0,l,r,S0,S0,L0,L0,c )
# define pcomp( c,l,r )	  parse_make( F0,P0,P0,S0,S0,l,r,c )
# define plol( p,l )	  parse_make( F0,p,P0,S0,S0,l,L0,0 )


#ifdef __STDC__
#include <stdlib.h>
#include <string.h>
#else
#include <malloc.h>
#include <memory.h>
#endif

#ifdef __cplusplus

#ifndef yyerror
	void yyerror(const char *);
#endif

#ifndef yylex
#ifdef __EXTERN_C__
	extern "C" { int yylex(void); }
#else
	int yylex(void);
#endif
#endif
	int yyparse(void);

#endif
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern int yyerrflag;
#ifndef YYSTYPE
#define YYSTYPE int
#endif
YYSTYPE yylval;
YYSTYPE yyval;
typedef int yytabelem;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#if YYMAXDEPTH > 0
int yy_yys[YYMAXDEPTH], *yys = yy_yys;
YYSTYPE yy_yyv[YYMAXDEPTH], *yyv = yy_yyv;
#else	/* user does initial allocation */
int *yys;
YYSTYPE *yyv;
#endif
static int yymaxdepth = YYMAXDEPTH;
# define YYERRCODE 256
yytabelem yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
-1, 4,
	263, 41,
	264, 41,
	292, 41,
	-2, 43,
	};
# define YYNPROD 52
# define YYLAST 167
yytabelem yyact[]={

    10,    26,    95,    93,    27,     6,     8,    28,    44,     3,
    85,    44,    35,    29,     9,     7,    63,    22,    11,    60,
    33,     4,   101,    94,    62,    61,    91,    64,    59,    58,
    41,    90,    42,    56,   100,    20,    28,    74,    40,    45,
    19,    43,    45,    21,    97,    20,    18,    31,    89,    47,
    19,    87,    68,    21,    36,    17,    48,    49,    46,    50,
    51,    34,    99,    37,    44,    65,    32,     2,    72,    15,
    52,     5,    16,    12,    57,    14,    13,    23,    73,    86,
    25,    24,    30,     1,     0,     0,    38,    39,     0,     0,
     0,    75,     0,     0,     0,    55,     0,     0,    25,    25,
     0,     0,     0,    66,     0,     0,     0,     0,    53,    54,
    70,    71,    69,    67,     0,     0,    25,    25,    78,    79,
    80,    81,    82,    83,    84,     0,    76,    77,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    98,    88,
     0,     0,    92,     0,     0,     0,     0,   102,     0,     0,
     0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   103 };
yytabelem yypact[]={

-10000000,  -271,-10000000,-10000000,-10000000,  -227,  -275,-10000000,  -256,  -279,
-10000000,  -261,  -203,  -280,  -210,  -200,-10000000,-10000000,  -229,-10000000,
-10000000,-10000000,  -249,  -257,  -248,  -209,  -256,  -256,-10000000,  -271,
  -259,  -264,  -271,-10000000,-10000000,-10000000,-10000000,-10000000,  -212,  -217,
-10000000,-10000000,  -235,  -261,  -256,  -256,  -285,  -285,  -285,  -285,
  -285,  -285,  -285,-10000000,  -251,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,  -213,-10000000,-10000000,-10000000,
  -216,  -258,  -265,  -235,  -289,  -268,-10000000,  -195,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,  -291,-10000000,  -220,-10000000,
  -261,-10000000,-10000000,  -201,  -240,-10000000,  -271,-10000000,  -269,  -261,
  -271,-10000000,-10000000,-10000000 };
yytabelem yypgo[]={

     0,    83,    65,    47,    66,    69,    75,    71,    72,    68,
    81,    82,    79,    78,    76,    74 };
yytabelem yyr1[]={

     0,     1,     1,     3,     3,     4,     4,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    12,     2,     2,
     8,     8,     8,    10,    10,    10,    10,    10,    10,    10,
    10,    10,    10,    10,    10,     9,     9,    13,     6,     6,
     5,    14,    14,     7,    11,    11,    15,    15,    15,    15,
    15,    15 };
yytabelem yyr2[]={

     0,     1,     5,     3,     9,     1,     5,     7,     7,     9,
    13,    11,    15,    11,    11,    15,     7,     1,    11,     7,
     3,     3,     3,     3,     7,     7,     7,     7,     7,     7,
     7,     5,     7,     7,     7,     1,     5,     9,     3,     7,
     3,     1,     5,     3,     1,     5,     3,     3,     3,     3,
     3,     3 };
yytabelem yychk[]={

-10000000,    -1,    -2,   280,   292,    -7,   276,   286,   277,   285,
   271,   289,    -5,   -14,    -6,    -5,    -8,   282,   273,   267,
   262,   270,   292,    -5,   -10,    -7,   257,   260,   292,   292,
   -11,    -3,    -4,   281,   264,   292,   264,   263,    -5,    -5,
   267,   279,   289,   289,   259,   290,   267,   258,   265,   266,
   268,   269,   279,   -10,   -10,    -2,   292,   -15,   288,   287,
   278,   284,   283,   275,   291,    -2,    -5,    -6,   264,    -8,
    -5,    -5,    -9,   -13,   272,    -3,   -10,   -10,    -7,    -7,
    -7,    -7,    -7,    -7,    -7,   261,   -12,   264,    -5,   264,
   289,   291,    -9,   292,   291,   293,    -4,   264,    -3,   263,
   274,   291,    -3,    -2 };
yytabelem yydef[]={

     1,    -2,     2,    41,    -2,     0,     0,    41,     0,     0,
    44,     5,     0,    40,     0,    38,    41,    41,     0,    20,
    21,    22,     0,     0,     0,    23,     0,     0,    43,     0,
     0,     0,     3,    41,     7,    42,     8,    41,     0,     0,
    41,    41,    35,     5,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    31,     0,    16,    17,    45,    46,    47,
    48,    49,    50,    51,    19,     6,     0,    39,     9,    41,
     0,     0,     0,    35,     0,     0,    32,    33,    24,    25,
    26,    27,    28,    29,    30,    34,     0,     5,     0,    11,
     5,    13,    36,     0,    14,    18,     4,    10,     0,     5,
     0,    12,    37,    15 };
typedef struct
#ifdef __cplusplus
	yytoktype
#endif
{ char *t_name; int t_val; } yytoktype;
#ifndef YYDEBUG
#	define YYDEBUG	0	/* don't allow debugging */
#endif

#if YYDEBUG

yytoktype yytoks[] =
{
	"_BANG",	257,
	"_BANG_EQUALS",	258,
	"_AMPERAMPER",	259,
	"_LPAREN",	260,
	"_RPAREN",	261,
	"_PLUS_EQUALS",	262,
	"_COLON",	263,
	"_SEMIC",	264,
	"_LANGLE",	265,
	"_LANGLE_EQUALS",	266,
	"_EQUALS",	267,
	"_RANGLE",	268,
	"_RANGLE_EQUALS",	269,
	"_QUESTION_EQUALS",	270,
	"ACTIONS",	271,
	"CASE",	272,
	"DEFAULT",	273,
	"ELSE",	274,
	"EXISTING",	275,
	"FOR",	276,
	"IF",	277,
	"IGNORE",	278,
	"IN",	279,
	"INCLUDE",	280,
	"LOCAL",	281,
	"ON",	282,
	"PIECEMEAL",	283,
	"QUIETLY",	284,
	"RULE",	285,
	"SWITCH",	286,
	"TOGETHER",	287,
	"UPDATED",	288,
	"_LBRACE",	289,
	"_BARBAR",	290,
	"_RBRACE",	291,
	"ARG",	292,
	"STRING",	293,
	"-unknown-",	-1	/* ends search */
};

char * yyreds[] =
{
	"-no such reduction-",
	"stmts : /* empty */",
	"stmts : stmts rule",
	"rules : rule0",
	"rules : LOCAL args _SEMIC rule0",
	"rule0 : /* empty */",
	"rule0 : rule0 rule",
	"rule : INCLUDE args _SEMIC",
	"rule : ARG lol _SEMIC",
	"rule : arg1 assign args _SEMIC",
	"rule : arg1 ON args assign args _SEMIC",
	"rule : arg1 DEFAULT _EQUALS args _SEMIC",
	"rule : FOR ARG IN args _LBRACE rules _RBRACE",
	"rule : SWITCH args _LBRACE cases _RBRACE",
	"rule : IF cond _LBRACE rules _RBRACE",
	"rule : IF cond _LBRACE rules _RBRACE ELSE rule",
	"rule : RULE ARG rule",
	"rule : ACTIONS eflags ARG",
	"rule : ACTIONS eflags ARG STRING",
	"rule : _LBRACE rules _RBRACE",
	"assign : _EQUALS",
	"assign : _PLUS_EQUALS",
	"assign : _QUESTION_EQUALS",
	"cond : arg1",
	"cond : arg1 _EQUALS arg1",
	"cond : arg1 _BANG_EQUALS arg1",
	"cond : arg1 _LANGLE arg1",
	"cond : arg1 _LANGLE_EQUALS arg1",
	"cond : arg1 _RANGLE arg1",
	"cond : arg1 _RANGLE_EQUALS arg1",
	"cond : arg1 IN arg1",
	"cond : _BANG cond",
	"cond : cond _AMPERAMPER cond",
	"cond : cond _BARBAR cond",
	"cond : _LPAREN cond _RPAREN",
	"cases : /* empty */",
	"cases : case cases",
	"case : CASE ARG _COLON rules",
	"lol : args",
	"lol : args _COLON lol",
	"args : argsany",
	"argsany : /* empty */",
	"argsany : argsany ARG",
	"arg1 : ARG",
	"eflags : /* empty */",
	"eflags : eflags eflag",
	"eflag : UPDATED",
	"eflag : TOGETHER",
	"eflag : IGNORE",
	"eflag : QUIETLY",
	"eflag : PIECEMEAL",
	"eflag : EXISTING",
};
#endif /* YYDEBUG */
/*
 * Copyright (c) 1993 by Sun Microsystems, Inc.
 */

#pragma ident	"@(#)yaccpar	6.12	93/06/07 SMI"

/*
** Skeleton parser driver for yacc output
*/

/*
** yacc user known macros and defines
*/
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define YYBACKUP( newtoken, newvalue )\
{\
	if ( yychar >= 0 || ( yyr2[ yytmp ] >> 1 ) != 1 )\
	{\
		yyerror( "syntax error - cannot backup" );\
		goto yyerrlab;\
	}\
	yychar = newtoken;\
	yystate = *yyps;\
	yylval = newvalue;\
	goto yynewstate;\
}
#define YYRECOVERING()	(!!yyerrflag)
#define YYNEW(type)	malloc(sizeof(type) * yynewmax)
#define YYCOPY(to, from, type) \
	(type *) memcpy(to, (char *) from, yynewmax * sizeof(type))
#define YYENLARGE( from, type) \
	(type *) realloc((char *) from, yynewmax * sizeof(type))
#ifndef YYDEBUG
#	define YYDEBUG	1	/* make debugging available */
#endif

/*
** user known globals
*/
int yydebug;			/* set to 1 to get debugging */

/*
** driver internal defines
*/
#define YYFLAG		(-10000000)

/*
** global variables used by the parser
*/
YYSTYPE *yypv;			/* top of value stack */
int *yyps;			/* top of state stack */

int yystate;			/* current state */
int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */
int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */



#ifdef YYNMBCHARS
#define YYLEX()		yycvtok(yylex())
/*
** yycvtok - return a token if i is a wchar_t value that exceeds 255.
**	If i<255, i itself is the token.  If i>255 but the neither 
**	of the 30th or 31st bit is on, i is already a token.
*/
#if defined(__STDC__) || defined(__cplusplus)
int yycvtok(int i)
#else
int yycvtok(i) int i;
#endif
{
	int first = 0;
	int last = YYNMBCHARS - 1;
	int mid;
	wchar_t j;

	if(i&0x60000000){/*Must convert to a token. */
		if( yymbchars[last].character < i ){
			return i;/*Giving up*/
		}
		while ((last>=first)&&(first>=0)) {/*Binary search loop*/
			mid = (first+last)/2;
			j = yymbchars[mid].character;
			if( j==i ){/*Found*/ 
				return yymbchars[mid].tvalue;
			}else if( j<i ){
				first = mid + 1;
			}else{
				last = mid -1;
			}
		}
		/*No entry in the table.*/
		return i;/* Giving up.*/
	}else{/* i is already a token. */
		return i;
	}
}
#else/*!YYNMBCHARS*/
#define YYLEX()		yylex()
#endif/*!YYNMBCHARS*/

/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
#if defined(__STDC__) || defined(__cplusplus)
int yyparse(void)
#else
int yyparse()
#endif
{
	register YYSTYPE *yypvt;	/* top of value stack for $vars */

#if defined(__cplusplus) || defined(lint)
/*
	hacks to please C++ and lint - goto's inside switch should never be
	executed; yypvt is set to 0 to avoid "used before set" warning.
*/
	static int __yaccpar_lint_hack__ = 0;
	switch (__yaccpar_lint_hack__)
	{
		case 1: goto yyerrlab;
		case 2: goto yynewstate;
	}
	yypvt = 0;
#endif

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;

#if YYMAXDEPTH <= 0
	if (yymaxdepth <= 0)
	{
		if ((yymaxdepth = YYEXPAND(0)) <= 0)
		{
			yyerror("yacc initialization error");
			YYABORT;
		}
	}
#endif

	{
		register YYSTYPE *yy_pv;	/* top of value stack */
		register int *yy_ps;		/* top of state stack */
		register int yy_state;		/* current state */
		register int  yy_n;		/* internal state number info */
	goto yystack;	/* moved from 6 lines above to here to please C++ */

		/*
		** get globals into registers.
		** branch to here only if YYBACKUP was called.
		*/
	yynewstate:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
		goto yy_newstate;

		/*
		** get globals into registers.
		** either we just started, or we just finished a reduction
		*/
	yystack:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;

		/*
		** top of for (;;) loop while no reductions done
		*/
	yy_stack:
		/*
		** put a state and value onto the stacks
		*/
#if YYDEBUG
		/*
		** if debugging, look up token value in list of value vs.
		** name pairs.  0 and negative (-1) are special values.
		** Note: linear search is used since time is not a real
		** consideration while debugging.
		*/
		if ( yydebug )
		{
			register int yy_i;

			printf( "State %d, token ", yy_state );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ++yy_ps >= &yys[ yymaxdepth ] )	/* room on stack? */
		{
			/*
			** reallocate and recover.  Note that pointers
			** have to be reset, or bad things will happen
			*/
			int yyps_index = (yy_ps - yys);
			int yypv_index = (yy_pv - yyv);
			int yypvt_index = (yypvt - yyv);
			int yynewmax;
#ifdef YYEXPAND
			yynewmax = YYEXPAND(yymaxdepth);
#else
			yynewmax = 2 * yymaxdepth;	/* double table size */
			if (yymaxdepth == YYMAXDEPTH)	/* first time growth */
			{
				char *newyys = (char *)YYNEW(int);
				char *newyyv = (char *)YYNEW(YYSTYPE);
				if (newyys != 0 && newyyv != 0)
				{
					yys = YYCOPY(newyys, yys, int);
					yyv = YYCOPY(newyyv, yyv, YYSTYPE);
				}
				else
					yynewmax = 0;	/* failed */
			}
			else				/* not first time */
			{
				yys = YYENLARGE(yys, int);
				yyv = YYENLARGE(yyv, YYSTYPE);
				if (yys == 0 || yyv == 0)
					yynewmax = 0;	/* failed */
			}
#endif
			if (yynewmax <= yymaxdepth)	/* tables not expanded */
			{
				yyerror( "yacc stack overflow" );
				YYABORT;
			}
			yymaxdepth = yynewmax;

			yy_ps = yys + yyps_index;
			yy_pv = yyv + yypv_index;
			yypvt = yyv + yypvt_index;
		}
		*yy_ps = yy_state;
		*++yy_pv = yyval;

		/*
		** we have a new state - find out what to do
		*/
	yy_newstate:
		if ( ( yy_n = yypact[ yy_state ] ) <= YYFLAG )
			goto yydefault;		/* simple state */
#if YYDEBUG
		/*
		** if debugging, need to mark whether new token grabbed
		*/
		yytmp = yychar < 0;
#endif
		if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
			yychar = 0;		/* reached EOF */
#if YYDEBUG
		if ( yydebug && yytmp )
		{
			register int yy_i;

			printf( "Received token " );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ( ( yy_n += yychar ) < 0 ) || ( yy_n >= YYLAST ) )
			goto yydefault;
		if ( yychk[ yy_n = yyact[ yy_n ] ] == yychar )	/*valid shift*/
		{
			yychar = -1;
			yyval = yylval;
			yy_state = yy_n;
			if ( yyerrflag > 0 )
				yyerrflag--;
			goto yy_stack;
		}

	yydefault:
		if ( ( yy_n = yydef[ yy_state ] ) == -2 )
		{
#if YYDEBUG
			yytmp = yychar < 0;
#endif
			if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
				yychar = 0;		/* reached EOF */
#if YYDEBUG
			if ( yydebug && yytmp )
			{
				register int yy_i;

				printf( "Received token " );
				if ( yychar == 0 )
					printf( "end-of-file\n" );
				else if ( yychar < 0 )
					printf( "-none-\n" );
				else
				{
					for ( yy_i = 0;
						yytoks[yy_i].t_val >= 0;
						yy_i++ )
					{
						if ( yytoks[yy_i].t_val
							== yychar )
						{
							break;
						}
					}
					printf( "%s\n", yytoks[yy_i].t_name );
				}
			}
#endif /* YYDEBUG */
			/*
			** look through exception table
			*/
			{
				register int *yyxi = yyexca;

				while ( ( *yyxi != -1 ) ||
					( yyxi[1] != yy_state ) )
				{
					yyxi += 2;
				}
				while ( ( *(yyxi += 2) >= 0 ) &&
					( *yyxi != yychar ) )
					;
				if ( ( yy_n = yyxi[1] ) < 0 )
					YYACCEPT;
			}
		}

		/*
		** check for syntax error
		*/
		if ( yy_n == 0 )	/* have an error */
		{
			/* no worry about speed here! */
			switch ( yyerrflag )
			{
			case 0:		/* new error */
				yyerror( "syntax error" );
				goto skip_init;
			yyerrlab:
				/*
				** get globals into registers.
				** we have a user generated syntax type error
				*/
				yy_pv = yypv;
				yy_ps = yyps;
				yy_state = yystate;
			skip_init:
				yynerrs++;
				/* FALLTHRU */
			case 1:
			case 2:		/* incompletely recovered error */
					/* try again... */
				yyerrflag = 3;
				/*
				** find state where "error" is a legal
				** shift action
				*/
				while ( yy_ps >= yys )
				{
					yy_n = yypact[ *yy_ps ] + YYERRCODE;
					if ( yy_n >= 0 && yy_n < YYLAST &&
						yychk[yyact[yy_n]] == YYERRCODE)					{
						/*
						** simulate shift of "error"
						*/
						yy_state = yyact[ yy_n ];
						goto yy_stack;
					}
					/*
					** current state has no shift on
					** "error", pop stack
					*/
#if YYDEBUG
#	define _POP_ "Error recovery pops state %d, uncovers state %d\n"
					if ( yydebug )
						printf( _POP_, *yy_ps,
							yy_ps[-1] );
#	undef _POP_
#endif
					yy_ps--;
					yy_pv--;
				}
				/*
				** there is no state on stack with "error" as
				** a valid shift.  give up.
				*/
				YYABORT;
			case 3:		/* no shift yet; eat a token */
#if YYDEBUG
				/*
				** if debugging, look up token in list of
				** pairs.  0 and negative shouldn't occur,
				** but since timing doesn't matter when
				** debugging, it doesn't hurt to leave the
				** tests here.
				*/
				if ( yydebug )
				{
					register int yy_i;

					printf( "Error recovery discards " );
					if ( yychar == 0 )
						printf( "token end-of-file\n" );
					else if ( yychar < 0 )
						printf( "token -none-\n" );
					else
					{
						for ( yy_i = 0;
							yytoks[yy_i].t_val >= 0;
							yy_i++ )
						{
							if ( yytoks[yy_i].t_val
								== yychar )
							{
								break;
							}
						}
						printf( "token %s\n",
							yytoks[yy_i].t_name );
					}
				}
#endif /* YYDEBUG */
				if ( yychar == 0 )	/* reached EOF. quit */
					YYABORT;
				yychar = -1;
				goto yy_newstate;
			}
		}/* end if ( yy_n == 0 ) */
		/*
		** reduction by production yy_n
		** put stack tops, etc. so things right after switch
		*/
#if YYDEBUG
		/*
		** if debugging, print the string that is the user's
		** specification of the reduction which is just about
		** to be done.
		*/
		if ( yydebug )
			printf( "Reduce by (%d) \"%s\"\n",
				yy_n, yyreds[ yy_n ] );
#endif
		yytmp = yy_n;			/* value to switch over */
		yypvt = yy_pv;			/* $vars top of value stack */
		/*
		** Look in goto table for next state
		** Sorry about using yy_state here as temporary
		** register variable, but why not, if it works...
		** If yyr2[ yy_n ] doesn't have the low order bit
		** set, then there is no action to be done for
		** this reduction.  So, no saving & unsaving of
		** registers done.  The only difference between the
		** code just after the if and the body of the if is
		** the goto yy_stack in the body.  This way the test
		** can be made before the choice of what to do is needed.
		*/
		{
			/* length of production doubled with extra bit */
			register int yy_len = yyr2[ yy_n ];

			if ( !( yy_len & 01 ) )
			{
				yy_len >>= 1;
				yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
				yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
					*( yy_ps -= yy_len ) + 1;
				if ( yy_state >= YYLAST ||
					yychk[ yy_state =
					yyact[ yy_state ] ] != -yy_n )
				{
					yy_state = yyact[ yypgo[ yy_n ] ];
				}
				goto yy_stack;
			}
			yy_len >>= 1;
			yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
			yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
				*( yy_ps -= yy_len ) + 1;
			if ( yy_state >= YYLAST ||
				yychk[ yy_state = yyact[ yy_state ] ] != -yy_n )
			{
				yy_state = yyact[ yypgo[ yy_n ] ];
			}
		}
					/* save until reenter driver code */
		yystate = yy_state;
		yyps = yy_ps;
		yypv = yy_pv;
	}
	/*
	** code supplied by user is placed in this switch
	*/
	switch( yytmp )
	{
		
case 1:
# line 103 "jamgram.y"
{
			compile_builtins();
		} break;
case 2:
# line 107 "jamgram.y"
{ 
			/* no target, sources in global scope */
			/* invoke statement and then free its parse */

			LOL l;
			lol_init( &l );
			(*(yypvt[-0].parse->func))( yypvt[-0].parse, &l );
			parse_free( yypvt[-0].parse );
		} break;
case 3:
# line 124 "jamgram.y"
{ yyval.parse = yypvt[-0].parse; } break;
case 4:
# line 126 "jamgram.y"
{ yyval.parse = plocal( yypvt[-2].list, yypvt[-0].parse ); } break;
case 5:
# line 130 "jamgram.y"
{ yyval.parse = prules( P0, P0 ); } break;
case 6:
# line 132 "jamgram.y"
{ yyval.parse = prules( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 7:
# line 136 "jamgram.y"
{ yyval.parse = pincl( yypvt[-1].list ); } break;
case 8:
# line 138 "jamgram.y"
{ yyval.parse = prule( yypvt[-2].string, yypvt[-1].parse ); } break;
case 9:
# line 140 "jamgram.y"
{ yyval.parse = pset( yypvt[-3].list, yypvt[-1].list, yypvt[-2].number ); } break;
case 10:
# line 142 "jamgram.y"
{ yyval.parse = pstng( yypvt[-3].list, yypvt[-5].list, yypvt[-1].list, yypvt[-2].number ); } break;
case 11:
# line 144 "jamgram.y"
{ yyval.parse = pset( yypvt[-4].list, yypvt[-1].list, ASSIGN_DEFAULT ); } break;
case 12:
# line 146 "jamgram.y"
{ yyval.parse = pfor( yypvt[-5].string, yypvt[-1].parse, yypvt[-3].list ); } break;
case 13:
# line 148 "jamgram.y"
{ yyval.parse = pswitch( yypvt[-3].list, yypvt[-1].parse ); } break;
case 14:
# line 150 "jamgram.y"
{ yyval.parse = pif( yypvt[-3].parse, pthen( yypvt[-1].parse, P0 ) ); } break;
case 15:
# line 152 "jamgram.y"
{ yyval.parse = pif( yypvt[-5].parse, pthen( yypvt[-3].parse, yypvt[-0].parse ) ); } break;
case 16:
# line 154 "jamgram.y"
{ yyval.parse = psetc( yypvt[-1].string, yypvt[-0].parse ); } break;
case 17:
# line 156 "jamgram.y"
{ yymode( SCAN_STRING ); } break;
case 18:
# line 158 "jamgram.y"
{ yyval.parse = psete( yypvt[-2].string, yypvt[-0].string, yypvt[-3].number );
		  yymode( SCAN_NORMAL ); } break;
case 19:
# line 161 "jamgram.y"
{ yyval.parse = yypvt[-1].parse; } break;
case 20:
# line 169 "jamgram.y"
{ yyval.number = ASSIGN_SET; } break;
case 21:
# line 171 "jamgram.y"
{ yyval.number = ASSIGN_APPEND; } break;
case 22:
# line 173 "jamgram.y"
{ yyval.number = ASSIGN_DEFAULT; } break;
case 23:
# line 181 "jamgram.y"
{ yyval.parse = pcomp( COND_EXISTS, yypvt[-0].list, L0 ); } break;
case 24:
# line 183 "jamgram.y"
{ yyval.parse = pcomp( COND_EQUALS, yypvt[-2].list, yypvt[-0].list ); } break;
case 25:
# line 185 "jamgram.y"
{ yyval.parse = pcomp( COND_NOTEQ, yypvt[-2].list, yypvt[-0].list ); } break;
case 26:
# line 187 "jamgram.y"
{ yyval.parse = pcomp( COND_LESS, yypvt[-2].list, yypvt[-0].list ); } break;
case 27:
# line 189 "jamgram.y"
{ yyval.parse = pcomp( COND_LESSEQ, yypvt[-2].list, yypvt[-0].list ); } break;
case 28:
# line 191 "jamgram.y"
{ yyval.parse = pcomp( COND_MORE, yypvt[-2].list, yypvt[-0].list ); } break;
case 29:
# line 193 "jamgram.y"
{ yyval.parse = pcomp( COND_MOREEQ, yypvt[-2].list, yypvt[-0].list ); } break;
case 30:
# line 195 "jamgram.y"
{ yyval.parse = pcomp( COND_IN, yypvt[-2].list, yypvt[-0].list ); } break;
case 31:
# line 197 "jamgram.y"
{ yyval.parse = pcond( COND_NOT, yypvt[-0].parse, P0 ); } break;
case 32:
# line 199 "jamgram.y"
{ yyval.parse = pcond( COND_AND, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 33:
# line 201 "jamgram.y"
{ yyval.parse = pcond( COND_OR, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 34:
# line 203 "jamgram.y"
{ yyval.parse = yypvt[-1].parse; } break;
case 35:
# line 214 "jamgram.y"
{ yyval.parse = P0; } break;
case 36:
# line 216 "jamgram.y"
{ yyval.parse = pcases( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 37:
# line 220 "jamgram.y"
{ yyval.parse = pcase( yypvt[-2].string, yypvt[-0].parse ); } break;
case 38:
# line 228 "jamgram.y"
{ yyval.parse = plol( P0, yypvt[-0].list ); } break;
case 39:
# line 230 "jamgram.y"
{ yyval.parse = plol( yypvt[-0].parse, yypvt[-2].list ); } break;
case 40:
# line 239 "jamgram.y"
{ yymode( SCAN_NORMAL ); } break;
case 41:
# line 243 "jamgram.y"
{ yyval.list = L0; yymode( SCAN_PUNCT ); } break;
case 42:
# line 245 "jamgram.y"
{ yyval.list = list_new( yypvt[-1].list, copystr( yypvt[-0].string ) ); } break;
case 43:
# line 249 "jamgram.y"
{ yyval.list = list_new( L0, copystr( yypvt[-0].string ) ); } break;
case 44:
# line 258 "jamgram.y"
{ yyval.number = 0; } break;
case 45:
# line 260 "jamgram.y"
{ yyval.number = yypvt[-1].number | yypvt[-0].number; } break;
case 46:
# line 264 "jamgram.y"
{ yyval.number = EXEC_UPDATED; } break;
case 47:
# line 266 "jamgram.y"
{ yyval.number = EXEC_TOGETHER; } break;
case 48:
# line 268 "jamgram.y"
{ yyval.number = EXEC_IGNORE; } break;
case 49:
# line 270 "jamgram.y"
{ yyval.number = EXEC_QUIETLY; } break;
case 50:
# line 272 "jamgram.y"
{ yyval.number = EXEC_PIECEMEAL; } break;
case 51:
# line 274 "jamgram.y"
{ yyval.number = EXEC_EXISTING; } break;
	}
	goto yystack;		/* reset registers in driver code */
}

