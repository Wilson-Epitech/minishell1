/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** setenv_command
*/

#include "../includes/lib.h"

extern char **environ;

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}

int error_handling_setenv_unsetenv(char **args, char **env)
{
    if (args[2] != NULL && args[1] == NULL
        && my_strcmp(args[0], "setenv") == 0) {
        print_env(env);
    }
    if (args[1] == NULL && my_strcmp(args[0], "unsetenv") == 0) {
        exit(84);
    }
    return 0;
}

char **setenv_command_one_arg(char **args, char **env)
{
    env = environ;
    char *arg1 = args[1];
    char *str = malloc(sizeof(char) * (my_strlen(arg1) + 3));
    str = my_strcat(arg1, "=");
    int i = 0;

    while (env[i] != NULL) {
        if (my_strcmp(env[i], arg1) == 0) {
            env[i] = str;
            return 0;
        }
        i++;
    }
    env[i] = str;
    env[i + 1] = NULL;
    return env;
}

int check_before_unsetenv(char **args, char **env)
{
    env = environ;
    size_t len = my_strlen(args[1]);
    char *path = malloc(sizeof(char) * (len + 2));
    path = my_strcat(path, args[1]);
    path = my_strcat(path, "=");

    char *path_value = get_env_line_path(env, NULL, path);
    if (path_value == NULL) {
        free(path);
        return -1;
    }
    free(path);
    return 0;
}

char **setenv_command(char **args, char **env)
{
    error_handling_setenv_unsetenv(args, env);
    env = environ;
    char *arg1 = args[1]; char *arg2 = args[2];
    char *str = malloc(sizeof(char) * (my_strlen(arg1) + my_strlen(arg2) + 2));
    str = my_strcat(arg1, "="); str = my_strcat(str, arg2);
    int i = 0;

    if (my_strcmp(arg1, "env") == 0) {
        print_env(environ);
    }
    while (env[i] != NULL) {
        if (my_strcmp(env[i], arg1) == 0) {
            env[i] = str;
            return 0;
        }
        i++;
    }
    env[i] = str;
    env[i + 1] = NULL;
    return env;
}

char *get_setenv_line_path(char **env, char *path_value, char *path)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(path, env[i], my_strlen(path)) == 0) {
            path_value = my_strdup(env[i]);
            break;
        }
    }
    return path_value;
}

char **unsetenv_command(char **args, char **env)
{
    env = environ;
    int state = check_before_unsetenv(args, env);
    if (state != -1) {
        char *arg1 = args[1];
        char *path = my_strcat(arg1, "=");
        char *path_value = NULL;
        path_value = get_setenv_line_path(env, path_value, path);

        int i = 0;
        while (env[i] != NULL) {
            if (my_strcmp(env[i], path_value) == 0) {
                int j = i;
                while (env[j] != NULL) {
                    env[j] = NULL;
                    j++;
                }
                env[j - 1] = NULL;
                return env;
            }
            i++;
        }
        return env;
    }
}
