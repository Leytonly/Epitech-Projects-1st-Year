/*
** EPITECH PROJECT, 2018
** my_putnbr_ubinary.c
** File description:
** my_putnbr_ubinary.c
*/
#include "../../include/my.h"
int my_putnbr_ubinary(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        nb = 4294967296 - nb;
        my_putnbr_base(nb, "01");
    }

    else if (nb > 0)
        my_putnbr_base(nb, "01");
}