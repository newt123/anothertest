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
#line 63 "jamgram.y"
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
# define plocal( l,p )	  parse_make( compile_local,p,P0,S0,S0,l,L0,0 );
# define pcases( l,r )    parse_make( F0,l,r,S0,S0,L0,L0,0 )
# define pcase( s,p )     parse_make( F0,p,P0,s,S0,L0,L0,0 )
# define pif( l,r )	  parse_make( compile_if,l,r,S0,S0,L0,L0,0 )
# define pthen( l,r )	  parse_make( F0,l,r,S0,S0,L0,L0,0 )
# define pcond( c,l,r )	  parse_make( F0,l,r,S0,S0,L0,L0,c )
# define pcomp( c,l,r )	  parse_make( F0,P0,P0,S0,S0,l,r,c )

#line 43 "y.tab.c"
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
#define CASE 272
#define DEFAULT 273
#define ELSE 274
#define EXISTING 275
#define FOR 276
#define IF 277
#define IGNORE 278
#define IN 279
#define INCLUDE 280
#define LOCAL 281
#define ON 282
#define PIECEMEAL 283
#define QUIETLY 284
#define RULE 285
#define SWITCH 286
#define TOGETHER 287
#define UPDATED 288
#define _LBRACE 289
#define _BARBAR 290
#define _RBRACE 291
#define ARG 292
#define STRING 293
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    2,    2,    3,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,   10,    1,    1,
    6,    6,    6,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    7,    7,   11,    4,   12,
   12,    5,    9,    9,   13,   13,   13,   13,   13,   13,
};
short yylen[] = {                                         2,
    0,    2,    1,    4,    0,    2,    3,    3,    5,    4,
    6,    5,    7,    5,    5,    7,    3,    0,    5,    3,
    1,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    2,    3,    3,    3,    0,    2,    4,    1,    0,
    2,    1,    0,    2,    1,    1,    1,    1,    1,    1,
};
short yydefred[] = {                                      1,
    0,   43,    0,    0,   40,    0,   40,    0,    0,    2,
    0,    0,    0,    0,    0,   42,    0,    0,    0,    0,
    0,    0,   40,    0,    0,    0,   22,   21,   23,    0,
   40,   40,   50,   47,   49,   48,   46,   45,   18,   44,
   40,   32,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    7,   41,   17,    0,    0,   20,    6,
   40,    8,   40,    0,    0,    0,    0,   35,   26,   27,
   28,   25,   29,   30,   31,   33,    0,    0,    0,    0,
    0,    5,    0,    0,   40,   10,   19,    0,    0,    0,
   14,   37,    0,    9,   12,    0,    0,    0,    0,   11,
   13,   16,   38,
};
short yydgoto[] = {                                       1,
   60,   24,   25,   19,   11,   32,   80,   18,   12,   66,
   81,   20,   40,
};
short yysindex[] = {                                      0,
 -147,    0, -280, -252,    0, -273,    0, -260,    0,    0,
 -136, -169, -255, -252, -252,    0, -118, -256, -234, -257,
 -147, -244,    0, -259, -147, -249,    0,    0,    0, -210,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -230, -227, -227, -227, -227, -227, -227, -227,
 -252, -260, -252,    0,    0,    0, -235, -195,    0,    0,
    0,    0,    0, -196, -192, -225, -214,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -212, -176, -207, -205,
 -235,    0, -177, -175,    0,    0,    0, -260, -180, -170,
    0,    0, -147,    0,    0, -166, -203, -147, -260,    0,
    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0, -164, -200,    0,
    0,    0,    0,    0,    0,    0, -248,    0,    0, -186,
    0,    0,    0,    0, -263,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -164,    0,    0,    0,    0, -191,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -251,    0,    0,
 -191,    0,    0,    0,    0,    0,    0, -164,    1,    0,
    0,    0, -247,    0,    0,    0,    0,    0, -181,    0,
    0,    0,    0,
};
short yygindex[] = {                                      0,
   -1,  -45,   19,   -5,    2,   38,   36,    8,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 293
short yytable[] = {                                      10,
   15,   22,   51,   26,   14,   17,   77,   15,    3,   34,
   24,   13,   24,   61,   62,   17,   17,   58,   21,   56,
   23,   42,   43,   41,    4,   64,   65,    3,   51,   54,
   68,   59,   52,   53,   55,   67,   79,   34,   34,   16,
   24,   24,   97,    4,   57,   69,   70,   71,   72,   73,
   74,   75,   17,  103,   17,   83,   63,   84,   76,   53,
   78,   42,   40,   40,   16,   27,   42,   87,   82,   42,
   28,   86,   42,   29,   88,   39,   39,   39,   89,   96,
   39,   42,   51,   39,   90,   91,   94,  101,   95,    5,
    5,   40,   99,   98,    5,    5,  102,  100,    5,   36,
   93,   85,   39,    5,    5,   33,    5,    5,   34,    5,
    5,    5,    5,   35,   36,    5,   92,   37,   38,    0,
    5,    5,   39,    2,    5,   27,    5,    5,    3,    4,
   28,    0,    5,   29,    0,    0,   30,    6,    7,   44,
    0,    8,    0,    0,    9,   31,   45,   46,   47,   48,
   49,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   50,    0,    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,   15,   15,    0,    0,    0,   15,   15,    0,    0,
   15,    0,    0,    0,    0,   15,   15,    0,    0,   15,
    0,   15,   15,
};
short yycheck[] = {                                       1,
    0,    7,  259,    9,  257,    4,   52,  260,  272,  261,
  259,  292,  261,  263,  264,   14,   15,   23,  292,   21,
  281,   14,   15,  279,  272,   31,   32,  291,  259,  264,
  261,  291,  289,  290,  292,   41,  272,  289,  290,  292,
  289,  290,   88,  291,  289,   44,   45,   46,   47,   48,
   49,   50,   51,   99,   53,   61,  267,   63,   51,  290,
   53,  262,  263,  264,  292,  262,  267,  293,  264,  270,
  267,  264,  273,  270,  289,  262,  263,  264,  291,   85,
  267,  282,  259,  270,  292,  291,  264,  291,  264,  271,
  272,  292,  263,  274,  276,  277,   98,  264,  280,  291,
   82,   64,  289,  285,  286,  275,  271,  289,  278,  291,
  292,  276,  277,  283,  284,  280,   81,  287,  288,   -1,
  285,  286,  292,  271,  289,  262,  291,  292,  276,  277,
  267,   -1,  280,  270,   -1,   -1,  273,  285,  286,  258,
   -1,  289,   -1,   -1,  292,  282,  265,  266,  267,  268,
  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,  271,  272,   -1,   -1,   -1,  276,  277,   -1,   -1,
  280,   -1,   -1,   -1,   -1,  285,  286,   -1,   -1,  289,
   -1,  291,  292,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 293
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
"ACTIONS","CASE","DEFAULT","ELSE","EXISTING","FOR","IF","IGNORE","IN","INCLUDE",
"LOCAL","ON","PIECEMEAL","QUIETLY","RULE","SWITCH","TOGETHER","UPDATED",
"_LBRACE","_BARBAR","_RBRACE","ARG","STRING",
};
char *yyrule[] = {
"$accept : stmts",
"stmts :",
"stmts : stmts rule",
"rules : rule0",
"rules : LOCAL args _SEMIC rule0",
"rule0 :",
"rule0 : rule0 rule",
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
"$$1 :",
"rule : ACTIONS eflags ARG $$1 STRING",
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
"cases :",
"cases : case cases",
"case : CASE ARG _COLON rules",
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
#line 102 "jamgram.y"
{
			compile_builtins();
		}
break;
case 2:
#line 106 "jamgram.y"
{ 
			(*(yyvsp[0].parse->func))( yyvsp[0].parse, L0, L0 );
			parse_free( yyvsp[0].parse );
		}
break;
case 3:
#line 118 "jamgram.y"
{ yyval.parse = yyvsp[0].parse; }
break;
case 4:
#line 120 "jamgram.y"
{ yyval.parse = plocal( yyvsp[-2].list, yyvsp[0].parse ); }
break;
case 5:
#line 124 "jamgram.y"
{ yyval.parse = prules( P0, P0 ); }
break;
case 6:
#line 126 "jamgram.y"
{ yyval.parse = prules( yyvsp[-1].parse, yyvsp[0].parse ); }
break;
case 7:
#line 130 "jamgram.y"
{ yyval.parse = pincl( yyvsp[-1].list ); }
break;
case 8:
#line 132 "jamgram.y"
{ yyval.parse = prule( yyvsp[-2].string, yyvsp[-1].list, L0 ); }
break;
case 9:
#line 134 "jamgram.y"
{ yyval.parse = prule( yyvsp[-4].string, yyvsp[-3].list, yyvsp[-1].list ); }
break;
case 10:
#line 136 "jamgram.y"
{ yyval.parse = pset( yyvsp[-3].list, yyvsp[-1].list, yyvsp[-2].number ); }
break;
case 11:
#line 138 "jamgram.y"
{ yyval.parse = pstng( yyvsp[-3].list, yyvsp[-5].list, yyvsp[-1].list, yyvsp[-2].number ); }
break;
case 12:
#line 140 "jamgram.y"
{ yyval.parse = pset( yyvsp[-4].list, yyvsp[-1].list, ASSIGN_DEFAULT ); }
break;
case 13:
#line 142 "jamgram.y"
{ yyval.parse = pfor( yyvsp[-5].string, yyvsp[-1].parse, yyvsp[-3].list ); }
break;
case 14:
#line 144 "jamgram.y"
{ yyval.parse = pswitch( yyvsp[-3].list, yyvsp[-1].parse ); }
break;
case 15:
#line 146 "jamgram.y"
{ yyval.parse = pif( yyvsp[-3].parse, pthen( yyvsp[-1].parse, P0 ) ); }
break;
case 16:
#line 148 "jamgram.y"
{ yyval.parse = pif( yyvsp[-5].parse, pthen( yyvsp[-3].parse, yyvsp[0].parse ) ); }
break;
case 17:
#line 150 "jamgram.y"
{ yyval.parse = psetc( yyvsp[-1].string, yyvsp[0].parse ); }
break;
case 18:
#line 152 "jamgram.y"
{ yymode( SCAN_STRING ); }
break;
case 19:
#line 154 "jamgram.y"
{ yyval.parse = psete( yyvsp[-2].string, yyvsp[0].string, yyvsp[-3].number );
		  yymode( SCAN_NORMAL ); }
break;
case 20:
#line 157 "jamgram.y"
{ yyval.parse = yyvsp[-1].parse; }
break;
case 21:
#line 165 "jamgram.y"
{ yyval.number = ASSIGN_SET; }
break;
case 22:
#line 167 "jamgram.y"
{ yyval.number = ASSIGN_APPEND; }
break;
case 23:
#line 169 "jamgram.y"
{ yyval.number = ASSIGN_DEFAULT; }
break;
case 24:
#line 177 "jamgram.y"
{ yyval.parse = pcomp( COND_EXISTS, yyvsp[0].list, L0 ); }
break;
case 25:
#line 179 "jamgram.y"
{ yyval.parse = pcomp( COND_EQUALS, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 26:
#line 181 "jamgram.y"
{ yyval.parse = pcomp( COND_NOTEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 27:
#line 183 "jamgram.y"
{ yyval.parse = pcomp( COND_LESS, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 28:
#line 185 "jamgram.y"
{ yyval.parse = pcomp( COND_LESSEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 29:
#line 187 "jamgram.y"
{ yyval.parse = pcomp( COND_MORE, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 30:
#line 189 "jamgram.y"
{ yyval.parse = pcomp( COND_MOREEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 31:
#line 191 "jamgram.y"
{ yyval.parse = pcomp( COND_IN, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 32:
#line 193 "jamgram.y"
{ yyval.parse = pcond( COND_NOT, yyvsp[0].parse, P0 ); }
break;
case 33:
#line 195 "jamgram.y"
{ yyval.parse = pcond( COND_AND, yyvsp[-2].parse, yyvsp[0].parse ); }
break;
case 34:
#line 197 "jamgram.y"
{ yyval.parse = pcond( COND_OR, yyvsp[-2].parse, yyvsp[0].parse ); }
break;
case 35:
#line 199 "jamgram.y"
{ yyval.parse = yyvsp[-1].parse; }
break;
case 36:
#line 210 "jamgram.y"
{ yyval.parse = P0; }
break;
case 37:
#line 212 "jamgram.y"
{ yyval.parse = pcases( yyvsp[-1].parse, yyvsp[0].parse ); }
break;
case 38:
#line 216 "jamgram.y"
{ yyval.parse = pcase( yyvsp[-2].string, yyvsp[0].parse ); }
break;
case 39:
#line 225 "jamgram.y"
{ yymode( SCAN_NORMAL ); }
break;
case 40:
#line 229 "jamgram.y"
{ yyval.list = L0; yymode( SCAN_PUNCT ); }
break;
case 41:
#line 231 "jamgram.y"
{ yyval.list = list_new( yyvsp[-1].list, copystr( yyvsp[0].string ) ); }
break;
case 42:
#line 235 "jamgram.y"
{ yyval.list = list_new( L0, copystr( yyvsp[0].string ) ); }
break;
case 43:
#line 244 "jamgram.y"
{ yyval.number = 0; }
break;
case 44:
#line 246 "jamgram.y"
{ yyval.number = yyvsp[-1].number | yyvsp[0].number; }
break;
case 45:
#line 250 "jamgram.y"
{ yyval.number = EXEC_UPDATED; }
break;
case 46:
#line 252 "jamgram.y"
{ yyval.number = EXEC_TOGETHER; }
break;
case 47:
#line 254 "jamgram.y"
{ yyval.number = EXEC_IGNORE; }
break;
case 48:
#line 256 "jamgram.y"
{ yyval.number = EXEC_QUIETLY; }
break;
case 49:
#line 258 "jamgram.y"
{ yyval.number = EXEC_PIECEMEAL; }
break;
case 50:
#line 260 "jamgram.y"
{ yyval.number = EXEC_EXISTING; }
break;
#line 653 "y.tab.c"
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
