/*
** EPITECH PROJECT, 2018
** my_putnbr_base.c
** File description:
** my_putnbr_base.c
*/

#include "../../include/my.h"

int my_putnbr_base(int nb, char const *base)
{
    int base_len;

    base_len = my_strlen(base);

    if (nb / base_len)
        my_putnbr_base(nb / base_len, base);
    my_putchar(base[nb % base_len]);
}