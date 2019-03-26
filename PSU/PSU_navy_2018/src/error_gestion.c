/*
** EPITECH PROJECT, 2019
** navy.c
** File description:
** error gestion for the navy
*/

#include <stdio.h>
#include "my.h"

char *init_string(char *str, int nb)
{
    int i = 0;

    while (i < nb) {
        str[i] = 0;
        i++;
    }
    return (str);
}

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid:  only for he 2nd player.");
    my_putstr("  pid of the first player\n");
    my_putstr("     navy_positions:  file representing the positions ");
    my_putstr("of the ships.\n");
}

int check_line_lenght(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            count = -1;
        }
        count++;
        i++;
    }
    if (count > 7)
        return (84);
    return (0);
}

int check_file_endchar(char *buf)
{
    int count = 0;
    int i = 0;

    if (buf[31] != '\0')
        return (84);
    while (buf[i] != '\0') {
        if (buf[i] == '\n')
            count++;
        i++;
    }
    if (count == 3)
        return (check_line_lenght(buf));
    else
        return (84);
}

int check_pos_file(char *file)
{
    int fd = 0;
    char *buf = NULL;

    fd = open(file, O_RDONLY);
    buf = malloc(sizeof(char) * 32);
    buf = init_string(buf, 32);
    read (fd, buf, 32);
    if (check_file_endchar(buf) == 84) {
        free(buf);
        return (84);
    }
    free(buf);
    return (0);
}