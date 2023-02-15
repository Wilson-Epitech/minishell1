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
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include "struct.h"
void my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_word_array(char const *str);
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
int error_handling_fullpath(char *full_path);
#endif /* !LIB_H_ */
