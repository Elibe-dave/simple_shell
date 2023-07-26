#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "command_utils.h"
#include "custom_string.h"
#include <string.h>
#include <stddef.h>

/**
* custom_strchr - Locate character in string
* @str: The string to search
* @c: The character to find
*
* Return: Pointer to the first occurrence of the character in the string,
*         or NULL if the character is not found
*/
char *custom_strchr(const char *str, int c)
{
while (*str != '\0')
{
if (*str == c)
return (char *)str;
str++;
}
return (NULL);
}

/**
* nullify_after_comment - Nullify the portion of the string after a comment
* @str: The string to modify
*
* Description:
*   This function finds the occurrence of '#' character in the string and
*   nullifies the portion of the string after the '#' character, effectively
*   removing the comment.
*/
void nullify_after_comment(char *str)
{
char *comment_pos;

comment_pos = custom_strchr(str, '#');

if (comment_pos != NULL)
*comment_pos = '\0';
}
