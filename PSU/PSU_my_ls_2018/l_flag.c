/*
** EPITECH PROJECT, 2019
** l_flag.c
** File description:
** l_flag.c
*/

#include "include/my.h"

void print_permissions(struct stat sb)
{
    my_printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
    my_printf((sb.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((sb.st_mode & S_IWUSR) ? "w" : "-");
    my_printf((sb.st_mode & S_IXUSR) ? "x" : "-");
    my_printf((sb.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((sb.st_mode & S_IWGRP) ? "w" : "-");
    my_printf((sb.st_mode & S_IXGRP) ? "x" : "-");
    my_printf((sb.st_mode & S_IROTH) ? "r" : "-");
    my_printf((sb.st_mode & S_IWOTH) ? "w" : "-");
    my_printf((sb.st_mode & S_IXOTH) ? "x. " : "-. ");
}

char *set_time_format(char *temp)
{
    char *right_time = malloc(sizeof(char) * 12);
    int i = 4;
    int j = 0;

    while (i < 16) {
        right_time[j] = temp[i];
        i++;
        j++;
    }
    right_time[j] = '\0';
    return (right_time);
}

void print_lflag(struct stat sb)
{
    struct passwd *pws;
    struct group *grp;
    char *temp = NULL;
    char *right_time = NULL;

    pws = getpwuid(sb.st_uid);
    grp = getgrgid(sb.st_gid);
    temp = ctime(&sb.st_mtime);
    right_time = set_time_format(temp);
    print_permissions(sb);
    my_printf("%d ", sb.st_nlink);
    my_printf("%s ", pws->pw_name);
    my_printf("%s ", grp->gr_name);
    my_printf("%d ", sb.st_size);
    my_printf("%s ", right_time);
}

void count_blocks(char *argv)
{
    DIR * dir;
    struct dirent *dirst;
    struct stat sb;
    int blocks = 0;
    
    dir = opendir(argv);
    while ((dirst = readdir(dir)) != NULL) {
        stat(dirst->d_name, &sb);
        if (dirst->d_name[0] != '.')
            blocks = blocks + sb.st_blocks;
    }
    my_printf("total %d\n", blocks / 2);
    closedir(dir);
}

void init_lflag(char *argv)
{
    DIR * dir;
    struct dirent *dirst;
    struct stat sb;

    check_ls_error(argv, sb);
    stat(argv, &sb);
    if (S_ISDIR (sb.st_mode)) {
        count_blocks(argv);
        if ((sb.st_mode & S_IRUSR) && (sb.st_mode & S_IRGRP) &&
             (sb.st_mode & S_IROTH)) {
            dir = opendir(argv);
            while ((dirst = readdir(dir)) != NULL) {
                if (dirst->d_name[0] != '.') {
                    stat(dirst->d_name, &sb);
                    print_lflag(sb);
                    my_printf("%s\n", dirst->d_name);
                }
            }
            closedir(dir);
        }
        else
            my_putstr("ls: cannot open directory '': permission denied\n");
    }
    else if (stat(argv, &sb) == 0) {
        print_lflag(sb);
        my_printf("%s\n", argv);
    }
}