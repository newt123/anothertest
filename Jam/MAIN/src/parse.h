/*
 * Copyright 1993 Christopher Seiwald.
 */

/*
 * parse.h - make and destroy parse trees as driven by the parser
 */

/*
 * parse tree node
 */

typedef struct _PARSE PARSE;

struct _PARSE {
	void	(*func)();
	PARSE	*left;
	PARSE	*right;
	char	*string;
	char	*string1;
	LIST	*llist;
	LIST	*rlist;
	int	num;
} ;

PARSE	*parse_make();
void	parse_free();
