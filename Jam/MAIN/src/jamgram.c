#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
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

#line 44 "y.tab.c"
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
    0,    0,    0,    0,    8,   43,   17,    0,    0,    7,
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
short yysindex[] = {                                      0,
 -150,    0, -282, -250,    0, -281,    0, -268,    0,    0,
 -112, -115, -265, -250, -250,    0, -120, -246, -245, -264,
 -150, -254,    0, -267, -150, -221, -209,    0,    0,    0,
 -208,    0,    0,    0,    0,    0,    0,    0,    0, -212,
    0,    0,    0, -233, -229, -229, -229, -229, -229, -229,
 -229, -250, -268, -250,    0,    0,    0, -204, -194,    0,
    0,    0,    0,    0, -235, -192,    0, -217, -211,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -210, -178,
 -203, -201, -204,    0,    0, -180,    0,    0,    0,    0,
 -268, -186, -169,    0,    0, -150,    0, -166, -199, -193,
 -150, -268,    0,    0,    0,    0,    0, -183,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0, -167, -196,    0,
    0,    0,    0,    0,    0,    0, -257,    0,    0, -187,
    0,    0,    0,    0, -255, -158,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -177,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -167,    0,    0,    0,    0, -176,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -252,
    0,    0, -176,    0,    0,    0,    0,    0,    0,    0,
 -167,    1,    0,    0,    0, -251,    0,    0,    0,    0,
    0, -185,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   -1,  -45,   28,   -2,   53,    2,   52,   35,    9,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 294
short yytable[] = {                                      10,
   15,   24,   19,   24,   22,   17,   14,   79,   34,   15,
   13,   21,   52,   23,   42,   17,   17,    3,   55,   57,
   59,    4,   43,   44,   60,   52,   28,   70,   56,   65,
   66,   29,   24,   24,   30,   58,    3,   34,   34,   69,
    4,   62,   16,   53,   54,  100,   71,   72,   73,   74,
   75,   76,   77,   17,   63,   17,  107,   54,   64,   67,
   78,   86,   80,   16,   89,   44,   42,   42,   81,   84,
   44,   88,   90,   44,   41,   41,   41,   44,   91,   41,
   52,   92,   41,   97,   98,    5,   44,    5,  101,   93,
   94,    5,    5,  102,  104,    5,   42,  103,  105,  106,
    5,    5,   41,    5,    5,   39,    5,    5,  109,    5,
    5,   96,   53,    5,   85,   36,   87,   95,    5,    5,
    2,    0,    5,    0,    5,    5,    3,    4,    0,    0,
    5,    0,    0,    0,    0,    6,    7,   45,    0,    8,
    0,    0,    9,    0,   46,   47,   48,   49,   50,   28,
    0,    0,    0,    0,   29,    0,    0,   30,    0,   51,
   34,   31,    0,   35,    0,    0,    0,    0,   36,   37,
   32,    0,   38,   39,    0,    0,    0,   40,    0,    0,
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
    0,  259,    5,  261,    7,    4,  257,   53,  261,  260,
  293,  293,  259,  282,  280,   14,   15,  273,  264,   21,
   23,  273,   14,   15,  292,  259,  262,  261,  293,   32,
   33,  267,  290,  291,  270,  290,  292,  290,  291,   42,
  292,  263,  293,  290,  291,   91,   45,   46,   47,   48,
   49,   50,   51,   52,  264,   54,  102,  291,  267,  272,
   52,   64,   54,  293,   67,  262,  263,  264,  273,  264,
  267,  264,  290,  270,  262,  263,  264,  274,  290,  267,
  259,  292,  270,  264,   87,  271,  283,  273,  275,  293,
  292,  277,  278,  263,  294,  281,  293,  264,  292,  101,
  286,  287,  290,  271,  290,  264,  292,  293,  292,  277,
  278,   84,  290,  281,   62,  292,   65,   83,  286,  287,
  271,   -1,  290,   -1,  292,  293,  277,  278,   -1,   -1,
  281,   -1,   -1,   -1,   -1,  286,  287,  258,   -1,  290,
   -1,   -1,  293,   -1,  265,  266,  267,  268,  269,  262,
   -1,   -1,   -1,   -1,  267,   -1,   -1,  270,   -1,  280,
  276,  274,   -1,  279,   -1,   -1,   -1,   -1,  284,  285,
  283,   -1,  288,  289,   -1,   -1,   -1,  293,   -1,   -1,
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
"cond : arg1 IN arg1",
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
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
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
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
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
    yyerror("syntax error");
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
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
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
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
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
#line 681 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
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
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
