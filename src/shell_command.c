/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** shell_command
*/

#include "../includes/lib.h"

void shell_command(char **args, char **env, char *current_path_save)
{
    char *existing_path = NULL;

    exit_command(args);
    setenv_command(args, env);
    cd_command(args, env, current_path_save);
    existing_path = check_existing_path(args);
    path_loop(existing_path, env, args);
}
