/*
** EPITECH PROJECT, 2018
** my_put_nbr_unsigned.c
** File description:
** my_put_nbr_unsigned.c
*/

#include "../../include/my.h"

int my_put_nbr_unsigned(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        nb = (4294967296) - nb;
    }

    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else
    my_putchar(nb + '0');
}