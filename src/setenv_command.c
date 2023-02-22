/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** setenv_command
*/

#include "../includes/lib.h"

int setenv_command(char **args, char **env)
{
    if (strcmp(args[0], "setenv") == 0) {
        if (args[1] != NULL && args[2] != NULL) {
            setenv(args[1], args[2], 1);
        } else {
            my_putstr("Error: incorrect arguments\n");
        }
    }
    return 1;
}
