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
    0,    1,    1,    1,    2,    2,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,   12,   13,    4,
    7,    7,    7,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    8,    8,   14,    5,    5,
    3,   15,   15,    6,   10,   10,   16,   16,   16,   16,
   16,   16,   11,   11,
};
const short yylen[] = {                                         2,
    1,    0,    1,    4,    1,    2,    3,    3,    3,    4,
    6,    5,    7,    5,    5,    7,    3,    0,    0,    9,
    1,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    2,    3,    3,    3,    0,    2,    4,    1,    3,
    1,    0,    2,    1,    0,    2,    1,    1,    1,    1,
    1,    1,    0,    2,
};
const short yydefred[] = {                                      0,
   45,    0,    0,   42,   42,    0,   42,    0,    0,    0,
    1,    0,    5,    0,    0,    0,    0,    0,   44,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    6,
   22,   21,   23,    0,   42,   42,   52,   49,   51,   50,
   48,   47,    0,   46,   42,   32,    0,    0,    0,    0,
    0,    0,    0,   42,    0,    0,    0,    8,   43,    0,
   17,    0,    7,   42,    9,   42,    0,    0,   42,    0,
    0,   35,   26,   27,   28,   25,   29,   30,   31,   33,
    0,    0,    4,    0,    0,    0,   40,    0,   42,   10,
   54,   18,    0,    0,    0,   14,   37,   12,    0,    0,
    0,    0,    0,   11,   19,   13,   16,   38,    0,   20,
};
const short yydgoto[] = {                                      10,
   11,   12,   28,   13,   29,   14,   36,   85,   21,   15,
   70,  100,  109,   86,   23,   44,
};
const short yysindex[] = {                                   -172,
    0, -276, -252,    0,    0, -274,    0, -172,    0,    0,
    0, -155,    0, -150, -142, -259, -252, -252,    0, -235,
 -248, -239, -265, -228, -155, -261, -246, -219, -209,    0,
    0,    0,    0, -204,    0,    0,    0,    0,    0,    0,
    0,    0, -207,    0,    0,    0, -237, -226, -226, -226,
 -226, -226, -226,    0, -252, -172, -252,    0,    0, -172,
    0, -197,    0,    0,    0,    0, -174, -195,    0, -213,
 -211,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -212, -173,    0, -196, -203, -197,    0, -166,    0,    0,
    0,    0, -172, -175, -159,    0,    0,    0, -157, -186,
 -181, -155, -172,    0,    0,    0,    0,    0, -167,    0,
};
const short yyrindex[] = {                                    119,
    0,    0,    0,    0,    0,    0,    0, -165, -180,    0,
    0,    3,    0,    0,    0,    0,    0,    0,    0, -241,
    0,    0, -189,    0,    0,    0,    0, -136,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -161,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -165,    0,    0,    0,    4,
    0, -162,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -251,    0,    0,    0, -162,    0,    0,    0,    0,
    0,    0, -165,    1,    0,    0,    0,    0,    0,    0,
    0,    0, -257,    0,    0,    0,    0,    0,    0,    0,
};
const short yygindex[] = {                                      0,
   -8,    0,    2,  -10,   72,    9,   73,   53,   -4,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 296
const short yytable[] = {                                      27,
   15,   30,    3,    2,   17,   22,   24,   18,   26,   34,
   55,   20,   46,   47,   61,    2,   16,   24,   25,   24,
   45,   55,   48,   72,   58,   20,   20,   59,   62,   49,
   50,   51,   52,   53,    2,   60,   67,   68,   34,   34,
   19,   56,   57,   64,   54,   63,   71,   81,   24,   24,
   80,   83,   82,   57,   65,   79,   73,   74,   75,   76,
   77,   78,   66,   20,   69,   20,   19,   88,   90,   41,
   91,   41,   41,   41,   41,   84,   92,   41,   93,   94,
   41,   44,   42,   42,  101,   55,   44,   31,   96,   44,
   99,  107,   32,   44,  108,   33,   95,   98,    1,  102,
   41,   41,   44,  103,    2,    3,  104,  105,    4,    5,
  106,   31,   42,    6,    7,    1,   32,    8,    2,   33,
    9,    2,    3,   34,  110,    4,    2,   39,   53,   36,
    6,    7,   35,   37,    8,   87,   38,    9,   97,   89,
    0,   39,   40,    0,    0,   41,   42,    0,    0,    0,
   43,    0,    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,   15,    0,   15,    0,    3,    2,   15,   15,    0,
    0,   15,    0,    0,    0,    0,   15,   15,    0,    0,
   15,    0,   15,   15,    3,    2,
};
const short yycheck[] = {                                       8,
    0,   12,    0,    0,  257,    4,    5,  260,    7,  261,
  259,    3,   17,   18,   25,  273,  293,  259,  293,  261,
  280,  259,  258,  261,  264,   17,   18,  293,  290,  265,
  266,  267,  268,  269,  292,  264,   35,   36,  290,  291,
  293,  290,  291,  263,  280,  292,   45,   56,  290,  291,
   55,   60,   57,  291,  264,   54,   48,   49,   50,   51,
   52,   53,  267,   55,  272,   57,  293,   66,  264,  259,
   69,  261,  262,  263,  264,  273,  290,  267,  290,  292,
  270,  262,  263,  264,   93,  259,  267,  262,  292,  270,
   89,  102,  267,  274,  103,  270,  293,  264,  271,  275,
  290,  291,  283,  263,  277,  278,  264,  294,  281,  282,
  292,  262,  293,  286,  287,  271,  267,  290,    0,  270,
  293,  277,  278,  274,  292,  281,  292,  264,  290,  292,
  286,  287,  283,  276,  290,   64,  279,  293,   86,   67,
   -1,  284,  285,   -1,   -1,  288,  289,   -1,   -1,   -1,
  293,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,  271,   -1,  273,   -1,  273,  273,  277,  278,   -1,
   -1,  281,   -1,   -1,   -1,   -1,  286,  287,   -1,   -1,
  290,   -1,  292,  293,  292,  292,
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
"block : rules",
"block : LOCAL args _SEMIC block",
"rules : rule",
"rules : rules rule",
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
#line 111 "jamgram.y"
{ yyval.parse = 0; }
break;
case 3:
#line 113 "jamgram.y"
{ yyval.parse = yyvsp[0].parse; }
break;
case 4:
#line 115 "jamgram.y"
{ yyval.parse = plocal( yyvsp[-2].list, yyvsp[0].parse ); }
break;
case 5:
#line 119 "jamgram.y"
{ yyval.parse = yyvsp[0].parse; }
break;
case 6:
#line 121 "jamgram.y"
{ yyval.parse = prules( yyvsp[-1].parse, yyvsp[0].parse ); }
break;
case 7:
#line 125 "jamgram.y"
{ yyval.parse = yyvsp[-1].parse; }
break;
case 8:
#line 127 "jamgram.y"
{ yyval.parse = pincl( yyvsp[-1].list ); }
break;
case 9:
#line 129 "jamgram.y"
{ yyval.parse = prule( yyvsp[-2].string, yyvsp[-1].parse ); }
break;
case 10:
#line 131 "jamgram.y"
{ yyval.parse = pset( yyvsp[-3].list, yyvsp[-1].list, yyvsp[-2].number ); }
break;
case 11:
#line 133 "jamgram.y"
{ yyval.parse = pstng( yyvsp[-3].list, yyvsp[-5].list, yyvsp[-1].list, yyvsp[-2].number ); }
break;
case 12:
#line 135 "jamgram.y"
{ yyval.parse = pset( yyvsp[-4].list, yyvsp[-1].list, ASSIGN_DEFAULT ); }
break;
case 13:
#line 137 "jamgram.y"
{ yyval.parse = pfor( yyvsp[-5].string, yyvsp[-1].parse, yyvsp[-3].list ); }
break;
case 14:
#line 139 "jamgram.y"
{ yyval.parse = pswitch( yyvsp[-3].list, yyvsp[-1].parse ); }
break;
case 15:
#line 141 "jamgram.y"
{ yyval.parse = pif( yyvsp[-3].parse, pthen( yyvsp[-1].parse, P0 ) ); }
break;
case 16:
#line 143 "jamgram.y"
{ yyval.parse = pif( yyvsp[-5].parse, pthen( yyvsp[-3].parse, yyvsp[0].parse ) ); }
break;
case 17:
#line 145 "jamgram.y"
{ yyval.parse = psetc( yyvsp[-1].string, yyvsp[0].parse ); }
break;
case 18:
#line 147 "jamgram.y"
{ yymode( SCAN_STRING ); }
break;
case 19:
#line 149 "jamgram.y"
{ yymode( SCAN_NORMAL ); }
break;
case 20:
#line 151 "jamgram.y"
{ yyval.parse = psete( yyvsp[-6].string,yyvsp[-5].list,yyvsp[-2].string,yyvsp[-7].number ); }
break;
case 21:
#line 159 "jamgram.y"
{ yyval.number = ASSIGN_SET; }
break;
case 22:
#line 161 "jamgram.y"
{ yyval.number = ASSIGN_APPEND; }
break;
case 23:
#line 163 "jamgram.y"
{ yyval.number = ASSIGN_DEFAULT; }
break;
case 24:
#line 171 "jamgram.y"
{ yyval.parse = pcomp( COND_EXISTS, yyvsp[0].list, L0 ); }
break;
case 25:
#line 173 "jamgram.y"
{ yyval.parse = pcomp( COND_EQUALS, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 26:
#line 175 "jamgram.y"
{ yyval.parse = pcomp( COND_NOTEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 27:
#line 177 "jamgram.y"
{ yyval.parse = pcomp( COND_LESS, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 28:
#line 179 "jamgram.y"
{ yyval.parse = pcomp( COND_LESSEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 29:
#line 181 "jamgram.y"
{ yyval.parse = pcomp( COND_MORE, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 30:
#line 183 "jamgram.y"
{ yyval.parse = pcomp( COND_MOREEQ, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 31:
#line 185 "jamgram.y"
{ yyval.parse = pcomp( COND_IN, yyvsp[-2].list, yyvsp[0].list ); }
break;
case 32:
#line 187 "jamgram.y"
{ yyval.parse = pcond( COND_NOT, yyvsp[0].parse, P0 ); }
break;
case 33:
#line 189 "jamgram.y"
{ yyval.parse = pcond( COND_AND, yyvsp[-2].parse, yyvsp[0].parse ); }
break;
case 34:
#line 191 "jamgram.y"
{ yyval.parse = pcond( COND_OR, yyvsp[-2].parse, yyvsp[0].parse ); }
break;
case 35:
#line 193 "jamgram.y"
{ yyval.parse = yyvsp[-1].parse; }
break;
case 36:
#line 204 "jamgram.y"
{ yyval.parse = P0; }
break;
case 37:
#line 206 "jamgram.y"
{ yyval.parse = pcases( yyvsp[-1].parse, yyvsp[0].parse ); }
break;
case 38:
#line 210 "jamgram.y"
{ yyval.parse = pcase( yyvsp[-2].string, yyvsp[0].parse ); }
break;
case 39:
#line 218 "jamgram.y"
{ yyval.parse = plol( P0, yyvsp[0].list ); }
break;
case 40:
#line 220 "jamgram.y"
{ yyval.parse = plol( yyvsp[0].parse, yyvsp[-2].list ); }
break;
case 41:
#line 229 "jamgram.y"
{ yymode( SCAN_NORMAL ); }
break;
case 42:
#line 233 "jamgram.y"
{ yyval.list = L0; yymode( SCAN_PUNCT ); }
break;
case 43:
#line 235 "jamgram.y"
{ yyval.list = list_new( yyvsp[-1].list, copystr( yyvsp[0].string ) ); }
break;
case 44:
#line 239 "jamgram.y"
{ yyval.list = list_new( L0, copystr( yyvsp[0].string ) ); }
break;
case 45:
#line 248 "jamgram.y"
{ yyval.number = 0; }
break;
case 46:
#line 250 "jamgram.y"
{ yyval.number = yyvsp[-1].number | yyvsp[0].number; }
break;
case 47:
#line 254 "jamgram.y"
{ yyval.number = EXEC_UPDATED; }
break;
case 48:
#line 256 "jamgram.y"
{ yyval.number = EXEC_TOGETHER; }
break;
case 49:
#line 258 "jamgram.y"
{ yyval.number = EXEC_IGNORE; }
break;
case 50:
#line 260 "jamgram.y"
{ yyval.number = EXEC_QUIETLY; }
break;
case 51:
#line 262 "jamgram.y"
{ yyval.number = EXEC_PIECEMEAL; }
break;
case 52:
#line 264 "jamgram.y"
{ yyval.number = EXEC_EXISTING; }
break;
case 53:
#line 273 "jamgram.y"
{ yyval.list = L0; }
break;
case 54:
#line 275 "jamgram.y"
{ yyval.list = yyvsp[0].list; }
break;
#line 687 "y.tab.c"
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
