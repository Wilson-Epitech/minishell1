/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** main
*/

#include "../includes/lib.h"

int main(int ac, char **av, char **env)
{
    error_handling(ac);
    size_t size_buffer = 100;
    char *path = "/bin/";
    char *buffer = malloc(sizeof(char *) * (size_buffer));
    while (1) {
        my_putstr("\033[31m/$\033[0m");
        error_handling_getline(buffer, size_buffer);
        end_of_buffer(buffer);
        char **args = malloc(sizeof(char*) * 10);
        error_handling_args(args);
        args = my_str_to_word_array_space(buffer);
        if (args == NULL || args[0] == NULL) {
            free(args);
            continue;
        }
        char *full_path = get_path(env, args);
        printf("full path ici : %s\n", full_path);
        int status = exec_command(full_path, args, env);
        free(args);
    }
    free(buffer);
    return 0;
}
