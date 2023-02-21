/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** cd_command
*/

#include "../includes/lib.h"

char *get_env_line_path(char **env, char *path_value, char *path);

int cd_command(char **args, char **env)
{
    char *path = "HOME=";
    char *path_home = NULL;
    char *cd = "cd";

    path_home = get_env_line_path(env, path_home, path);
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strncmp(args[0], cd, 2) == 0) {
            chdir(path_home);
        }
    }
    return 0;
}
