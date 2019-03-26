/*
** EPITECH PROJECT, 2019
** manage_signal
** File description:
** manage signal functions
*/

#include "../include/my.h"

char set_signal_value(int nb)
{
    static char i = '0';

    if (nb == 0)
        i = '1';
    else if (nb == 1)
        i = '0';
    return (i);
}

char *my_revstr(char *str)
{
    int nb = 0;
    int j = 0;
    char *tab = malloc(sizeof(str)+1);

    for (; str[nb] != '\0' ; nb++);
    for (nb = nb - 1 ; nb >= 0 ; nb--) {
        tab[j] = str[nb];
        j++;
    }
    return (tab);
}

char *get_base(int pi, int len)
{
    char *str = NULL;
    int end = len;
    int n = 0;
    int k = 0;

    str = malloc(sizeof(char *) + len + 1);
    for (; len >= 0 ; len--) {
        k = pi >> len;
        if (k & 1)
            str[len] = '1';
        else
            str[len] = '0';
    }
    str = my_revstr(str);
    return (str);
}

int get_three_arg(int i, char *pi)
{
    int j = getpid();

    my_putstr("my_pid:  ");
    my_put_nbr(j);
    my_putchar('\n');
    sig(i, my_get_nbr(pi), j);
    my_putstr("successfully connected\n\n");
    return (j);
}

int get_two_arg(int i)
{
    int t = 0;
    int j = getpid();
    char *tab = malloc((sizeof(char) * 32) + 1);

    my_putstr("my_pid:  ");
    my_put_nbr(j);
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n\n");
    for (; i <= 32; i++) {
        signal(SIGUSR1, first_sig);
        signal(SIGUSR2, second_sig);
        pause();
        tab[t] = set_signal_value(2);
        t++;
    }
    my_putstr("enemy connected\n\n");
    return (j);
}
