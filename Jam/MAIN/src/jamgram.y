%token _BANG
%token _BANG_EQUALS
%token _AMPERAMPER
%token _LPAREN
%token _RPAREN
%token _COLON
%token _SEMIC
%token _LANGLE
%token _LANGLE_EQUALS
%token _EQUALS
%token _RANGLE
%token _RANGLE_EQUALS
%token ACTIONS
%token CASE
%token DEFAULT
%token ELSE
%token FOR
%token IF
%token IGNORE
%token IN
%token INCLUDE
%token ON
%token PIECEMEAL
%token QUIETLY
%token RULE
%token SWITCH
%token TOGETHER
%token UPDATED
%token _LBRACE
%token _BARBAR
%token _RBRACE
/*
 * Copyright 1993 Christopher Seiwald.
 */

/*
 * jamgram.yy - jam grammar
 */

%token ARG STRING

%left _BARBAR
%left _AMPERAMPER
%left _BANG

%{
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

%}

%%

/*
 * stmts - the contents of a JAMFILE
 */

stmts	: 
		{
			compile_builtins();
		}
	| stmts rule
		{ 
			(*($2.parse->func))( $2.parse, L0, L0 );
			parse_free( $2.parse );
		}
	;

/*
 * rules - a strings of rule's together
 * rule - any one of jam's rules
 */

rules	: /* empty */
		{ $$.parse = prules( P0, P0 ); }
	| rules rule
		{ $$.parse = prules( $1.parse, $2.parse ); }
	;

rule	: INCLUDE args _SEMIC
		{ $$.parse = pincl( $2.list ); }
	| ARG args _SEMIC
		{ $$.parse = prule( $1.string, $2.list, L0 ); }
	| ARG args _COLON args _SEMIC
		{ $$.parse = prule( $1.string, $2.list, $4.list ); }
	| arg1 _EQUALS args _SEMIC
		{ $$.parse = pset( $1.list, $3.list ); }
	| arg1 DEFAULT _EQUALS args _SEMIC
		{ $$.parse = psetdef( $1.list, $4.list ); }
	| arg1 ON args _EQUALS args _SEMIC
		{ $$.parse = psettings( $3.list, pseton( $1.list, $5.list ) ); }
	| FOR ARG IN args _LBRACE rules _RBRACE
		{ $$.parse = pfor( $2.string, $6.parse, $4.list ); }
	| SWITCH args _LBRACE cases _RBRACE
		{ $$.parse = pswitch( $2.list, $4.parse ); }
	| IF cond _LBRACE rules _RBRACE 
		{ $$.parse = pif( $2.parse, pthen( $4.parse, P0 ) ); }
	| IF cond _LBRACE rules _RBRACE ELSE rule
		{ $$.parse = pif( $2.parse, pthen( $4.parse, $7.parse ) ); }
	| RULE ARG rule
		{ $$.parse = psetc( $2.string, $3.parse ); }
	| ACTIONS eflags ARG 
		{ scan_asstring = 1; }
	  STRING 
		{ $$.parse = psete( $3.string, $5.string, $2.number );
		  scan_asstring = 0; }
	| _LBRACE rules _RBRACE
		{ $$.parse = $2.parse; }
	;

/*
 * cond - a conditional for 'if'
 */

cond	: args 
		{ $$.parse = pcomp( COND_EXISTS, $1.list, L0 ); }
	| args _EQUALS args 
		{ $$.parse = pcomp( COND_EQUALS, $1.list, $3.list ); }
	| args _BANG_EQUALS args
		{ $$.parse = pcomp( COND_NOTEQ, $1.list, $3.list ); }
	| args _LANGLE args
		{ $$.parse = pcomp( COND_LESS, $1.list, $3.list ); }
	| args _LANGLE_EQUALS args 
		{ $$.parse = pcomp( COND_LESSEQ, $1.list, $3.list ); }
	| args _RANGLE args 
		{ $$.parse = pcomp( COND_MORE, $1.list, $3.list ); }
	| args _RANGLE_EQUALS args 
		{ $$.parse = pcomp( COND_MOREEQ, $1.list, $3.list ); }
	| _BANG cond
		{ $$.parse = pcond( COND_NOT, $2.parse, P0 ); }
	| cond _AMPERAMPER cond 
		{ $$.parse = pcond( COND_AND, $1.parse, $3.parse ); }
	| cond _BARBAR cond
		{ $$.parse = pcond( COND_OR, $1.parse, $3.parse ); }
	| _LPAREN cond _RPAREN
		{ $$.parse = $2.parse; }
	;

/*
 * cases - action elements inside a 'switch'
 * case - a single action element inside a 'switch'
 *
 * Unfortunately, a right-recursive rule.
 */

cases	: /* empty */
		{ $$.parse = P0; }
	| case cases
		{ $$.parse = pcases( $1.parse, $2.parse ); }
	;

case	: CASE ARG _COLON rules
		{ $$.parse = pcase( $2.string, $4.parse ); }
	;

/*
 * args - zero or more ARGs in a LIST
 * arg1 - exactly one ARG in a LIST 
 */

args	: /* empty */
		{ $$.list = L0; }
	| args ARG
		{ $$.list = list_new( $1.list, copystr( $2.string ) ); }
	;

arg1	: ARG 
		{ $$.list = list_new( L0, copystr( $1.string ) ); }
	;

/*
 * eflags - zero or more modifiers to 'executes'
 * eflag - a single modifier to 'executes'
 */

eflags	: /* empty */
		{ $$.number = 0; }
	| eflags eflag
		{ $$.number = $1.number | $2.number; }
	;

eflag	: UPDATED
		{ $$.number = EXEC_UPDATED; }
	| TOGETHER
		{ $$.number = EXEC_TOGETHER; }
	| IGNORE
		{ $$.number = EXEC_IGNORE; }
	| QUIETLY
		{ $$.number = EXEC_QUIETLY; }
	| PIECEMEAL
		{ $$.number = EXEC_PIECEMEAL; }
	;

