/*
** MINISHELL1 PROJECT, 2023
** minishell1
** File description:
** unit_test_backup
*/

#include "../includes/lib.h"

Test (exit_command, should_exit) {
    char *args[] = {"exit", NULL};
    cr_assert_eq(exit_command(args), 0);
}

Test (check_existing_path, should_return_existing_path) {
    char *args[] = {"/bin/ls", NULL};
    cr_assert_str_eq(check_existing_path(args), "/bin/ls");
}

Test (check_existing_path, should_return_null) {
    char *args[] = {"ls", NULL};
    cr_assert_null(check_existing_path(args));
}

Test (error_handling, ac_one) {
    int ac = 1;
    cr_assert_eq(error_handling(ac), 0, "Error: ac_one");
}

Test (end_of_buffer, remove_newline) {
    char buffer[10] = "hello\n";
    cr_assert_eq(end_of_buffer(buffer), 0, "Error: remove_newline");
    cr_assert_str_eq(buffer, "hello", "Error: remove_newline");
}

Test (end_of_buffer, no_newline) {
    char buffer[10] = "hello";
    cr_assert_eq(end_of_buffer(buffer), 0, "Error: no_newline");
    cr_assert_str_eq(buffer, "hello", "Error: no_newline");
}

Test (error_handling_args, args_not_null) {
    char *args[2] = {"ls", NULL};
    cr_assert_eq(error_handling_args(args), 0, "Error: args_not_null");
}

Test (error_handling_fullpath, full_path_null) {
    char *args[2] = {"ls", NULL};
    cr_assert_eq(error_handling_fullpath(NULL, args),
        0, "Error: full_path_null");
}

Test (error_handling_fullpath, full_path_not_null) {
    char *args[2] = {"ls", NULL};
    char *full_path = "/bin/ls";
    cr_assert_eq(error_handling_fullpath(full_path, args),
        0, "Error: full_path_not_null");
}

Test (error_handling_fullpath, cd) {
    char *args[2] = {"cd", NULL};
    char *full_path = NULL;
    cr_assert_eq(error_handling_fullpath(full_path, args), 0, "Error: cd");
}

Test (error_handling_fullpath, setenv) {
    char *args[2] = {"setenv", NULL};
    char *full_path = NULL;
    cr_assert_eq(error_handling_fullpath(full_path, args),
        0, "Error: setenv");
}

Test (error_handling_fullpath, unsetenv) {
    char *args[2] = {"unsetenv", NULL};
    char *full_path = NULL;
    cr_assert_eq(error_handling_fullpath(full_path, args),
        0, "Error: unsetenv");
}

Test (bypass_first_lap, count_non_zero) {
    cr_redirect_stdout();
    bypass_first_lap(1);
    cr_assert_stdout_eq_str("\n");
}

Test (display_line_shell, prints_correct_line_shell) {
    char *str = "\033[34m┌──(\033[31muser㉿\033[34m)"
        "-[/home/user]\033[0m\n\033[34m└─$ \033[0m";
    char *current_path = "/home/user";
    char *env[] = {"USER=user", NULL};
    cr_redirect_stdout();
    display_line_shell(current_path, env);
    cr_assert_stdout_eq_str(str);
}

Test (my_strdup, copies_string_correctly) {
    char *src = "Hello, World!";
    char *copy = my_strdup(src);
    cr_assert_str_eq(copy, src);

    free(copy);
}

Test (malloc_buffer, returns_correct_args) {
    char **args = NULL;
    char buffer[] = "ls -la";
    size_t size_buffer = sizeof(buffer);
    args = malloc_buffer(args, buffer, size_buffer);

    cr_assert_str_eq(args[0], "ls");
    cr_assert_str_eq(args[1], "-la");
    cr_assert_null(args[2]);

    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(args);
}

Test (clone_env, basic_test) {
    char *env[] = {"VAR1=value1", "VAR2=value2", NULL};
    char **new_env = clone_env(env);
    cr_assert_str_eq(new_env[0], "VAR1=value1");
    cr_assert_str_eq(new_env[1], "VAR2=value2");
    cr_assert_null(new_env[2]);
    free(new_env[0]);
    free(new_env[1]);
    free(new_env);
}

Test (shell_command, cd_command) {
    char *env[] = {"PWD=/", NULL};
    char *args[] = {"cd", "/", NULL};
    char *current_path_save = "/";
    char **new_env = shell_command(args, env, current_path_save);
    cr_assert_str_eq(new_env[0], "PWD=/");
    cr_assert_null(new_env[1]);
}

Test (shell_command, exit_command) {
    char *env[] = {"VAR1=value1", "VAR2=value2", NULL};
    char *args[] = {"exit", NULL};
    char *current_path_save = "/";
    char **new_env = shell_command(args, env, current_path_save);
    cr_assert_null(new_env);
}

Test (cd_chdir, cd_home_directory) {
    char *path_home = "/home/wilson";
    char *args[] = {"cd", NULL};
    char *path_last_lap = "/home/wilson/B1";
    cd_chdir(1, path_home, args, path_last_lap);
    char *result = getcwd(NULL, 0);
    cr_assert_str_eq(result, path_home);
}

Test (cd_chdir, cd_previous_directory) {
    char *path_home = "/home/wilson";
    char *args[] = {"cd", "-", NULL};
    char *path_last_lap = "/home/wilson/B1";
    cd_chdir(2, path_home, args, path_last_lap);
    char *result = getcwd(NULL, 0);
    cr_assert_str_eq(result, path_last_lap);
}

Test (error_handling_cd, cd_no_arguments) {
    char *args[] = {"cd", NULL};
    int result = error_handling_cd(args);
    cr_assert_eq(result, 0);
}

Test (error_handling_cd, cd_directory_not_found) {
    char *args[] = {"cd", "nonexistent_directory", NULL};
    int result = error_handling_cd(args);
    cr_assert_eq(result, 0);
}

Test (error_handling_cd, cd_file_not_directory) {
    char *args[] = {"cd", "file.txt", NULL};
    int result = error_handling_cd(args);
    cr_assert_eq(result, 0);
}

Test (error_handling_cd, cd_too_many_arguments) {
    char *args[] = {"cd", "directory", "extra_argument", NULL};
    int result = error_handling_cd(args);
    cr_assert_eq(result, 0);
}

Test (check_existing_path, existing_path) {
    char *args[] = {"/bin/ls", "-l", NULL};
    char *result = check_existing_path(args);
    cr_assert_not_null(result);
}

Test (check_existing_path, non_existing_path) {
    char *args[] = {"non_existing_command", NULL};
    char *result = check_existing_path(args);
    cr_assert_null(result);
}

Test (get_path, existing_path) {
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    char *args[] = {"ls", "-l", NULL};
    char *result = get_path(env, args);
    cr_assert_str_eq(result, "/bin/ls");
}

Test (exec_command, ls) {
    char *env[] = {"PATH=/bin:/usr/bin", NULL};
    char *args[] = {"ls", "-l", NULL};
    exec_command("/bin/ls", args, env);
    cr_assert(1);
}
