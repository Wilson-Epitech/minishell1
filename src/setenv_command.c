/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** setenv_command
*/

#include "../includes/lib.h"

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        printf("%s\n", env[i]);
    }
}

int error_handling_setenv_unsetenv(char **args, char **env)
{
    return 0;
}

char **setenv_command(char **args, char **env)
{
    print_env(env);
    return env;
}

int unsetenv_command(char **args, char **env)
{
    print_env(env);
    return 1;
}