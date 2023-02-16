/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** get_path
*/

#include "../includes/lib.h"

char *get_env_line_path(char **env, char *path_value, char *path)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(path, env[i], my_strlen(path)) == 0) {
            path_value = env[i] + my_strlen(path);
            break;
        }
    }
    return path_value;
}

char *get_full_path(char *path_value, char *full_path, char *slash, char **args)
{
    if (path_value != NULL) {
        char *dir = strtok(path_value, ":");
        while (dir != NULL) {
            my_strcpy(full_path, dir);
            my_strcat(full_path, slash);
            my_strcat(full_path, args[0]);
            my_putstr(full_path);
            my_putchar('\n');
            dir = strtok(NULL, ":");
        }
    }
    return full_path;
}

char *get_path(char **env, char **args)
{
    char *path = "PATH=";
    char *slash = "/";
    char *path_value = NULL;
    char *full_path = malloc(sizeof(char) *
        (my_strlen(path) + my_strlen(args[0]) + 1));

    error_handling_fullpath(full_path);
    path_value = get_env_line_path(env, path_value, path);
    full_path = get_full_path(path_value, full_path, slash, args);
    return full_path;
}
