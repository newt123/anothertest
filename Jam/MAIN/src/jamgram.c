extern char *malloc(), *realloc();
# define _BANG 257
# define _BANG_EQUALS 258
# define _AMPERAMPER 259
# define _LPAREN 260
# define _RPAREN 261
# define _COLON 262
# define _SEMIC 263
# define _LANGLE 264
# define _LANGLE_EQUALS 265
# define _EQUALS 266
# define _RANGLE 267
# define _RANGLE_EQUALS 268
# define ACTIONS 269
# define CASE 270
# define DEFAULT 271
# define ELSE 272
# define FOR 273
# define IF 274
# define IGNORE 275
# define IN 276
# define INCLUDE 277
# define ON 278
# define PIECEMEAL 279
# define QUIETLY 280
# define RULE 281
# define SWITCH 282
# define TOGETHER 283
# define UPDATED 284
# define _LBRACE 285
# define _BARBAR 286
# define _RBRACE 287
# define ARG 288
# define STRING 289

# line 47 "jamgram.y"
#include "lists.h"
#include "parse.h"
#include "scan.h"
#include "compile.h"
#include "newstr.h"

# define F0 (void (*)())0
# define P0 (PARSE *)0
# define L0 (LIST *)0
# define S0 (char *)0

# define pset( l,r ) 	  parse_make( compile_set,P0,P0,S0,S0,l,r,0 )
# define psettings( l,p ) parse_make( compile_settings,p,P0,S0,S0,l,L0,0 )
# define pseton( l,r ) 	  parse_make( F0,P0,P0,S0,S0,l,r,0 )
# define psetdef( l,r )   parse_make( compile_setdefault,P0,P0,S0,S0,l,r,0 )
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
	266, 35,
	271, 35,
	278, 35,
	-2, 33,
	};
# define YYNPROD 43
# define YYLAST 177
int yyact[]={

    10,    84,    51,    83,     6,     8,    53,    52,     3,    27,
    50,    49,     9,     7,    81,    47,    11,    10,    88,     4,
    76,     6,     8,    29,    28,     3,    27,    23,    78,     9,
     7,    27,    75,    11,    10,    82,     4,    17,     6,     8,
    59,    57,     3,    26,    33,    27,     9,     7,    87,    27,
    11,    10,    55,     4,    36,     6,     8,    27,    34,     3,
    31,    27,    27,     9,     7,    39,    27,    11,    27,    63,
     4,    40,    41,    38,    42,    43,    36,    79,    73,    14,
    35,    37,    86,    21,    15,    25,    22,    36,    54,    48,
     2,    16,    20,    61,    62,    27,    12,    13,    74,    24,
    18,     5,     1,    37,     0,    19,     0,    30,     0,    32,
     0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
     0,    64,    56,     0,    58,     0,    60,    44,    45,     0,
     0,    67,    68,    69,    70,    71,    72,     0,     0,     0,
     0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
     0,     0,    77,     0,     0,     0,    80,     0,     0,     0,
     0,     0,     0,     0,    85,     0,     0,     0,     0,     0,
     0,     0,    89,     0,     0,     0,    90 };
int yypact[]={

 -1000,  -218, -1000, -1000, -1000,  -187,  -251, -1000,  -174,  -261,
 -1000, -1000,  -220,  -239, -1000,  -206, -1000,  -232,  -227,  -205,
  -193,  -174,  -174,  -218,  -273,  -235, -1000, -1000, -1000, -1000,
  -222, -1000,  -226, -1000,  -201, -1000,  -174,  -174, -1000, -1000,
 -1000, -1000, -1000, -1000, -1000,  -183, -1000, -1000, -1000, -1000,
 -1000, -1000, -1000, -1000, -1000, -1000,  -231, -1000,  -243, -1000,
  -257,  -210,  -201,  -274,  -252, -1000,  -172,  -279,  -279,  -279,
  -279,  -279,  -279, -1000,  -286, -1000, -1000,  -262, -1000, -1000,
 -1000,  -180,  -224, -1000, -1000,  -269, -1000,  -218, -1000,  -218,
 -1000 };
int yypgo[]={

     0,   102,    88,    85,    92,   101,    93,   105,    99,    98,
    94,    89 };
int yyr1[]={

     0,     1,     1,     3,     3,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     9,     2,     2,     7,
     7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     6,     6,    10,     4,     4,     5,     8,     8,    11,    11,
    11,    11,    11 };
int yyr2[]={

     0,     1,     5,     1,     5,     7,     7,    11,     9,    11,
    13,    15,    11,    11,    15,     7,     1,    11,     7,     3,
     7,     7,     7,     7,     7,     7,     5,     7,     7,     7,
     1,     5,     9,     1,     5,     3,     1,     5,     3,     3,
     3,     3,     3 };
int yychk[]={

 -1000,    -1,    -2,   277,   288,    -5,   273,   282,   274,   281,
   269,   285,    -4,    -4,   266,   271,   278,   288,    -4,    -7,
    -4,   257,   260,   288,    -8,    -3,   263,   288,   263,   262,
    -4,   266,    -4,   276,   285,   285,   259,   286,   266,   258,
   264,   265,   267,   268,    -7,    -7,    -2,   288,   -11,   284,
   283,   275,   280,   279,    -2,   287,    -4,   263,    -4,   266,
    -4,    -6,   -10,   270,    -3,    -7,    -7,    -4,    -4,    -4,
    -4,    -4,    -4,   261,    -9,   263,   263,    -4,   285,   287,
    -6,   288,   287,   289,   263,    -3,   262,   272,   287,    -3,
    -2 };
int yydef[]={

     1,    -2,     2,    33,    -2,     0,     0,    33,    33,     0,
    36,     3,     0,     0,    33,     0,    33,     0,     0,     0,
    19,    33,    33,     0,     0,     0,     5,    34,     6,    33,
     0,    33,     0,    33,    30,     3,    33,    33,    33,    33,
    33,    33,    33,    33,    26,     0,    15,    16,    37,    38,
    39,    40,    41,    42,     4,    18,     0,     8,     0,    33,
     0,     0,    30,     0,     0,    27,    28,    20,    21,    22,
    23,    24,    25,    29,     0,     7,     9,     0,     3,    12,
    31,     0,    13,    17,    10,     0,     3,     0,    11,    32,
    14 };
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
	"_COLON",	262,
	"_SEMIC",	263,
	"_LANGLE",	264,
	"_LANGLE_EQUALS",	265,
	"_EQUALS",	266,
	"_RANGLE",	267,
	"_RANGLE_EQUALS",	268,
	"ACTIONS",	269,
	"CASE",	270,
	"DEFAULT",	271,
	"ELSE",	272,
	"FOR",	273,
	"IF",	274,
	"IGNORE",	275,
	"IN",	276,
	"INCLUDE",	277,
	"ON",	278,
	"PIECEMEAL",	279,
	"QUIETLY",	280,
	"RULE",	281,
	"SWITCH",	282,
	"TOGETHER",	283,
	"UPDATED",	284,
	"_LBRACE",	285,
	"_BARBAR",	286,
	"_RBRACE",	287,
	"ARG",	288,
	"STRING",	289,
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
	"rule : arg1 _EQUALS args _SEMIC",
	"rule : arg1 DEFAULT _EQUALS args _SEMIC",
	"rule : arg1 ON args _EQUALS args _SEMIC",
	"rule : FOR ARG IN args _LBRACE rules _RBRACE",
	"rule : SWITCH args _LBRACE cases _RBRACE",
	"rule : IF cond _LBRACE rules _RBRACE",
	"rule : IF cond _LBRACE rules _RBRACE ELSE rule",
	"rule : RULE ARG rule",
	"rule : ACTIONS eflags ARG",
	"rule : ACTIONS eflags ARG STRING",
	"rule : _LBRACE rules _RBRACE",
	"cond : args",
	"cond : args _EQUALS args",
	"cond : args _BANG_EQUALS args",
	"cond : args _LANGLE args",
	"cond : args _LANGLE_EQUALS args",
	"cond : args _RANGLE args",
	"cond : args _RANGLE_EQUALS args",
	"cond : _BANG cond",
	"cond : cond _AMPERAMPER cond",
	"cond : cond _BARBAR cond",
	"cond : _LPAREN cond _RPAREN",
	"cases : /* empty */",
	"cases : case cases",
	"case : CASE ARG _COLON rules",
	"args : /* empty */",
	"args : args ARG",
	"arg1 : ARG",
	"eflags : /* empty */",
	"eflags : eflags eflag",
	"eflag : UPDATED",
	"eflag : TOGETHER",
	"eflag : IGNORE",
	"eflag : QUIETLY",
	"eflag : PIECEMEAL",
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
# line 85 "jamgram.y"
{
			compile_builtins();
		} break;
case 2:
# line 89 "jamgram.y"
{ 
			(*(yypvt[-0].parse->func))( yypvt[-0].parse, L0, L0 );
			parse_free( yypvt[-0].parse );
		} break;
case 3:
# line 101 "jamgram.y"
{ yyval.parse = prules( P0, P0 ); } break;
case 4:
# line 103 "jamgram.y"
{ yyval.parse = prules( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 5:
# line 107 "jamgram.y"
{ yyval.parse = pincl( yypvt[-1].list ); } break;
case 6:
# line 109 "jamgram.y"
{ yyval.parse = prule( yypvt[-2].string, yypvt[-1].list, L0 ); } break;
case 7:
# line 111 "jamgram.y"
{ yyval.parse = prule( yypvt[-4].string, yypvt[-3].list, yypvt[-1].list ); } break;
case 8:
# line 113 "jamgram.y"
{ yyval.parse = pset( yypvt[-3].list, yypvt[-1].list ); } break;
case 9:
# line 115 "jamgram.y"
{ yyval.parse = psetdef( yypvt[-4].list, yypvt[-1].list ); } break;
case 10:
# line 117 "jamgram.y"
{ yyval.parse = psettings( yypvt[-3].list, pseton( yypvt[-5].list, yypvt[-1].list ) ); } break;
case 11:
# line 119 "jamgram.y"
{ yyval.parse = pfor( yypvt[-5].string, yypvt[-1].parse, yypvt[-3].list ); } break;
case 12:
# line 121 "jamgram.y"
{ yyval.parse = pswitch( yypvt[-3].list, yypvt[-1].parse ); } break;
case 13:
# line 123 "jamgram.y"
{ yyval.parse = pif( yypvt[-3].parse, pthen( yypvt[-1].parse, P0 ) ); } break;
case 14:
# line 125 "jamgram.y"
{ yyval.parse = pif( yypvt[-5].parse, pthen( yypvt[-3].parse, yypvt[-0].parse ) ); } break;
case 15:
# line 127 "jamgram.y"
{ yyval.parse = psetc( yypvt[-1].string, yypvt[-0].parse ); } break;
case 16:
# line 129 "jamgram.y"
{ scan_asstring = 1; } break;
case 17:
# line 131 "jamgram.y"
{ yyval.parse = psete( yypvt[-2].string, yypvt[-0].string, yypvt[-3].number );
		  scan_asstring = 0; } break;
case 18:
# line 134 "jamgram.y"
{ yyval.parse = yypvt[-1].parse; } break;
case 19:
# line 142 "jamgram.y"
{ yyval.parse = pcomp( COND_EXISTS, yypvt[-0].list, L0 ); } break;
case 20:
# line 144 "jamgram.y"
{ yyval.parse = pcomp( COND_EQUALS, yypvt[-2].list, yypvt[-0].list ); } break;
case 21:
# line 146 "jamgram.y"
{ yyval.parse = pcomp( COND_NOTEQ, yypvt[-2].list, yypvt[-0].list ); } break;
case 22:
# line 148 "jamgram.y"
{ yyval.parse = pcomp( COND_LESS, yypvt[-2].list, yypvt[-0].list ); } break;
case 23:
# line 150 "jamgram.y"
{ yyval.parse = pcomp( COND_LESSEQ, yypvt[-2].list, yypvt[-0].list ); } break;
case 24:
# line 152 "jamgram.y"
{ yyval.parse = pcomp( COND_MORE, yypvt[-2].list, yypvt[-0].list ); } break;
case 25:
# line 154 "jamgram.y"
{ yyval.parse = pcomp( COND_MOREEQ, yypvt[-2].list, yypvt[-0].list ); } break;
case 26:
# line 156 "jamgram.y"
{ yyval.parse = pcond( COND_NOT, yypvt[-0].parse, P0 ); } break;
case 27:
# line 158 "jamgram.y"
{ yyval.parse = pcond( COND_AND, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 28:
# line 160 "jamgram.y"
{ yyval.parse = pcond( COND_OR, yypvt[-2].parse, yypvt[-0].parse ); } break;
case 29:
# line 162 "jamgram.y"
{ yyval.parse = yypvt[-1].parse; } break;
case 30:
# line 173 "jamgram.y"
{ yyval.parse = P0; } break;
case 31:
# line 175 "jamgram.y"
{ yyval.parse = pcases( yypvt[-1].parse, yypvt[-0].parse ); } break;
case 32:
# line 179 "jamgram.y"
{ yyval.parse = pcase( yypvt[-2].string, yypvt[-0].parse ); } break;
case 33:
# line 188 "jamgram.y"
{ yyval.list = L0; } break;
case 34:
# line 190 "jamgram.y"
{ yyval.list = list_new( yypvt[-1].list, copystr( yypvt[-0].string ) ); } break;
case 35:
# line 194 "jamgram.y"
{ yyval.list = list_new( L0, copystr( yypvt[-0].string ) ); } break;
case 36:
# line 203 "jamgram.y"
{ yyval.number = 0; } break;
case 37:
# line 205 "jamgram.y"
{ yyval.number = yypvt[-1].number | yypvt[-0].number; } break;
case 38:
# line 209 "jamgram.y"
{ yyval.number = EXEC_UPDATED; } break;
case 39:
# line 211 "jamgram.y"
{ yyval.number = EXEC_TOGETHER; } break;
case 40:
# line 213 "jamgram.y"
{ yyval.number = EXEC_IGNORE; } break;
case 41:
# line 215 "jamgram.y"
{ yyval.number = EXEC_QUIETLY; } break;
case 42:
# line 217 "jamgram.y"
{ yyval.number = EXEC_PIECEMEAL; } break;
	}
	goto yystack;		/* reset registers in driver code */
}
