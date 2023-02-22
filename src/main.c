/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** main
*/

#include "../includes/lib.h"

int path_loop(char *existing_path, char **env, char **args)
{
    if (existing_path == NULL) {
        char *full_path = get_path(env, args);
        int status = exec_command(full_path, args, env);
    } else {
        int status = exec_command(existing_path, args, env);
    }
}

int bypass_first_lap(int count)
{
    if (count != 0) {
        my_putchar('\n');
    }
}

int main(int ac, char **av, char **env)
{
    size_t size_buffer = 100;
    char *buffer = malloc(sizeof(char) * (size_buffer));
    int count = 0;

    error_handling(ac);
    while (1) {
        bypass_first_lap(count);
        char *current_path_save = handling_path(buffer, size_buffer, env);
        error_handling_getline(buffer, size_buffer);
        char **args = malloc_buffer(args, buffer, size_buffer);
        if (args == NULL || args[0] == NULL) {
            free(args);
            continue;
        }
        shell_command(args, env, current_path_save);
        free(args);
        count ++;
    }
    free(buffer);
    return 0;
}
