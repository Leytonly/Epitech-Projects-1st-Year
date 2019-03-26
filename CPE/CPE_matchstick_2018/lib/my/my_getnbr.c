/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int neg = 0;
    int i = 0;

    if (str[0] == '-')
        neg = 1;

    while (str[i] != '\0') {
        if (str[i] > 47 && str[i] < 58)
            nb = nb * 10 + (str[i]) - 48;
        i++;
    }

    if (neg == 1)
        nb = -nb;
    return (nb);
}