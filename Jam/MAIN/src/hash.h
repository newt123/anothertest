/*
 * Copyright 1993 Christopher Seiwald.
 */

/*
 * hash.h - simple in-memory hashing routines 
 */

typedef struct hashdata HASHDATA;

struct hash *	hashinit();
int		hashitem();
void		hashdone();

# define	hashenter( hp, data ) !hashitem( hp, data, !0 )
# define	hashcheck( hp, data ) hashitem( hp, data, 0 )
