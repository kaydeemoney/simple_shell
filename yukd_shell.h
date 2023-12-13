#ifndef _SHELL_H_
#define _SHELL_H_
/*
 * We are trying to define all the
 * header we use in the shell
 * some functions that include system calls
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>


/* q1_shell.c */
int one_arg_xcute(void);

/* q2_shell.c */
int two_args_xcute(void);
#endif
