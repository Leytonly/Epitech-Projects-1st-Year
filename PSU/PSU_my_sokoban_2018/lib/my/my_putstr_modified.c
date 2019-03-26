/*
** EPITECH PROJECT, 2018
** my_putstr_modified.c
** File description:
** my_putstr_modified.c
*/

#include "../../include/my.h"

int my_putstr_modified(char const *str)
{
    int i = 0;
    int j = 0;
    int str_asc;
    char *finalstr;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            str_asc = (int)str[i];
            my_putchar('\\');
            my_put_nbr(str_asc);
        }
        else if (str[i] > 32 || str[i] <= 127) {
            my_putchar(str[i]);
        }
        i = i + 1;
    }
    return (0);
}
