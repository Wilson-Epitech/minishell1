/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** main
*/

#include "../includes/lib.h"
#include <string.h>

int exec_command(char *path, char **tmp, char **env)
{
    pid_t pid = fork();
    if (pid == -1) {
        exit(84);
    }
    if (pid == 0) {
        execve(path, tmp, env);
        exit(84);
    } else {
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            exit(84);
        }
    }
    return 0;
}

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
        args = my_str_to_word_array(buffer);
        if (args == NULL || args[0] == NULL) {
            free(args);
            continue;
        }
        char *full_path = malloc(sizeof(char) * (my_strlen(path) + my_strlen(args[0]) + 1));
        error_handling_fullpath(full_path);
        strcpy(full_path, path);
        strcat(full_path, args[0]);
        int status = exec_command(full_path, args, env);
        free(args);
    }
    free(buffer);
    return 0;
}
