/* 
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

# ifdef VMS

# include "jam.h"
# include "execcmd.h"
# include "lists.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <iodef.h>
#include <ssdef.h>
#include <descrip.h>
#include <dvidef.h>
#include <clidef.h>
#include <libclidef.h>
#include <lib$routines.h>

#include <descrip.h>

/* execvms.c - execute a shell script, ala VMS
 *
 * 05/04/94 (seiwald) - async multiprocess interface; noop on VMS
 * 05/07/95 (wingel) - async multiprocess interface; now for real
 *
 * Wingel is Christer Weinigel at the Ctrl-C Academic Computer Club
 * at the University of Linköping, Sweden (wingel@ctrl-c.liu.se)
 *
 * Most of the code in this file is my (wingel's) fault.  This is one
 * of my first real attempts at using VMS system services, so please
 * don't yell at me if it's too ugly. 
 */

static int initialized = 0;

#define EVENT_MAX 32		/* maximum no of jobs */
#define EVENT_BASE 32		/* base to add to jobs */

/* Jobs waiting */
static struct
{
  void (*func)(void *closure, int rstat);
  void *closure;
  unsigned process_id;
  unsigned status;
  char fn[256];
} jobs[EVENT_MAX];

/* Mask with active jobs */
unsigned eventMask;

/* no of jobs running */
static int activeJobs;

static void sighandler_cc(void)
{
  int i;
  unsigned status;

  signal(SIGINT, SIG_DFL);

  printf("Received SIGINT, waiting for children to terminate\n");
  for (i = 0; i < EVENT_MAX; i++)
    if (jobs[i].func)
      kill(jobs[i].process_id, SIGINT);

  while (execwait())
    ;

  exit(0);
}

void execcmd(char *string, 
	     void (*func)(void *closure, int rstat), 
	     void *closure, 
	     LIST *shell)
{
  unsigned status;
  FILE *fp;
  unsigned slot;
  unsigned event_id;

  if (!initialized)
  {
    int i;
 
    /* Clear function pointers */
    for (i = 0; i < EVENT_MAX; i++)
      jobs[i].func = NULL;

    signal(SIGINT, sighandler_cc);

    eventMask = 0;

    activeJobs = 0;

    initialized = 1;
  }

  /* Allocate an event */
  for (slot = 0; slot < EVENT_MAX; slot++)
    if (jobs[slot].func == NULL)
    {
      event_id = slot + EVENT_BASE;
      status = lib$reserve_ef(&event_id);
      if (status & 1)
	break;
    }
  
  if (slot == EVENT_MAX)
  {
    printf("Could not allocate an event for child\n");
    exit(EXITBAD);
  }

  status = sys$clref(event_id);
  if (!(status & 1))
    exit(status);

  jobs[slot].func = func;
  jobs[slot].closure = closure;

  sprintf(jobs[slot].fn, "sys$scratch:jam%s.temp", tmpnam(NULL));

  if ((fp = fopen(jobs[slot].fn, "w")) == NULL)
  {
    printf("Could not create command file for child\n");
    exit(EXITBAD);
  }
  fwrite(string, strlen(string), 1, fp);
  fclose(fp);

  {
    struct dsc$descriptor_s input_file = { 0, DSC$K_DTYPE_T, DSC$K_CLASS_S };
    unsigned flags = CLI$M_NOWAIT;

    input_file.dsc$w_length = strlen(jobs[slot].fn);
    input_file.dsc$a_pointer = jobs[slot].fn;

    status = lib$spawn(NULL,	/* command string, NULL = CLI */
		       &input_file, /* input file */
		       NULL,	/* output file */
		       &flags,	/* flags */
		       NULL,	/* process name */
		       &jobs[slot].process_id, /* process id */
		       &jobs[slot].status, /* completion status address */
		       &event_id); /* event flag number */
    if (!(status & 1))
    {
      (*func)(closure, EXEC_CMD_FAIL);
      lib$free_ef(&event_id);
      jobs[slot].func = NULL;
      return;
    }
  }

  eventMask |= (1 << slot);

  activeJobs++;

  if (globs.debug >= 3)
    printf("active %d, slot %d, file %s, pid %x\n", 
	   activeJobs, 
	   slot,
	   jobs[slot].fn,
	   jobs[slot].process_id);

  while (activeJobs >= MAXJOBS || activeJobs >= globs.jobs)
    if (!execwait())
	break;
}

int execwait(void)
{
  unsigned semaphore_id;
  unsigned status; 
  unsigned slot;
  int rstat;
  unsigned activeEvents;
  unsigned event_id;
  void (*func)(void *closure, int rstat);
  void *closure;

  if (activeJobs == 0)
    return 0;

  status = sys$wflor(EVENT_BASE, eventMask);
  if (!(status & 1))
    exit(status);

  status = sys$readef(EVENT_BASE, &activeEvents);
  if (!(status & 1))
    exit(status);
  activeEvents &= eventMask;

  for (slot = 0; slot < EVENT_MAX; slot++)
    if (activeEvents & (1 << slot))
      break;
  event_id = slot + EVENT_BASE;

  if (slot == EVENT_MAX)
  {
    printf("Program error, event triggered but got lost\n" );
    printf("(No, you're not supposed to understand this.)\n");
    exit(EXITBAD);
  }

  if (jobs[slot].func == NULL)
  {
    printf("Program error, got event, but no function\n");
    exit(EXITBAD);
  }

  if (globs.debug >= 3)
    printf("active %d, slot %d, file %s, pid %x, status %x\n", 
	   activeJobs,
	   slot,
	   jobs[slot].fn,
	   jobs[slot].process_id,
	   jobs[slot].status);

  /* Prepare to finish off this job */
  func = jobs[slot].func;
  closure = jobs[slot].closure;
  switch (jobs[slot].status & 7)
  {
  case 0:			/* warning */
  case 1:			/* success */
  case 3:			/* informational */
    rstat = EXEC_CMD_OK;
    break;

  case 2:			/* error */
  case 4:			/* severe or fatal error */
    rstat = EXEC_CMD_FAIL;
    break;

  default:
    printf("Undefined status redurned from child\n");
    exit(jobs[slot].status);
  }

  /* Clear everything */
  jobs[slot].func = NULL;
  unlink(jobs[slot].fn);
  lib$free_ef(&event_id);
  eventMask &= ~(1 << slot);

  activeJobs--;

  /* Clear up */
  (*func)(closure, rstat);

  return 1;
}

# endif /* VMS */

