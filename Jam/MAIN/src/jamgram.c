extern char *malloc(), *realloc();
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
# define ON 281
# define PIECEMEAL 282
# define QUIETLY 283
# define RULE 284
# define SWITCH 285
# define TOGETHER 286
# define UPDATED 287
# define _LBRACE 288
# define _BARBAR 289
# define _RBRACE 290
# define ARG 291
# define STRING 292

# line 62 "jamgram.y"
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
# define prule( s,l,r )   parse_make( compile_rule,P0,P0,s,S0,l,r,0 )
# define prules( l,r )	  parse_make( compile_rules,l,r,S0,S0,L0,L0,0 )
# define pfor( s,p,l )    parse_make( compile_foreach,p,P0,s,S0,l,L0,0 )
# define psetc( s,p )     parse_make( compile_setcomp,p,P0,s,S0,L0,L0,0 )
# define psete( s,s1,f )  parse_make( compile_setexec,P0,P0,s,s1,L0,L0,f )
# define pincl( l )       parse_make( compile_include,P0,P0,S0,S0,l,L0,0 )
# define pswitch( l,p )   parse_make( compile_switch,p,P0,S0,S0,l,L0,0 )
# define pcases( l,r )    parse_make( F0,l,r,S0,S0,L0,L0,0 )
# define pcase( s,p )     parse_make( F0,p,P0,s,S0,L0,L0,0 )
# define pif( l,r )	  parse_make( compile_if,l,r,S0,S0,L0,L0,0 )
# define pthen( l,r )	  parse_make( F0,l,r,S0,S0,L0,L0,0 )
# define pcond( c,l,r )	  parse_make( F0,l,r,S0,S0,L0,L0,c )
# define pcomp( c,l,r )	  parse_make( F0,P0,P0,S0,S0,l,r,c )

#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern int yyerrflag;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#ifndef YYSTYPE
#define YYSTYPE int
#endif
YYSTYPE yylval, yyval;
# define YYERRCODE 256
int yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
-1, 4,
	263, 37,
	264, 37,
	291, 37,
	-2, 39,
	};
# define YYNPROD 48
# define YYLAST 173
int yyact[]={

    10,    89,    87,    27,    32,     6,     8,    28,    25,     3,
    21,    26,    85,     9,     7,    84,    10,    11,    39,    94,
     4,     6,     8,    38,    93,     3,    41,    69,    79,     9,
     7,    37,    10,    11,    90,    88,     4,     6,     8,    34,
    33,     3,    27,    41,    83,     9,     7,    81,    10,    11,
    63,    61,     4,     6,     8,    31,    42,     3,    92,    19,
    41,     9,     7,    59,    18,    11,    56,    20,     4,    30,
    58,    57,    40,    42,    55,    54,    19,    67,    60,    52,
     2,    18,    44,    53,    20,    15,    13,    17,    68,    45,
    46,    43,    47,    48,     5,    16,    12,    80,    29,     1,
     0,    14,    23,    24,    22,     0,     0,    51,     0,     0,
    70,     0,    35,    36,     0,     0,     0,     0,     0,     0,
    24,    24,    64,     0,     0,     0,     0,     0,    49,    50,
     0,    62,     0,     0,    65,    66,    24,    24,    73,    74,
    75,    76,    77,    78,    71,    72,    86,     0,     0,     0,
     0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
     0,    82,    95,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    96 };
int yypact[]={

 -1000,  -223, -1000, -1000, -1000,  -186,  -281, -1000,  -249,  -284,
 -1000, -1000,  -209,  -287,  -224, -1000, -1000,  -236, -1000, -1000,
 -1000,  -256,  -270,  -216,  -176,  -249,  -249, -1000,  -223,  -212,
  -239, -1000, -1000, -1000, -1000,  -214,  -203, -1000, -1000,  -245,
 -1000,  -249,  -249,  -288,  -288,  -288,  -288,  -288,  -288, -1000,
  -233, -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000,
 -1000, -1000,  -217, -1000, -1000,  -220,  -273,  -278,  -245,  -289,
  -255, -1000,  -199, -1000, -1000, -1000, -1000, -1000, -1000, -1000,
  -291, -1000,  -230, -1000, -1000, -1000, -1000,  -205,  -250, -1000,
 -1000,  -271, -1000,  -223, -1000,  -223, -1000 };
int yypgo[]={

     0,    99,    78,    69,    96,    94,    85,    77,   102,    98,
    97,    88,    86,    83 };
int yyr1[]={

     0,     1,     1,     3,     3,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,    10,     2,     2,     6,
     6,     6,     8,     8,     8,     8,     8,     8,     8,     8,
     8,     8,     8,     7,     7,    11,     4,    12,    12,     5,
     9,     9,    13,    13,    13,    13,    13,    13 };
int yyr2[]={

     0,     1,     5,     1,     5,     7,     7,    11,     9,    13,
    11,    15,    11,    11,    15,     7,     1,    11,     7,     3,
     3,     3,     3,     7,     7,     7,     7,     7,     7,     5,
     7,     7,     7,     1,     5,     9,     3,     1,     5,     3,
     1,     5,     3,     3,     3,     3,     3,     3 };
int yychk[]={

 -1000,    -1,    -2,   280,   291,    -5,   276,   285,   277,   284,
   271,   288,    -4,   -12,    -4,    -6,   281,   273,   267,   262,
   270,   291,    -4,    -8,    -5,   257,   260,   291,   291,    -9,
    -3,   264,   291,   264,   263,    -4,    -4,   267,   279,   288,
   288,   259,   289,   267,   258,   265,   266,   268,   269,    -8,
    -8,    -2,   291,   -13,   287,   286,   278,   283,   282,   275,
    -2,   290,    -4,   264,    -6,    -4,    -4,    -7,   -11,   272,
    -3,    -8,    -8,    -5,    -5,    -5,    -5,    -5,    -5,   261,
   -10,   264,    -4,   264,   288,   290,    -7,   291,   290,   292,
   264,    -3,   263,   274,   290,    -3,    -2 };
int yydef[]={

     1,    -2,     2,    37,    -2,     0,     0,    37,     0,     0,
    40,     3,     0,    36,     0,    37,    37,     0,    19,    20,
    21,     0,     0,     0,    22,     0,     0,    39,     0,     0,
     0,     5,    38,     6,    37,     0,     0,    37,    37,    33,
     3,     0,     0,     0,     0,     0,     0,     0,     0,    29,
     0,    15,    16,    41,    42,    43,    44,    45,    46,    47,
     4,    18,     0,     8,    37,     0,     0,     0,    33,     0,
     0,    30,    31,    23,    24,    25,    26,    27,    28,    32,
     0,     7,     0,    10,     3,    12,    34,     0,    13,    17,
     9,     0,     3,     0,    11,    35,    14 };
typedef struct { char *t_name; int t_val; } yytoktype;
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
	"ON",	281,
	"PIECEMEAL",	282,
	"QUIETLY",	283,
	"RULE",	284,
	"SWITCH",	285,
	"TOGETHER",	286,
	"UPDATED",	287,
	"_LBRACE",	288,
	"_BARBAR",	289,
	"_RBRACE",	290,
	"ARG",	291,
	"STRING",	292,
	"-unknown-",	-1	/* ends search */
};

char * yyreds[] =
{
	"-no such reduction-",
	"stmts : /* empty */",
	"stmts : stmts rule",
	"rules : /* empty */",
	"rules : rules rule",
	"rule : INCLUDE args _SEMIC",
	"rule : ARG args _SEMIC",
	"rule : ARG args _COLON args _SEMIC",
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
	"cond : _BANG cond",
	"cond : cond _AMPERAMPER cond",
	"cond : cond _BARBAR cond",
	"cond : _LPAREN cond _RPAREN",
	"cases : /* empty */",
	"cases : case cases",
	"case : CASE ARG _COLON rules",
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
#line 1 "/usr/lib/yaccpar"
/*	@(#)yaccpar 1.10 89/04/04 SMI; from S5R3 1.10	*/

/*
** Skeleton parser driver for yacc output
*/

/*
** yacc user known macros and defines
*/
#define YYERROR		goto yyerrlab
#define YYACCEPT	{ free(yys); free(yyv); return(0); }
#define YYABORT		{ free(yys); free(yyv); return(1); }
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
#define YYFLAG		(-1000)

/*
** static variables used by the parser
*/
static YYSTYPE *yyv;			/* value stack */
static int *yys;			/* state stack */

static YYSTYPE *yypv;			/* top of value stack */
static int *yyps;			/* top of state stack */

static int yystate;			/* current state */
static int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */

int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */


/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
int
yyparse()
{
	register YYSTYPE *yypvt;	/* top of value stack for $vars */
	unsigned yymaxdepth = YYMAXDEPTH;

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yyv = (YYSTYPE*)malloc(yymaxdepth*sizeof(YYSTYPE));
	yys = (int*)malloc(yymaxdepth*sizeof(int));
	if (!yyv || !yys)
	{
		yyerror( "out of memory" );
		return(1);
	}
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;

	goto yystack;
	{
		register YYSTYPE *yy_pv;	/* top of value stack */
		register int *yy_ps;		/* top of state stack */
		register int yy_state;		/* current state */
		register int  yy_n;		/* internal state number info */

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

			(void)printf( "State %d, token ", yy_state );
			if ( yychar == 0 )
				(void)printf( "end-of-file\n" );
			else if ( yychar < 0 )
				(void)printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				(void)printf( "%s\n", yytoks[yy_i].t_name );
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
			yymaxdepth += YYMAXDEPTH;
			yyv = (YYSTYPE*)realloc((char*)yyv,
				yymaxdepth * sizeof(YYSTYPE));
			yys = (int*)realloc((char*)yys,
				yymaxdepth * sizeof(int));
			if (!yyv || !yys)
			{
				yyerror( "yacc stack overflow" );
				return(1);
			}
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
		if ( ( yychar < 0 ) && ( ( yychar = yylex() ) < 0 ) )
			yychar = 0;		/* reached EOF */
#if YYDEBUG
		if ( yydebug && yytmp )
		{
			register int yy_i;

			(void)printf( "Received token " );
			if ( yychar == 0 )
				(void)printf( "end-of-file\n" );
			else if ( yychar < 0 )
				(void)printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				(void)printf( "%s\n", yytoks[yy_i].t_name );
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
			if ( ( yychar < 0 ) && ( ( yychar = yylex() ) < 0 ) )
				yychar = 0;		/* reached EOF */
#if YYDEBUG
			if ( yydebug && yytmp )
			{
				register int yy_i;

				(void)printf( "Received token " );
				if ( yychar == 0 )
					(void)printf( "end-of-file\n" );
				else if ( yychar < 0 )
					(void)printf( "-none-\n" );
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
					(void)printf( "%s\n", yytoks[yy_i].t_name );
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
				yynerrs++;
			skip_init:
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
						(void)printf( _POP_, *yy_ps,
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

					(void)printf( "Error recovery discards " );
					if ( yychar == 0 )
						(void)printf( "token end-of-file\n" );
					else if ( yychar < 0 )
						(void)printf( "token -none-\n" );
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
						(void)printf( "token %s\n",
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
			(void)printf( "Reduce by (%d) \"%s\"\n",
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
# line 100 "jamgram.y"
{
			compile_builtins();
		} break;
case 2:
# line 104 "jamgram.y"
{ 
			(*(yypvt[-0].parse->func))( yypvt[-0].parse, L0, L0 );
			parse_free( yypvt[-0].parse );
		} break;
case 3:
# line 116 "jamgram.y"
{ yyval.parse = prules( P0, P0 ); } break;
case 4:
# line 118 "jamgram.y"
{ yyval.parse = prules( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 5:
# line 122 "jamgram.y"
{ yyval.parse = pincl( yypvt[-1].list ); } break;
case 6:
# line 124 "jamgram.y"
{ yyval.parse = prule( yypvt[-2].string, yypvt[-1].list, L0 ); } break;
case 7:
# line 126 "jamgram.y"
{ yyval.parse = prule( yypvt[-4].string, yypvt[-3].list, yypvt[-1].list ); } break;
case 8:
# line 128 "jamgram.y"
{ yyval.parse = pset( yypvt[-3].list, yypvt[-1].list, yypvt[-2].number ); } break;
case 9:
# line 130 "jamgram.y"
{ yyval.parse = pstng( yypvt[-3].list, yypvt[-5].list, yypvt[-1].list, yypvt[-2].number ); } break;
case 10:
# line 132 "jamgram.y"
{ yyval.parse = pset( yypvt[-4].list, yypvt[-1].list, ASSIGN_DEFAULT ); } break;
case 11:
# line 134 "jamgram.y"
{ yyval.parse = pfor( yypvt[-5].string, yypvt[-1].parse, yypvt[-3].list ); } break;
case 12:
# line 136 "jamgram.y"
{ yyval.parse = pswitch( yypvt[-3].list, yypvt[-1].parse ); } break;
case 13:
# line 138 "jamgram.y"
{ yyval.parse = pif( yypvt[-3].parse, pthen( yypvt[-1].parse, P0 ) ); } break;
case 14:
# line 140 "jamgram.y"
{ yyval.parse = pif( yypvt[-5].parse, pthen( yypvt[-3].parse, yypvt[-0].parse ) ); } break;
case 15:
# line 142 "jamgram.y"
{ yyval.parse = psetc( yypvt[-1].string, yypvt[-0].parse ); } break;
case 16:
# line 144 "jamgram.y"
{ yymode( SCAN_STRING ); } break;
case 17:
# line 146 "jamgram.y"
{ yyval.parse = psete( yypvt[-2].string, yypvt[-0].string, yypvt[-3].number );
		  yymode( SCAN_NORMAL ); } break;
case 18:
# line 149 "jamgram.y"
{ yyval.parse = yypvt[-1].parse; } break;
case 19:
# line 157 "jamgram.y"
{ yyval.number = ASSIGN_SET; } break;
case 20:
# line 159 "jamgram.y"
{ yyval.number = ASSIGN_APPEND; } break;
case 21:
# line 161 "jamgram.y"
{ yyval.number = ASSIGN_DEFAULT; } break;
case 22:
# line 169 "jamgram.y"
{ yyval.parse = pcomp( COND_EXISTS, yypvt[-0].list, L0 ); } break;
case 23:
# line 171 "jamgram.y"
{ yyval.parse = pcomp( COND_EQUALS, yypvt[-2].list, yypvt[-0].list ); } break;
case 24:
# line 173 "jamgram.y"
{ yyval.parse = pcomp( COND_NOTEQ, yypvt[-2].list, yypvt[-0].list ); } break;
case 25:
# line 175 "jamgram.y"
{ yyval.parse = pcomp( COND_LESS, yypvt[-2].list, yypvt[-0].list ); } break;
case 26:
# line 177 "jamgram.y"
{ yyval.parse = pcomp( COND_LESSEQ, yypvt[-2].list, yypvt[-0].list ); } break;
case 27:
# line 179 "jamgram.y"
{ yyval.parse = pcomp( COND_MORE, yypvt[-2].list, yypvt[-0].list ); } break;
case 28:
# line 181 "jamgram.y"
{ yyval.parse = pcomp( COND_MOREEQ, yypvt[-2].list, yypvt[-0].list ); } break;
case 29:
# line 183 "jamgram.y"
{ yyval.parse = pcond( COND_NOT, yypvt[-0].parse, P0 ); } break;
case 30:
# line 185 "jamgram.y"
{ yyval.parse = pcond( COND_AND, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 31:
# line 187 "jamgram.y"
{ yyval.parse = pcond( COND_OR, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 32:
# line 189 "jamgram.y"
{ yyval.parse = yypvt[-1].parse; } break;
case 33:
# line 200 "jamgram.y"
{ yyval.parse = P0; } break;
case 34:
# line 202 "jamgram.y"
{ yyval.parse = pcases( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 35:
# line 206 "jamgram.y"
{ yyval.parse = pcase( yypvt[-2].string, yypvt[-0].parse ); } break;
case 36:
# line 215 "jamgram.y"
{ yymode( SCAN_NORMAL ); } break;
case 37:
# line 219 "jamgram.y"
{ yyval.list = L0; yymode( SCAN_PUNCT ); } break;
case 38:
# line 221 "jamgram.y"
{ yyval.list = list_new( yypvt[-1].list, copystr( yypvt[-0].string ) ); } break;
case 39:
# line 225 "jamgram.y"
{ yyval.list = list_new( L0, copystr( yypvt[-0].string ) ); } break;
case 40:
# line 234 "jamgram.y"
{ yyval.number = 0; } break;
case 41:
# line 236 "jamgram.y"
{ yyval.number = yypvt[-1].number | yypvt[-0].number; } break;
case 42:
# line 240 "jamgram.y"
{ yyval.number = EXEC_UPDATED; } break;
case 43:
# line 242 "jamgram.y"
{ yyval.number = EXEC_TOGETHER; } break;
case 44:
# line 244 "jamgram.y"
{ yyval.number = EXEC_IGNORE; } break;
case 45:
# line 246 "jamgram.y"
{ yyval.number = EXEC_QUIETLY; } break;
case 46:
# line 248 "jamgram.y"
{ yyval.number = EXEC_PIECEMEAL; } break;
case 47:
# line 250 "jamgram.y"
{ yyval.number = EXEC_EXISTING; } break;
	}
	goto yystack;		/* reset registers in driver code */
}
