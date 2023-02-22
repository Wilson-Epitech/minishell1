/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** cd_command
*/

#include "../includes/lib.h"

char *get_env_line_path(char **env, char *path_value, char *path);

void cd_chdir(int nb_args, char *path_home, char **args, char *path_last_lap)
{
    if ((nb_args == 1) || (nb_args == 2 && my_strcmp(args[1], "~") == 0)) {
        chdir(path_home);
    } else if (my_strcmp(args[1], "-") == 0) {
        chdir(path_last_lap);
    } else {
        chdir(args[1]);
    }
}

int cd_command(char **args, char **env, char const *current_path)
{
    char *path = "HOME=";
    char *path_home = NULL;
    static char *path_last_lap = NULL;
    char *path_current_lap = my_strdup(current_path);
    int nb_args = 0;

    path_home = get_env_line_path(env, path_home, path);
    for (int i = 0; args[i] != NULL; i++) {
        nb_args++;
    }
    if (my_strncmp(args[0], "cd", 2) == 0) {
        if (path_last_lap == NULL) {
            path_last_lap = my_strdup(path_current_lap);
        }
        cd_chdir(nb_args, path_home, args, path_last_lap);
        path_last_lap = my_strdup(path_current_lap);
        path_current_lap = my_strdup(getcwd(NULL, 0));
    }
    return 0;
}
