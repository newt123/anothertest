#ifndef lint
static char const yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
extern "C" { char *getenv(const char *); }
#else
extern char *getenv();
extern int yylex();
extern int yyparse();
#endif
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


#line 60 "y.tab.c"
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
const short yylhs[] = {                                        -1,
    0,    1,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,   11,   12,    2,    6,    6,
    6,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    7,    7,   13,    4,    4,    3,   14,
   14,    5,    9,    9,   15,   15,   15,   15,   15,   15,
   10,   10,
};
const short yylen[] = {                                         2,
    1,    0,    2,    4,    3,    3,    3,    4,    6,    5,
    7,    5,    5,    7,    3,    0,    0,    9,    1,    1,
    1,    1,    3,    3,    3,    3,    3,    3,    3,    2,
    3,    3,    3,    0,    2,    4,    1,    3,    1,    0,
    2,    1,    0,    2,    1,    1,    1,    1,    1,    1,
    0,    2,
};
const short yydefred[] = {                                      0,
   43,    0,    0,   40,   40,    0,   40,    0,    0,    0,
    1,    0,    0,    0,    0,    0,    0,   42,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    3,   20,
   19,   21,    0,   40,   40,   50,   47,   49,   48,   46,
   45,    0,   44,   40,   30,    0,    0,    0,    0,    0,
    0,    0,   40,    0,    0,    0,    6,   41,    0,   15,
    0,    5,   40,    7,   40,    0,    0,   40,    0,    0,
   33,   24,   25,   26,   23,   27,   28,   29,   31,    0,
    0,    4,    0,    0,    0,   38,    0,   40,    8,   52,
   16,    0,    0,    0,   12,   35,   10,    0,    0,    0,
    0,    0,    9,   17,   11,   14,   36,    0,   18,
};
const short yydgoto[] = {                                      10,
   11,   12,   27,   28,   13,   35,   84,   20,   14,   69,
   99,  108,   85,   22,   43,
};
const short yysindex[] = {                                   -189,
    0, -274, -252,    0,    0, -273,    0, -189,    0,    0,
    0, -189, -167, -145, -253, -252, -252,    0, -139, -237,
 -235, -258, -230, -169, -247, -254, -214, -212,    0,    0,
    0,    0, -203,    0,    0,    0,    0,    0,    0,    0,
    0, -206,    0,    0,    0, -229, -220, -220, -220, -220,
 -220, -220,    0, -252, -189, -252,    0,    0, -189,    0,
 -199,    0,    0,    0,    0, -239, -186,    0, -209, -205,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -201,
 -173,    0, -194, -182, -199,    0, -159,    0,    0,    0,
    0, -189, -164, -150,    0,    0,    0, -149, -180, -172,
 -169, -189,    0,    0,    0,    0,    0, -170,    0,
};
const short yyrindex[] = {                                    123,
    0,    0,    0,    0,    0,    0,    0, -160, -187,    0,
    0,    3,    0,    0,    0,    0,    0,    0, -219,    0,
    0, -246,    0,    0,    0,    0, -131,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -165,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -160,    0,    0,    0,    3,    0,
 -157,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -222,    0,    0,    0, -157,    0,    0,    0,    0,    0,
    0, -160,    1,    0,    0,    0,    0,    0,    0,    0,
    0, -259,    0,    0,    0,    0,    0,    0,    0,
};
const short yygindex[] = {                                      0,
   -8,  -22,    2,   73,    9,   71,   53,   -6,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 295
const short yytable[] = {                                      26,
   13,   60,    2,   29,   16,   21,   23,   17,   25,   45,
   46,   19,   39,    2,   39,   39,   39,   39,   15,   24,
   39,   54,   30,   39,   19,   19,   44,   31,   57,   54,
   32,   71,    2,   59,   58,   66,   67,   62,   32,   22,
   18,   22,   61,   39,   39,   70,   80,   79,   63,   81,
   82,   64,   55,   56,   78,   72,   73,   74,   75,   76,
   77,   56,   19,   65,   19,   68,   87,   32,   32,   90,
   22,   22,   18,   83,   42,   40,   40,   89,  106,   42,
   91,    1,   42,  100,   92,   54,   42,    2,    3,   98,
   93,    4,    5,  107,   30,   42,    6,    7,   94,   31,
    8,    1,   32,    9,   97,   40,   33,    2,    3,   95,
  101,    4,  102,  104,  103,   34,    6,    7,   47,  105,
    8,  109,    2,    9,   51,   48,   49,   50,   51,   52,
   36,    2,   37,   37,   34,   86,   88,   96,   38,   39,
   53,    0,   40,   41,    0,    0,    0,   42,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   13,    0,   13,    0,    2,    0,   13,   13,    0,
    0,   13,   13,    0,    0,    0,   13,   13,    0,    0,
   13,    0,   13,   13,    2,
};
const short yycheck[] = {                                       8,
    0,   24,    0,   12,  257,    4,    5,  260,    7,   16,
   17,    3,  259,  273,  261,  262,  263,  264,  293,  293,
  267,  259,  262,  270,   16,   17,  280,  267,  264,  259,
  270,  261,  292,  264,  293,   34,   35,  292,  261,  259,
  293,  261,  290,  290,  291,   44,   55,   54,  263,   56,
   59,  264,  290,  291,   53,   47,   48,   49,   50,   51,
   52,  291,   54,  267,   56,  272,   65,  290,  291,   68,
  290,  291,  293,  273,  262,  263,  264,  264,  101,  267,
  290,  271,  270,   92,  290,  259,  274,  277,  278,   88,
  292,  281,  282,  102,  262,  283,  286,  287,  293,  267,
  290,  271,  270,  293,  264,  293,  274,  277,  278,  292,
  275,  281,  263,  294,  264,  283,  286,  287,  258,  292,
  290,  292,    0,  293,  290,  265,  266,  267,  268,  269,
  276,  292,  264,  279,  292,   63,   66,   85,  284,  285,
  280,   -1,  288,  289,   -1,   -1,   -1,  293,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  271,   -1,  273,   -1,  273,   -1,  277,  278,   -1,
   -1,  281,  282,   -1,   -1,   -1,  286,  287,   -1,   -1,
  290,   -1,  292,  293,  292,
};
#define YYFINAL 10
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
const char * const yyrule[] = {
"$accept : run",
"run : block",
"block :",
"block : rule block",
"block : LOCAL args _SEMIC block",
"rule : _LBRACE block _RBRACE",
"rule : INCLUDE args _SEMIC",
"rule : ARG lol _SEMIC",
"rule : arg1 assign args _SEMIC",
"rule : arg1 ON args assign args _SEMIC",
"rule : arg1 DEFAULT _EQUALS args _SEMIC",
"rule : FOR ARG IN args _LBRACE block _RBRACE",
"rule : SWITCH args _LBRACE cases _RBRACE",
"rule : IF cond _LBRACE block _RBRACE",
"rule : IF cond _LBRACE block _RBRACE ELSE rule",
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
"case : CASE ARG _COLON block",
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

    if ((yys = getenv("YYDEBUG")))
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
    if ((yyn = yydefred[yystate])) goto yyreduce;
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
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
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
#line 101 "jamgram.y"
{ parse_save( yyvsp[0].parse ); }
break;
case 2:
#line 110 "jamgram.y"
{ yyval.parse = 0; }
break;
case 3:
#line 112 "jamgram.y"
{ yyval.parse = prules( yyvsp[-1].parse, yyvsp[0].parse ); }
break;
case 4:
#line 114 "jamgram.y"
{ yyval.parse = plocal( yyvsp[-2].list, yyvsp[0].parse ); }
break;
case 5:
#line 118 "jamgram.y"
{ yyval.parse = yyvsp[-1].parse; }
break;
case 6:
#line 120 "jamgram.y"
{ yyval.parse = pincl( yyvsp[-1].list ); }
break;
case 7:
#line 122 "jamgram.y"
{ yyval.parse = prule( yyvsp[-2].string, yyvsp[-1].parse ); }
break;
case 8:
#line 124 "jamgram.y"
{ yyval.parse = pset( yyvsp[-3].list, yyvsp[-1].list, yyvsp[-2].number ); }
break;
case 9:
#line 126 "jamgram.y"
{ yyval.parse = pstng( yyvsp[-3].list, yyvsp[-5].list, yyvsp[-1].list, yyvsp[-2].number ); }
break;
case 10:
#line 128 "jamgram.y"
{ yyval.parse = pset( yyvsp[-4].list, yyvsp[-1].list, ASSIGN_DEFAULT ); }
break;
case 11:
#line 130 "jamgram.y"
{ yyval.parse = pfor( yyvsp[-5].string, yyvsp[-1].parse, yyvsp[-3].list ); }
break;
case 12:
#line 132 "jamgram.y"
{ yyval.parse = pswitch( yyvsp[-3].list, yyvsp[-1].parse ); }
break;
case 13:
#line 134 "jamgram.y"
{ yyval.parse = pif( yyvsp[-3].parse, pthen( yyvsp[-1].parse, P0 ) ); }
break;
case 14:
#line 136 "jamgram.y"
{ yyval.parse = pif( yyvsp[-5].parse, pthen( yyvsp[-3].parse, yyvsp[0].parse ) ); }
break;
case 15:
#line 138 "jamgram.y"
{ yyval.parse = psetc( yyvsp[-1].string, yyvsp[0].parse ); }
break;
case 16:
#line 140 "jamgram.y"
{ yymode( SCAN_STRING ); }
break;
case 17:
#line 142 "jamgram.y"
{ yymode( SCAN_NORMAL ); }
break;
case 18:
#line 144 "jamgram.y"
{ yyval.parse = psete( yyvsp[-6].string,yyvsp[-5].list,yyvsp[-2].string,yyvsp[-7].number ); }
break;
case 19:
#line 152 "jamgram.y"
{ yyval.number = ASSIGN_SET; }
break;
case 20:
#line 154 "jamgram.y"
{ yyval.number = ASSIGN_APPEND; }
break;
case 21:
#line 156 "jamgram.y"
{ yyval.number = ASSIGN_DEFAULT; }
break;
case 22:
#line 164 "jamgram.y"
{ yyval.parse = pcomp( COND_EXISTS, yyvsp[0].list, L0 ); }
break;
case 23:
#line 166 "jamgram.y"
{ yyval.parse = pcomp( COND_EQUALS, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 24:
#line 168 "jamgram.y"
{ yyval.parse = pcomp( COND_NOTEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 25:
#line 170 "jamgram.y"
{ yyval.parse = pcomp( COND_LESS, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 26:
#line 172 "jamgram.y"
{ yyval.parse = pcomp( COND_LESSEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 27:
#line 174 "jamgram.y"
{ yyval.parse = pcomp( COND_MORE, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 28:
#line 176 "jamgram.y"
{ yyval.parse = pcomp( COND_MOREEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 29:
#line 178 "jamgram.y"
{ yyval.parse = pcomp( COND_IN, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 30:
#line 180 "jamgram.y"
{ yyval.parse = pcond( COND_NOT, yyvsp[0].parse, P0 ); }
break;
case 31:
#line 182 "jamgram.y"
{ yyval.parse = pcond( COND_AND, yyvsp[-2].parse, yyvsp[0].parse ); }
break;
case 32:
#line 184 "jamgram.y"
{ yyval.parse = pcond( COND_OR, yyvsp[-2].parse, yyvsp[0].parse ); }
break;
case 33:
#line 186 "jamgram.y"
{ yyval.parse = yyvsp[-1].parse; }
break;
case 34:
#line 197 "jamgram.y"
{ yyval.parse = P0; }
break;
case 35:
#line 199 "jamgram.y"
{ yyval.parse = pcases( yyvsp[-1].parse, yyvsp[0].parse ); }
break;
case 36:
#line 203 "jamgram.y"
{ yyval.parse = pcase( yyvsp[-2].string, yyvsp[0].parse ); }
break;
case 37:
#line 211 "jamgram.y"
{ yyval.parse = plol( P0, yyvsp[0].list ); }
break;
case 38:
#line 213 "jamgram.y"
{ yyval.parse = plol( yyvsp[0].parse, yyvsp[-2].list ); }
break;
case 39:
#line 222 "jamgram.y"
{ yymode( SCAN_NORMAL ); }
break;
case 40:
#line 226 "jamgram.y"
{ yyval.list = L0; yymode( SCAN_PUNCT ); }
break;
case 41:
#line 228 "jamgram.y"
{ yyval.list = list_new( yyvsp[-1].list, copystr( yyvsp[0].string ) ); }
break;
case 42:
#line 232 "jamgram.y"
{ yyval.list = list_new( L0, copystr( yyvsp[0].string ) ); }
break;
case 43:
#line 241 "jamgram.y"
{ yyval.number = 0; }
break;
case 44:
#line 243 "jamgram.y"
{ yyval.number = yyvsp[-1].number | yyvsp[0].number; }
break;
case 45:
#line 247 "jamgram.y"
{ yyval.number = EXEC_UPDATED; }
break;
case 46:
#line 249 "jamgram.y"
{ yyval.number = EXEC_TOGETHER; }
break;
case 47:
#line 251 "jamgram.y"
{ yyval.number = EXEC_IGNORE; }
break;
case 48:
#line 253 "jamgram.y"
{ yyval.number = EXEC_QUIETLY; }
break;
case 49:
#line 255 "jamgram.y"
{ yyval.number = EXEC_PIECEMEAL; }
break;
case 50:
#line 257 "jamgram.y"
{ yyval.number = EXEC_EXISTING; }
break;
case 51:
#line 266 "jamgram.y"
{ yyval.list = L0; }
break;
case 52:
#line 268 "jamgram.y"
{ yyval.list = yyvsp[0].list; }
break;
#line 677 "y.tab.c"
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
