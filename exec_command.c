#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "command_utils.h"
#include "custom_string.h"
#include <string.h>

#define MAX_ARGS 10 /* Maximum number of arguments for the command */

/**
* execute_command - Execute a specific command.
* @command: The command to execute.
* @args: An array of strings containing the arguments.
*
* Description: This function executes a specific command
* and performs the necessary actions based on the command.
* Return: Return value of the executed command.
**/
int execute_command(char *command, char **args)
{
pid_t pid;
int status;
char *command_path;
/* char *exit_status; */

/*
 * if (custom_strcmp(command, "exit") == 0)
 * {
 * exit(0);
 * }
 *if (custom_strncmp(command, "exit ", 5) == 0)
 {
 * Extract the exit status argument *
 * exit_status = command +   5;
 * status = custom_atoi(exit_status);
 *
 * Exit the shell with the provided status
 * exit(status);
 *
 * return (-1);}
 */
if (custom_strcmp(args[0], "exit") == 0)
{
return (execute_exit(args));
}

/* Nullify the line after '#' character */
nullify_after_comment(command);

if (command[0] == '\0')
{
return (0);
}

null_after_comment(command, custom_strlen(command));
if (command[0] == '\0')
{
	return (0);
}

if (custom_strncmp(command, "/bin/echo #", 11) == 0)
    {
        write(STDOUT_FILENO, "\n", 1);
        return (0);
    }

if (custom_strncmp(command, "echo #", 6) == 0)
{
write(STDOUT_FILENO, "\n", 1);
return (0);
}


if (command[0] == '/')
{
pid = fork();
if (pid == -1)
{
perror("fork");
return (1);
}
else if (pid == 0)
{
execve(command, args, environ);
perror("Absolute path");
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
}
}
else
{
if (!command_exists(command))
{
perror("Command");
return (1);
}
command_path = resolve_command_path(command);
if (command_path == NULL)
{
perror("Command");
return (1);
}
pid = fork();
if (pid == -1)
{
perror("fork");
free(command_path);
return (1);
}
else if (pid == 0)
{
execve(command_path, args, environ);
perror("execve");
free(command_path);
exit(EXIT_FAILURE);
}
else
{
wait(&status);
free(command_path);
}
}

return (-1);
}
