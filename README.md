Simple Shell is a basic shell implementation written in C. It provides a basic command-line interface that allows you to execute commands, handle built-in commands, and manage environment variables.

## Features
The custom shell implementation provides the following features:

Interactive Mode: The shell can be used interactively by displaying a prompt and accepting user commands.

- Command execution: The shell can execute external commands by forking a child process and using the `execve` system call. The shell is capable of executing external commands either by providing the full absolute path or by searching for the command in the directories listed in the PATH environment variable. 

- Built-in commands: The shell supports a few built-in commands, including `exit` to exit the shell and `env` to print the environment variables.

- PATH resolution: The shell can resolve command paths using the PATH environment variable, allowing you to execute commands by their names without specifying the full path.

- Input handling: The shell can read user input using the `getline` function, allowing you to type commands and arguments interactively.

- Environment variables: The shell can access and manipulate environment variables using the `environ` variable, providing information about the current environment.

List of allowed functions and system calls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

## Functions Not Allowed

Due to certain limitations or requirements, the following functions are not allowed to be used directly in this shell implementation:

- `getenv`: The `getenv` function is not allowed for retrieving environment variables. Instead, the shell accesses environment variables through the `environ` variable.
- `strlen`: The `strlen` function is not allowed for string length calculation. Custom implementations or alternative approaches are used instead.
- `strcmp`: The `strcmp` function is not allowed for string comparison. Custom implementations or alternative approaches are used instead.
- `snprintf`: The `snprintf` function is not allowed for string formatting. Custom implementations or alternative approaches are used instead.

Custom Functions
In order to work within the constraints of not using certain functions, the following custom functions have been implemented:

custom_strdup: This function duplicates a string by manually allocating memory and copying the characters one by one.

custom_strcat: This function concatenates two strings by manually allocating memory and copying the characters from both strings.

custom_getenv: This function retrieves the value of an environment variable by iterating through the environ variable and searching for a matching variable name.

These custom functions provide alternative implementations for the restricted functions and ensure the functionality of the shell.

Error Handling
The shell implementation includes error handling using the perror function. When an error occurs, such as a failed system call or memory allocation, the corresponding error message is displayed using perror to provide meaningful information about the error and aid in debugging.

Memory Management
Proper memory management practices are followed in the shell implementation. Memory is allocated dynamically when needed and freed when it is no longer required. Memory leaks are avoided by freeing dynamically allocated memory before exiting the shell or when it is no longer needed.

## Getting Started
To build and run the shell, follow these steps:

1. Clone the repository: `git clone https://github.com/Elibe-dave/simple_shell.git`
2. Change to the project directory: `cd simple_shell`
3. Compile the source code: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
4. Run the shell: `./hsh`

## Usage

Once the shell is running, you can type commands and execute them. The shell supports basic command execution and a few built-in commands:

- External commands: You can execute external commands by typing their names (e.g., `ls`, `cat`, etc.). The shell will search for the command in the directories listed in the PATH environment variable.
- Built-in commands: The shell supports the following built-in commands:
  - `exit`: Exits the shell.
  - `env`: Prints the environment variables. 

