#include "yukd_shell.h"


/**                                                                                                                                                                                                               
 * one_arg_xcute -  a simple shell that collects one argument                                                                                                                                                     
 *                                                                                                                                                                                                                
 * Return : nothing, it is to be looped                                                                                                                                                                           
 */

int one_arg_xcute(void)
{
char *kdbuff = NULL;
size_t kdbuff_size = 0;
int status;
pid_t proc_id;
char *command;
int i = 0;
char **args;
while (1)
{
write(1, "#cisfun$ ", 10);
getline(&kdbuff, &kdbuff_size, stdin);
command = strtok(kdbuff, "\t\n");
args = malloc(sizeof(char *) * 1024);
while (command)
{
args[i] = command;
command = strtok(NULL, "\t\n");
i++;
}
args[i] = NULL;
proc_id = fork();
if (proc_id == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (proc_id == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror("error with execution");
exit(EXIT_FAILURE); }
}
else
{
wait(&status);
}
i = 0;
free(args);}
return (0);
}

}
