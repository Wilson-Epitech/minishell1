/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** setenv_command
*/

#include "../includes/lib.h"

int setenv_command(char **args, char **env)
{
    if (my_strcmp(args[0], "setenv") == 0) {
        return 1;
    }
    return 0;
}
