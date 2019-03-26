/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "../../include/my.h"

int	my_get_nbr(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] == '\0' || str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = sign * -1;
        i = i + 1;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        result = result * 10;
        result = result + str[i] - 48;
        i = i + 1;
    }
    return (result * sign);
}