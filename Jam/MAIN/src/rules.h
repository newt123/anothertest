/*
 * Copyright 1993 Christopher Seiwald.
 */

/*
 * rules.h -  targets, rules, and related information
 *
 * This file describes the structures holding the targets, rules, and
 * related information accumulated by interpreting the statements
 * of the jam files.
 *
 * The following are defined:
 *
 *	RULE - a generic jam rule, the product of RULE and ACTIONS 
 *	ACTIONS - a chain of ACTIONs 
 *	ACTION - a RULE instance with targets and sources 
 *	SETTINGS - variables to set when executing a TARGET's ACTIONS 
 *	TARGETS - a chain of TARGETs 
 *	TARGET - a file or "thing" that can be built 
 */

typedef struct _rule RULE;
typedef struct _target TARGET;
typedef struct _targets TARGETS;
typedef struct _action ACTION;
typedef struct _actions ACTIONS;
typedef struct _settings SETTINGS ;

/* RULE - a generic jam rule, the product of RULE and ACTIONS */

struct _rule {
	char	*name;
	PARSE	*procedure;		/* parse tree from RULE */
	char	*actions;		/* command string from ACTIONS */
	int	flags;			/* modifiers on ACTIONS */

# define	RULE_NEWSRCS	0x01	/* $(>) is updated sources only */
# define	RULE_TOGETHER	0x02	/* combine actions on single target */
# define	RULE_IGNORE	0x04	/* ignore return status of executes */
# define	RULE_QUIETLY	0x08	/* don't mention it unless verbose */
# define	RULE_PIECEMEAL	0x10	/* split exec so each $(>) is small */

} ;

/* ACTIONS - a chain of ACTIONs */

struct _actions {
	ACTIONS	*next;
	ACTIONS	*tail;			/* valid only for head */
	ACTION	*action;
} ;

/* ACTION - a RULE instance with targets and sources */

struct _action {
	RULE	*rule;
	TARGETS	*targets;
	TARGETS	*sources;		/* aka $(>) */
	int	progress;		/* see TARGET progress */
} ;

/* SETTINGS - variables to set when executing a TARGET's ACTIONS */

struct _settings {
	SETTINGS *next;
	char	*symbol;		/* symbol name for var_set() */
	LIST	*value;			/* symbol value for var_set() */
} ;

/* TARGETS - a chain of TARGETs */

struct _targets {
	TARGETS	*next;
	TARGETS	*tail;			/* valid only for head */
	TARGET	*target;
} ;

/* TARGET - a file or "thing" that can be built */

struct _target {
	char	*name;
	char	*boundname;		/* if search() relocates target */
	ACTIONS	*actions;		/* rules to execute, if any */
	TARGETS	*deps;			/* dependencies */
	SETTINGS *settings;		/* variables to define */
	time_t	time;			/* update time */

	int	flags;			/* status info */

# define 	T_FLAG_TEMP 	0x01	/* TEMPORARY applied */
# define 	T_FLAG_NOCARE 	0x02	/* NOCARE applied */
# define 	T_FLAG_NOTIME 	0x04	/* NOTIME applied */
# define	T_FLAG_TOUCHED	0x08	/* -t target applied */

	int	binding;		/* how target relates to real file */

# define 	T_BIND_UNBOUND	0	/* a disembodied name */
# define 	T_BIND_TEMP	1	/* a present temporary */
# define 	T_BIND_EXISTS	2	/* name names a real file */
# define 	T_BIND_MISSING	3	/* couldn't find real file */

	int	fate;			/* make0()'s diagnosis */

# define 	T_FATE_INIT	0	/* nothing done to target */
# define 	T_FATE_MAKING	1	/* make0(target) on stack */
# define 	T_FATE_STABLE	2	/* target didn't need updating */
# define	T_FATE_TOUCHED	3	/* manually touched with -t */
					/* ...rest mean new target... */ 
# define 	T_FATE_ISTMP	4	/* unneeded temp target oddly present */
# define	T_FATE_MISSING	5	/* is missing, needs updating */
# define 	T_FATE_OUTDATED	6	/* is out of date, needs updating */
# define 	T_FATE_UPDATE	7	/* deps updated, needs updating */
# define 	T_FATE_DONTKNOW	8	/* no rules to make missing target */

	int	progress;		/* tracks make1() progress */

# define	T_MAKE_INIT	0	/* make1(target) not yet called */
# define	T_MAKE_STABLE	1	/* make1(target) had nothing to do */
# define	T_MAKE_OK	2	/* make1(target) hasn't failed (yet) */
# define	T_MAKE_FAIL	3	/* make1(target) failed */
# define	T_MAKE_INTR	4	/* make1(target) interrupted by ^C */

	TARGETS	*headers;		/* list of header file codependencies */
	time_t	htime;			/* collected update time for headers */
	int	hfate;			/* collected fate for headers */
} ;

RULE	*bindrule();
TARGET	*bindtarget();
void	touchtarget();
TARGETS	*targetlist();
void	actionlist();
SETTINGS *addsettings();
void 	pushsettings();
void 	popsettings();
