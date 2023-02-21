/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** display_line_shell
*/

#include "../includes/lib.h"

void display_line_shell(char const *current_path)
{
    my_putstr("\033[34m [");
    my_putstr(current_path);
    my_putstr("]\033[0m");
    my_putchar('\n');
    my_putstr("\033[34m /$\033[0m");
}
