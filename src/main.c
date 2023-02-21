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

void func_func(int count, char * buffer,
    size_t size_buffer, char const *current_path)
{
    bypass_first_lap(count);
    current_path = getcwd(buffer, size_buffer);
    display_line_shell(current_path);
    error_handling_getline(buffer, size_buffer);
    end_of_buffer(buffer);
}

void func_command(char **args, char **env)
{
    exit_command(args);
    cd_command(args, env);
    char *existing_path = check_existing_path(args);
    path_loop(existing_path, env, args);
}

int main(int ac, char **av, char **env)
{
    size_t size_buffer = 100;
    char *buffer = malloc(sizeof(char) * (size_buffer));
    char const *current_path;
    int count = 0;

    error_handling(ac);
    while (1) {
        func_func(count, buffer, size_buffer, current_path);
        char **args = malloc(sizeof(char*) * size_buffer);
        error_handling_args(args);
        args = my_str_to_word_array(buffer);
        if (args == NULL || args[0] == NULL) {
            free(args);
            continue;
        }
        func_command(args, env);
        free(args);
        count ++;
    }
    free(buffer); return 0;
}
