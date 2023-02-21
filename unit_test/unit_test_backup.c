#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/lib.h"

Test(exit_command, should_exit) {
    char *args[] = {"exit", NULL};
    cr_assert_eq(exit_command(args), 0);
}

Test(exit_command, should_not_exit) {
    char *args[] = {"ls", NULL};
    cr_assert_eq(exit_command(args), -1);
}

Test(check_existing_path, should_return_existing_path) {
    char *args[] = {"/bin/ls", NULL};
    cr_assert_str_eq(check_existing_path(args), "/bin/ls");
}

Test(check_existing_path, should_return_null) {
    char *args[] = {"ls", NULL};
    cr_assert_null(check_existing_path(args));
}

Test(path_loop, should_return_success) {
    char *existing_path = "/bin/ls";
    char *env[] = {"PATH=/bin", NULL};
    char *args[] = {"ls", NULL};
    cr_assert_eq(path_loop(existing_path, env, args), 0);
}

Test(path_loop, should_return_failure) {
    char *existing_path = "/usr/bin/ls";
    char *env[] = {"PATH=/bin", NULL};
    char *args[] = {"ls", NULL};
    cr_assert_eq(path_loop(existing_path, env, args), -1);
}

