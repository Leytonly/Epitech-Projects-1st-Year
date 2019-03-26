/*
** EPITECH PROJECT, 2019
** error_gestion.c
** File description:
** error_gestion.c
*/

#include "my.h"

int check_params(char **argv)
{
    int count = 0;
    int i = 1;
    int j = 0;
    int sticks_pr = my_getnbr(argv[1]);

    while (i < 3) {
        while (argv[i][j] != '\0') {
            if ((argv[i][j] < 49) || (argv[i][j] > 57))
                count++;
            j++;
        }
        j = 0;
        i++;
    }
    if (sticks_pr < 1 || sticks_pr > 100) {
        return (0);
    }
    if (count != 0)
        return (0);
    return (0);
}

int check_input(char *str)
{
    int i = 0;
    int status = 0;

    while (str[i] != '\n') {
        if ((str[i]) > 57 || str[i] < 48)
            status = 84;
        i++;
    }
    if (status == 84)
        my_putstr("Error : invalid input (positive number expected)\n");
    return (status);
}