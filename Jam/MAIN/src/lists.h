/*
 * Copyright 1993 Christopher Seiwald.
 */

/*
 * lists.h - the LIST structure and routines to manipulate them
 */

/*
 * LIST - list of strings
 */

typedef struct _list LIST;

struct _list {
	LIST	*next;
	LIST	*tail;		/* only valid in head node */
	char	*string;	/* private copy */
} ;

LIST 	*list_copy();
LIST 	*list_new();
void	list_free();
void	list_print();
LIST	*list_sublist();

# define list_next( l ) ((l)->next)
