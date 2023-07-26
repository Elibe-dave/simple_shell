#include <stdio.h>
#include <stdlib.h>
#include "command_utils.h"
#include "custom_string.h"

/**
 * execute_exit - Executes the "exit" command to terminate the shell.
 * @args: List of arguments, where args[0] is "exit" command and args[1] (if present) is the exit status.
 *
 * Return: None.
 */

int execute_exit(char **args)
{
int exit_status;
if (args[1] != NULL)
{
exit_status = custom_atoi(args[1]);
exit(exit_status);
} else
{
exit(EXIT_SUCCESS);
}
}
