/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/lib.h"

void redirect_all_std (void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(exit_command, should_exit, .init=redirect_all_std, .timeout=1.0) {
    char *args[] = {"exit", NULL};
    cr_assert_eq(exit_command(args), 0);
}
