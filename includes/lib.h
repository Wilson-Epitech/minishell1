/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include "struct.h"
void my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_word_array(char const *str);
char *my_strncpy(char *dest, char const *src, int size);
int my_strlen(char const *str);
counter_t init_struct(int value);
int check_status(int status);
int my_put_nbr(int nb);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int error_handling(int ac);
int error_handling_getline(char *buffer, size_t size_buffer);
int error_handling_args(char **args);
int end_of_buffer(char *buffer);
int error_handling_fullpath(char *full_path, char **args);
char *my_revstr(char *str);
char *get_path(char **env, char **args);
int exec_command(char *path, char **tmp, char **env);
char *my_strdup(char const *src);
int my_strncmp(char const *str1, char const *str2, int size);
int my_strcmp(char const *str1, char const *str2);
int path_loop(char *existing_path, char **env, char **args);
int exit_command(char **args);
char *check_existing_path(char **args);
int path_loop(char *existing_path, char **env, char **args);
int exit_command(char **args);
int cd_command(char **args, char **env, char const *current_path);
void display_line_shell(char const *current_path, char **env);
char *check_existing_path(char **args);
char *get_env_line_path(char **env, char *path_value, char *path);
char *get_log_name(char **env);
int setenv_command(char **args, char **env);
char **malloc_buffer(char **args, char *buffer, size_t size_buffer);
void shell_command(char **args, char **env, char *current_path_save);
char *handling_path(char *buffer, size_t size_buffer, char **env);
#endif /* !LIB_H_ */
