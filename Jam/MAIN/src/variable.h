/*
 * Copyright 1993 Christopher Seiwald.
 */

/*
 * variable.h - handle jam multi-element variables
 */

LIST *var_get();
void var_defines();
void var_set();
LIST *var_swap();
LIST *var_list();
int var_string();
