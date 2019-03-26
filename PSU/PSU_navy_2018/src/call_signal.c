/*
** EPITECH PROJECT, 2019
** call_signal.c
** File description:
** call the signal
*/

#include "../include/my.h"

int check_hit()
{
    char check = 'a';

    signal(SIGUSR1, first_sig);
    signal(SIGUSR2, second_sig);
    pause();
    check = set_signal_value(2);
    if (check == '0')
        return (0);
    return (1);
}

void send_hit(int pid, int i)
{
    if (i == 1)
        kill(pid, SIGUSR2);
    else
        kill(pid, SIGUSR1);
    usleep(1500);
}

void first_sig(int andi)
{
    int nb = 1;

    set_signal_value(nb);
}

void second_sig(int andi)
{
    int nb = 0;

    set_signal_value(nb);
}

void sig(int i, int pi, int j)
{
    char *str = NULL;

    str = get_base(j, 32);
    for (; i <= 32 ; i++) {
        if (str[i] == '0')
            kill(pi, SIGUSR1);
        if (str[i] == '1')
            kill(pi, SIGUSR2);
        usleep(1500);
    }
}
