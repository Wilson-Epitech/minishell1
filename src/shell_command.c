/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** shell_command
*/

#include "../includes/lib.h"

char **shell_command(char **args, char **env, char *current_path_save)
{
    char *existing_path = NULL;
    char **new_env = clone_env(env);
    exit_command(args);
    if (args[2] != NULL && my_strcmp(args[0], "setenv") == 0)
        setenv_command(args, new_env);
    if (my_strcmp(args[0], "unsetenv") == 0)
        unsetenv_command(args, new_env);
    if (args[2] == NULL && my_strcmp(args[0], "setenv") == 0)
        setenv_command_one_arg(args, env);
    cd_command(args, env, current_path_save);
    existing_path = check_existing_path(args);
    path_loop(existing_path, env, args);
    return env;
}
