/*
 * Copyright 1993 Christopher Seiwald.
 */

# include "jam.h"
# include "jamgram.h"
# include "lists.h"
# include "parse.h"
# include "scan.h"
# include "newstr.h"

/*
 * scan.c - the jam yacc scanner
 */

struct keyword {
	char *word;
	int type;
} keywords[] = {
# include "jamgramtab.h"
	0, 0
} ;

# define MAX_INCLUDES 10

static struct {
	char *string;
	FILE *file;
	char *fname;
	int line;
	char buf[ 512 ];
} includes[ MAX_INCLUDES ] = {0}, *incp = includes;

static int incdepth = 0;

int scan_asstring = 0;

static char *symdump();

/* 
 */

yyerror( s )
char *s;
{
	if( incdepth )
	    printf( "%s: line %d: ", incp->fname, incp->line );

	printf( "%s at %s\n", s, symdump( &yylval ) );
}

yyfparse( s )
char *s;
{
	FILE *f = stdin;

	if( incdepth == MAX_INCLUDES )
	{
	    printf( "%s: too many levels of nested includes\n", s );
	    return;
	}

	if( strcmp( s, "-" ) && !( f = fopen( s, "r" ) ) )
	    perror( s );

	incdepth++;
	incp = &includes[ incdepth - 1 ];
	incp->string = "";
	incp->file = f;
	incp->fname = s;
	incp->line = 0;
}

/*
 * get character routine
 */

yyline()
{
top:
	if( incp->file )
	{
	    if( fgets( incp->buf, sizeof( incp->buf ), incp->file ) )
	    {
		incp->line++;
		incp->string = incp->buf;
		return *incp->string++;
	    }

	    if( incp->file != stdin )
		    fclose( incp->file );
	} 

	if( !--incdepth )
	    return EOF;

	incp = &includes[ incdepth - 1 ];

	if( !*incp->string )
	    goto top;

	return *incp->string++;
}

/*
 * yylex() - set yylval to current token; return its type
 */

# define yychar() ( *incp->string ? *incp->string++ : yyline() )

yylex()
{
	char buf[512];
	int c = *incp->string;

	for( ;; )
	{
		while( !c || isspace( c ) && c != EOF )
			c = yychar();
		if( c != '#' )
			break;
		while( ( c = yychar() ) != EOF && c != '\n' )
			;
	}

	if( c == EOF )
	{
		yylval.type = EOF;
		return EOF;
	} 
	else if( c == '{' && scan_asstring )
	{
		/* look for closing { */

		char *b = buf;
		int nest = 1;

		while( ( c = yychar() ) != EOF )
		{
			if( c == '{' )
				nest++;
			else if( c == '}' )
				nest--;
			if( !nest )
			    break;
			*b++ = c;
		}
		*b = 0;
		yylval.type = STRING;
		yylval.string = newstr( buf );
	}
	else 
	{
		/* look for white space to delimit word */
		/* "'s get stripped but preserve white space */

		char *b = buf;
		int inquote = 0;
		int literal = 0;
		int hasquote = 0;
		struct keyword *k;

		do {
		    if( literal )
			*b++ = c, literal = 0;
		    else if( c == '\\' )
			literal++;
		    else if( c == '"' )
			inquote = !inquote, hasquote++;
		    else
			*b++ = c;
		}
		while( ( c=yychar() ) != EOF && ( inquote || !isspace( c ) ) );
		incp->string--;
		*b = 0;

		/* scan token table, except for $anything and quoted anything */

		yylval.type = ARG;

		if( *buf != '$' && !hasquote )
		    for( k = keywords; k->word; k++ )
			if( *buf == *k->word && !strcmp( k->word, buf ) )
		{
		    yylval.type = k->type;
		    yylval.string = k->word;	/* used by symdump */
		    break;
		}

		if( yylval.type == ARG )
		    yylval.string = newstr( buf );
	}

	if( DEBUG_SCAN )
		printf( "scan %s\n", symdump( &yylval ) );

	return yylval.type;
}

static char *
symdump( s )
YYSTYPE *s;
{
	static char buf[ 512 ];

	switch( s->type )
	{
	case EOF:
		sprintf( buf, "EOF" );
		break;
	case 0:
		sprintf( buf, "unknown symbol %s", s->string );
		break;
	case ARG:
		sprintf( buf, "argument %s", s->string );
		break;
	case STRING:
		sprintf( buf, "string \"%s\"", s->string );
		break;
	default:
		sprintf( buf, "keyword %s", s->string );
		break;
	}
	return buf;
}
