#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Sybase) 06/01/96";
#endif
#define YYBYACC 1
#line 64 "jamgram.y"
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
# define psete( s,l,s1,f ) parse_make( compile_setexec,P0,P0,s,s1,l,L0,f )
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

#line 38 "y.tab.c"
#define _BANG 257
#define _BANG_EQUALS 258
#define _AMPERAMPER 259
#define _LPAREN 260
#define _RPAREN 261
#define _PLUS_EQUALS 262
#define _COLON 263
#define _SEMIC 264
#define _LANGLE 265
#define _LANGLE_EQUALS 266
#define _EQUALS 267
#define _RANGLE 268
#define _RANGLE_EQUALS 269
#define _QUESTION_EQUALS 270
#define ACTIONS 271
#define BIND 272
#define CASE 273
#define DEFAULT 274
#define ELSE 275
#define EXISTING 276
#define FOR 277
#define IF 278
#define IGNORE 279
#define IN 280
#define INCLUDE 281
#define LOCAL 282
#define ON 283
#define PIECEMEAL 284
#define QUIETLY 285
#define RULE 286
#define SWITCH 287
#define TOGETHER 288
#define UPDATED 289
#define _LBRACE 290
#define _BARBAR 291
#define _RBRACE 292
#define ARG 293
#define STRING 294
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    2,    2,    3,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,   12,   13,    1,
    7,    7,    7,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    8,    8,   14,    5,    5,
    4,   15,   15,    6,   10,   10,   16,   16,   16,   16,
   16,   16,   11,   11,
};
short yylen[] = {                                         2,
    0,    2,    1,    4,    0,    2,    3,    3,    3,    4,
    6,    5,    7,    5,    5,    7,    3,    0,    0,    9,
    1,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    2,    3,    3,    3,    0,    2,    4,    1,    3,
    1,    0,    2,    1,    0,    2,    1,    1,    1,    1,
    1,    1,    0,    2,
};
short yydefred[] = {                                      1,
    0,   45,    0,    0,   42,    0,   42,    0,    0,    2,
    0,    0,    0,    0,    0,   44,    0,    0,    0,    0,
    0,    0,   42,    0,    0,    0,    0,   22,   21,   23,
    0,   42,   42,   52,   49,   51,   50,   48,   47,    0,
   46,   42,   32,    0,    0,    0,    0,    0,    0,    0,
   42,    0,    0,    0,    8,   43,   17,    0,    0,    7,
    6,   42,    9,   42,    0,    0,   42,    0,    0,   35,
   26,   27,   28,   25,   29,   30,   31,   33,    0,    0,
    0,    0,    0,    5,   40,    0,   42,   10,   54,   18,
    0,    0,    0,   14,   37,    0,   12,    0,    0,    0,
    0,    0,   11,   19,   13,   16,   38,    0,   20,
};
short yydgoto[] = {                                       1,
   61,   24,   25,   26,   27,   11,   33,   82,   18,   12,
   68,   99,  108,   83,   20,   41,
};
int yysindex[] = {                                      0,
 -138,    0, -282, -248,    0, -279,    0, -267,    0,    0,
 -120, -123, -261, -248, -248,    0, -176, -257, -242, -268,
 -138, -264,    0, -249, -138, -213, -236,    0,    0,    0,
 -216,    0,    0,    0,    0,    0,    0,    0,    0, -212,
    0,    0,    0, -220, -241, -241, -241, -241, -241, -241,
    0, -248, -267, -248,    0,    0,    0, -203, -191,    0,
    0,    0,    0,    0, -235, -190,    0, -211, -210,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -209, -173,
 -206, -198, -203,    0,    0, -166,    0,    0,    0,    0,
 -267, -167, -161,    0,    0, -138,    0, -154, -183, -189,
 -138, -267,    0,    0,    0,    0,    0, -180,    0,
};
int yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0, -155, -186,    0,
    0,    0,    0,    0,    0,    0, -243,    0,    0, -195,
    0,    0,    0,    0, -263, -151,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -171,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -155,    0,    0,    0,    0, -175,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -253,
    0,    0, -175,    0,    0,    0,    0,    0,    0,    0,
 -155,    1,    0,    0,    0, -256,    0,    0,    0,    0,
    0, -172,    0,    0,    0,    0,    0,    0,    0,
};
int yygindex[] = {                                      0,
   -1,  -49,   40,   -2,   63,    9,   62,   45,   -8,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 294
short yytable[] = {                                      10,
   15,   52,   19,   79,   22,   43,   44,   34,   14,    3,
   13,   15,   17,   21,   23,   24,    4,   24,   42,   57,
   59,   55,   17,   17,   56,   58,   28,   63,    3,   65,
   66,   29,   53,   54,   30,    4,   34,   34,   52,   69,
   70,  100,   60,   78,   16,   80,   24,   24,   77,   62,
   64,   16,  107,   71,   72,   73,   74,   75,   76,   67,
   17,   86,   17,   41,   89,   41,   41,   41,   41,   81,
   54,   41,   84,   88,   41,   44,   42,   42,   90,   91,
   44,   45,   92,   44,   98,   52,   93,   44,   46,   47,
   48,   49,   50,   94,   41,   41,   44,   97,    5,  106,
    5,  102,  105,   51,    5,    5,   42,  101,    5,  103,
  104,  109,   39,    5,    5,    5,   36,    5,   53,    5,
    5,    5,    5,   96,   85,    5,   87,   95,    0,    0,
    5,    5,    2,    0,    5,    0,    5,    5,    3,    4,
    0,   28,    5,    0,    0,    0,   29,    6,    7,   30,
    0,    8,   34,   31,    9,   35,    0,    0,    0,    0,
   36,   37,   32,    0,   38,   39,    0,    0,    0,   40,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   15,    0,   15,    0,    0,    0,   15,   15,    0,
    0,   15,    0,    0,    0,    0,   15,   15,    0,    0,
   15,    0,   15,   15,
};
short yycheck[] = {                                       1,
    0,  259,    5,   53,    7,   14,   15,  261,  257,  273,
  293,  260,    4,  293,  282,  259,  273,  261,  280,   21,
   23,  264,   14,   15,  293,  290,  262,  264,  292,   32,
   33,  267,  290,  291,  270,  292,  290,  291,  259,   42,
  261,   91,  292,   52,  293,   54,  290,  291,   51,  263,
  267,  293,  102,   45,   46,   47,   48,   49,   50,  272,
   52,   64,   54,  259,   67,  261,  262,  263,  264,  273,
  291,  267,  264,  264,  270,  262,  263,  264,  290,  290,
  267,  258,  292,  270,   87,  259,  293,  274,  265,  266,
  267,  268,  269,  292,  290,  291,  283,  264,  271,  101,
  273,  263,  292,  280,  277,  278,  293,  275,  281,  264,
  294,  292,  264,  286,  287,  271,  292,  290,  290,  292,
  293,  277,  278,   84,   62,  281,   65,   83,   -1,   -1,
  286,  287,  271,   -1,  290,   -1,  292,  293,  277,  278,
   -1,  262,  281,   -1,   -1,   -1,  267,  286,  287,  270,
   -1,  290,  276,  274,  293,  279,   -1,   -1,   -1,   -1,
  284,  285,  283,   -1,  288,  289,   -1,   -1,   -1,  293,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  271,   -1,  273,   -1,   -1,   -1,  277,  278,   -1,
   -1,  281,   -1,   -1,   -1,   -1,  286,  287,   -1,   -1,
  290,   -1,  292,  293,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"_BANG","_BANG_EQUALS",
"_AMPERAMPER","_LPAREN","_RPAREN","_PLUS_EQUALS","_COLON","_SEMIC","_LANGLE",
"_LANGLE_EQUALS","_EQUALS","_RANGLE","_RANGLE_EQUALS","_QUESTION_EQUALS",
"ACTIONS","BIND","CASE","DEFAULT","ELSE","EXISTING","FOR","IF","IGNORE","IN",
"INCLUDE","LOCAL","ON","PIECEMEAL","QUIETLY","RULE","SWITCH","TOGETHER",
"UPDATED","_LBRACE","_BARBAR","_RBRACE","ARG","STRING",
};
char *yyrule[] = {
"$accept : stmts",
"stmts :",
"stmts : stmts rule",
"rules : rule0",
"rules : LOCAL args _SEMIC rule0",
"rule0 :",
"rule0 : rule0 rule",
"rule : _LBRACE rules _RBRACE",
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
"$$1 :",
"$$2 :",
"rule : ACTIONS eflags ARG bindlist _LBRACE $$1 STRING $$2 _RBRACE",
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
"cond : arg1 IN args",
"cond : _BANG cond",
"cond : cond _AMPERAMPER cond",
"cond : cond _BARBAR cond",
"cond : _LPAREN cond _RPAREN",
"cases :",
"cases : case cases",
"case : CASE ARG _COLON rules",
"lol : args",
"lol : args _COLON lol",
"args : argsany",
"argsany :",
"argsany : argsany ARG",
"arg1 : ARG",
"eflags :",
"eflags : eflags eflag",
"eflag : UPDATED",
"eflag : TOGETHER",
"eflag : IGNORE",
"eflag : QUIETLY",
"eflag : PIECEMEAL",
"eflag : EXISTING",
"bindlist :",
"bindlist : BIND args",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
#define yystacksize YYSTACKSIZE
#ifndef YYPRINTF
#define YYPRINTF printf
#endif
#ifndef YYLEXCALL
#define YYLEXCALL() yylex()
#endif
#ifndef YYTOKENERRORCALL
#define YYTOKENERRORCALL() yyerror("syntax error")
#endif
#ifndef YYSTACKERRORCALL
#define YYSTACKERRORCALL() yyerror("yacc stack overflow")
#endif
#ifndef YYINT
#define YYINT int
#endif
#ifndef YYLVAL
#define YYLVAL yylval
#endif
#ifndef YYPARSE
#define YYPARSE() yyparse()
#endif
#ifndef YYABORTCALL
#define YYABORTCALL() return (1)
#endif
#ifndef YYACCEPTCALL
#define YYACCEPTCALL() return (0)
#endif
YYINT yydebug;
YYINT yynerrs;
YYINT yyerrflag;
YYINT yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE YYLVAL;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
YYINT
YYPARSE()
{
    register YYINT yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEXCALL()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            YYPRINTF("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            YYPRINTF("yydebug: state %d, shifting to state %d\n",
                    yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = YYLVAL;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    YYTOKENERRORCALL();
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    YYPRINTF("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = YYLVAL;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    YYPRINTF("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            YYPRINTF("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        YYPRINTF("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 104 "jamgram.y"
{
			compile_builtins();
		}
break;
case 2:
#line 108 "jamgram.y"
{ 
			/* no target, sources in global scope */
			/* invoke statement and then free its parse */

			LOL l;
			lol_init( &l );
			(*(yyvsp[0].parse->func))( yyvsp[0].parse, &l );
			parse_free( yyvsp[0].parse );
		}
break;
case 3:
#line 125 "jamgram.y"
{ yyval.parse = yyvsp[0].parse; }
break;
case 4:
#line 127 "jamgram.y"
{ yyval.parse = plocal( yyvsp[-2].list, yyvsp[0].parse ); }
break;
case 5:
#line 131 "jamgram.y"
{ yyval.parse = prules( P0, P0 ); }
break;
case 6:
#line 133 "jamgram.y"
{ yyval.parse = prules( yyvsp[-1].parse, yyvsp[0].parse ); }
break;
case 7:
#line 137 "jamgram.y"
{ yyval.parse = yyvsp[-1].parse; }
break;
case 8:
#line 139 "jamgram.y"
{ yyval.parse = pincl( yyvsp[-1].list ); }
break;
case 9:
#line 141 "jamgram.y"
{ yyval.parse = prule( yyvsp[-2].string, yyvsp[-1].parse ); }
break;
case 10:
#line 143 "jamgram.y"
{ yyval.parse = pset( yyvsp[-3].list, yyvsp[-1].list, yyvsp[-2].number ); }
break;
case 11:
#line 145 "jamgram.y"
{ yyval.parse = pstng( yyvsp[-3].list, yyvsp[-5].list, yyvsp[-1].list, yyvsp[-2].number ); }
break;
case 12:
#line 147 "jamgram.y"
{ yyval.parse = pset( yyvsp[-4].list, yyvsp[-1].list, ASSIGN_DEFAULT ); }
break;
case 13:
#line 149 "jamgram.y"
{ yyval.parse = pfor( yyvsp[-5].string, yyvsp[-1].parse, yyvsp[-3].list ); }
break;
case 14:
#line 151 "jamgram.y"
{ yyval.parse = pswitch( yyvsp[-3].list, yyvsp[-1].parse ); }
break;
case 15:
#line 153 "jamgram.y"
{ yyval.parse = pif( yyvsp[-3].parse, pthen( yyvsp[-1].parse, P0 ) ); }
break;
case 16:
#line 155 "jamgram.y"
{ yyval.parse = pif( yyvsp[-5].parse, pthen( yyvsp[-3].parse, yyvsp[0].parse ) ); }
break;
case 17:
#line 157 "jamgram.y"
{ yyval.parse = psetc( yyvsp[-1].string, yyvsp[0].parse ); }
break;
case 18:
#line 159 "jamgram.y"
{ yymode( SCAN_STRING ); }
break;
case 19:
#line 161 "jamgram.y"
{ yymode( SCAN_NORMAL ); }
break;
case 20:
#line 163 "jamgram.y"
{ yyval.parse = psete( yyvsp[-6].string,yyvsp[-5].list,yyvsp[-2].string,yyvsp[-7].number ); }
break;
case 21:
#line 171 "jamgram.y"
{ yyval.number = ASSIGN_SET; }
break;
case 22:
#line 173 "jamgram.y"
{ yyval.number = ASSIGN_APPEND; }
break;
case 23:
#line 175 "jamgram.y"
{ yyval.number = ASSIGN_DEFAULT; }
break;
case 24:
#line 183 "jamgram.y"
{ yyval.parse = pcomp( COND_EXISTS, yyvsp[0].list, L0 ); }
break;
case 25:
#line 185 "jamgram.y"
{ yyval.parse = pcomp( COND_EQUALS, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 26:
#line 187 "jamgram.y"
{ yyval.parse = pcomp( COND_NOTEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 27:
#line 189 "jamgram.y"
{ yyval.parse = pcomp( COND_LESS, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 28:
#line 191 "jamgram.y"
{ yyval.parse = pcomp( COND_LESSEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 29:
#line 193 "jamgram.y"
{ yyval.parse = pcomp( COND_MORE, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 30:
#line 195 "jamgram.y"
{ yyval.parse = pcomp( COND_MOREEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 31:
#line 197 "jamgram.y"
{ yyval.parse = pcomp( COND_IN, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 32:
#line 199 "jamgram.y"
{ yyval.parse = pcond( COND_NOT, yyvsp[0].parse, P0 ); }
break;
case 33:
#line 201 "jamgram.y"
{ yyval.parse = pcond( COND_AND, yyvsp[-2].parse, yyvsp[0].parse ); }
break;
case 34:
#line 203 "jamgram.y"
{ yyval.parse = pcond( COND_OR, yyvsp[-2].parse, yyvsp[0].parse ); }
break;
case 35:
#line 205 "jamgram.y"
{ yyval.parse = yyvsp[-1].parse; }
break;
case 36:
#line 216 "jamgram.y"
{ yyval.parse = P0; }
break;
case 37:
#line 218 "jamgram.y"
{ yyval.parse = pcases( yyvsp[-1].parse, yyvsp[0].parse ); }
break;
case 38:
#line 222 "jamgram.y"
{ yyval.parse = pcase( yyvsp[-2].string, yyvsp[0].parse ); }
break;
case 39:
#line 230 "jamgram.y"
{ yyval.parse = plol( P0, yyvsp[0].list ); }
break;
case 40:
#line 232 "jamgram.y"
{ yyval.parse = plol( yyvsp[0].parse, yyvsp[-2].list ); }
break;
case 41:
#line 241 "jamgram.y"
{ yymode( SCAN_NORMAL ); }
break;
case 42:
#line 245 "jamgram.y"
{ yyval.list = L0; yymode( SCAN_PUNCT ); }
break;
case 43:
#line 247 "jamgram.y"
{ yyval.list = list_new( yyvsp[-1].list, copystr( yyvsp[0].string ) ); }
break;
case 44:
#line 251 "jamgram.y"
{ yyval.list = list_new( L0, copystr( yyvsp[0].string ) ); }
break;
case 45:
#line 260 "jamgram.y"
{ yyval.number = 0; }
break;
case 46:
#line 262 "jamgram.y"
{ yyval.number = yyvsp[-1].number | yyvsp[0].number; }
break;
case 47:
#line 266 "jamgram.y"
{ yyval.number = EXEC_UPDATED; }
break;
case 48:
#line 268 "jamgram.y"
{ yyval.number = EXEC_TOGETHER; }
break;
case 49:
#line 270 "jamgram.y"
{ yyval.number = EXEC_IGNORE; }
break;
case 50:
#line 272 "jamgram.y"
{ yyval.number = EXEC_QUIETLY; }
break;
case 51:
#line 274 "jamgram.y"
{ yyval.number = EXEC_PIECEMEAL; }
break;
case 52:
#line 276 "jamgram.y"
{ yyval.number = EXEC_EXISTING; }
break;
case 53:
#line 285 "jamgram.y"
{ yyval.list = L0; }
break;
case 54:
#line 287 "jamgram.y"
{ yyval.list = yyvsp[0].list; }
break;
#line 704 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            YYPRINTF("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEXCALL()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                YYPRINTF("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        YYPRINTF("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    YYSTACKERRORCALL();
yyabort:
    YYABORTCALL();
yyaccept:
    YYACCEPTCALL();
}
