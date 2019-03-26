/*
** EPITECH PROJECT, 2018
** conv_dec_to_bin.c
** File description:
** convert a binary number into decimal
*/

#include "../../include/my.h"

int char_to_binstr(char *str)
{
    int nb = 0;
    int i = 0;
    int len = my_strlen(str);

    while (i < len) {
        nb = nb * 10;
        nb = nb + (str[i] - 48);
        i++;
    }
    return (nb);
}

int conv_bin_to_dec(char *str)
{
    int nb = char_to_binstr(str);
    int dec = 0;
    int base = 1;
    int rem = 0;

    while (nb > 0) {
        rem = nb % 10;
        dec = dec + rem * base;
        nb = nb / 10;
        base = base * 2;
    }
    return (dec);
}