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
        printf("%s\n", env[i]);
    }
}

int error_handling_setenv_unsetenv(char **args)
{
    if (args[1] == NULL && my_strcmp(args[0], "setenv") == 0) {
        exit(84);
    }
    if (args[2] == NULL && my_strcmp(args[0], "setenv") == 0) {
        exit(84);
    }
    if (args[1] == NULL && my_strcmp(args[0], "unsetenv") == 0) {
        exit(84);
    }
    return 0;
}

int setenv_command(char **args, char **env)
{
    error_handling_setenv_unsetenv(args);

    char *arg1 = args[1];
    char *arg2 = args[2];
    char *str = malloc(sizeof(char) * (my_strlen(arg1) + my_strlen(arg2) + 2));
    str = my_strcat(arg1, "=");
    str = my_strcat(str, arg2);
    printf("str ici %s\n", str);

    int i = 0;
    while (env[i] != NULL) {
        if (my_strcmp(env[i], arg1) == 0) {
            env[i] = str;
            return 0;
        }
        i++;
    }
    printf("str la %s\n", str);
    env[i] = str;
    env[i + 1] = NULL;
    printf("OKOK\n");
    print_env(env);
    return 0;
}

int unsetenv_command(char **args, char **env)
{
    // error_handling_setenv_unsetenv(args);
    // char *arg1 = args[1];
    // int i = 0;
    // while (env[i] != NULL) {
    //     if (my_strcmp(env[i], arg1) == 0) {
    //         int j = i;
    //         while (env[j + 1] != NULL) {
    //             env[j] = env[j + 1];
    //             j++;
    //         }
    //         env[j] = NULL;
    //         return 0;
    //     }
    //     i++;
    // }
    print_env(env);
    return 1;
}