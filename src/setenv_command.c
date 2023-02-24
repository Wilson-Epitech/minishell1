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
        my_putstr(env[i]);
    }
}

int setenv_command(char **args, char **env)
{
    print_env(env);
    return 0;
}

int unsetenv_command(char **args, char **env)
{
    print_env(env);
    return 1;
}