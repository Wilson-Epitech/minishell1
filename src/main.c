/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** main
*/

#include "../includes/lib.h"

int exit_command(char **args)
{
    char *str = "exit";
    if (my_strcmp(str, args[0]) == 0) {
        exit(0);
    }
    return 0;
}

char *check_existing_path(char **args)
{
    char *existing_path;
    for (int i = 0; args[0][i] != '\0'; i++) {
        if (args[0][i] == '/' && access(args[0], X_OK) == 0) {
            return args[0];
        }
        if (args[0][i] == '/' && access(args[0], X_OK) == -1) {
            return NULL;
        }
    }
    return NULL;
}

int path_loop(char *existing_path, char **env, char **args)
{
    if (existing_path == NULL) {
        char *full_path = get_path(env, args);
        int status = exec_command(full_path, args, env);
    } else {
        int status = exec_command(existing_path, args, env);
    }
}

int main(int ac, char **av, char **env)
{
    error_handling(ac);
    size_t size_buffer = 100;
    char *buffer = malloc(sizeof(char) * (size_buffer));
    while (1) {
        my_putstr("\033[31m/$\033[0m");
        error_handling_getline(buffer, size_buffer);
        end_of_buffer(buffer);
        char **args = malloc(sizeof(char*) * size_buffer);
        error_handling_args(args);
        args = my_str_to_word_array_test(buffer);
        if (args == NULL || args[0] == NULL) {
            free(args);
            continue;
        }
        exit_command(args);
        char *existing_path = check_existing_path(args);
        path_loop(existing_path, env, args);
        free(args);
    }
    free(buffer);
    return 0;
}
