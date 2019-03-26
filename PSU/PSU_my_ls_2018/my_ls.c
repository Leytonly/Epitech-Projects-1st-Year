/*
** EPITECH PROJECT, 2019
** my_ls.c
** File description:
** my_ls.c
*/

#include "include/my.h"

void print_ls_only(int argc, char *argv)
{
    DIR *dir;
    struct dirent *dirst;
    struct stat sb;

    check_ls_error(argv, sb);
    stat(argv, &sb);
    if (S_ISDIR (sb.st_mode)) {
        dir = opendir(argv);
        if (argv != "." && argc >= 3) {
            my_printf("%s:\n", argv);
        }
        while ((dirst = readdir(dir)) != NULL) {
            if (dirst->d_name[0] != '.')
                my_printf("%s\n", dirst->d_name);
        }
        closedir(dir);
    }
    else if (stat(argv, &sb) == 0)
        my_printf("%s\n", argv);
}

void init_ls(int argc, char *argv, int total)
{
    if (total == 0)
        print_ls_only(argc, argv);
    if (total == 2)
        init_lflag(argv);
}

int check_ls_error(char *argv, struct stat sb)
{
    if (stat(argv, &sb) != 0) {
        my_printf("ls: cannot access '%s': No such file or directory\n",
                  argv);
    }
    return (84);
}

void check_parameters(int argc, char **argv)
{
    flags_t *flags = malloc(sizeof(flags_t));
    int i = 1;
    int j = 1;
    int count = 0;

    while (i < argc) {
        if (argv[i][0] == '-') {
            flags = check_ls_flag(argv[i], flags);
            count++;
        }
        i++;
    }
    if (argc - count > 1) {
        while (j < argc) {
            if (argv[j][0] != '-')
                init_ls(argc, argv[j], flags->total);
            j++;
        }
    }
    else
        init_ls(argc, ".", flags->total);
}

flags_t *check_ls_flag(char *argv, flags_t *flags)
{
    int i = 0;

    while (argv[i] != '\0') {
        if (argv[i] == 'l')
            flags->l_flag = 2;
        if (argv[i] == 'r')
            flags->r_flag = 3;
        if (argv[i] == 'R')
            flags->R_flag = 5;
        if (argv[i] == 'd')
            flags->d_flag = 7;
        if (argv[i] == 't')
            flags->t_flag = 13;
        i++;
    }
    flags->total = flags->l_flag + flags->d_flag + flags->R_flag;
    flags->total = flags->total + flags->r_flag + flags->t_flag;
    return (flags);
}
