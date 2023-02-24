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
    if (args[1] == NULL && my_strcmp(args[0], "setenv") == 0) {
        print_env(env);
    }
    if (args[2] == NULL && my_strcmp(args[0], "setenv") == 0) {
        exit(84);
    }
    if (args[1] == NULL && my_strcmp(args[0], "unsetenv") == 0) {
        exit(84);
    }
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
        print_env(env);
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

char **unsetenv_command(char **args, char **env)
{
    error_handling_setenv_unsetenv(args, env);
    env = environ;
    char *arg1 = args[1];
    int i = 0;
    while (env[i] != NULL) {
        if (my_strcmp(env[i], arg1) == 0) {
            int j = i;
            while (env[j + 1] != NULL) {
                env[j] = env[j + 1];
                j++;
            }
            env[j] = NULL;
            return 0;
        }
        i++;
    }
    return env;
}
