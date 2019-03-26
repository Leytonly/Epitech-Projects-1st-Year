/*
** EPITECH PROJECT, 2019
** matchstick.c
** File description:
** matchstick.c
*/

#include "my.h"

int calc_sticks(char *window)
{
    int i = 0;
    int count = 0;

    while (window[i] != '\0') {
        if (window[i] == '|')
            count++;
        i++;
    }
    return (count);
}

int count_sticks(char **window, int lines)
{
    int i = 0;
    int count = 0;

    while (i < lines) {
        count = count + calc_sticks(window[i + 1]);
        i++;
    }
    return (count);
}

void print_format(char **window, int lines)
{
    int i = 0;

    while (i < (lines + 2)) {
        my_putstr(window[i]);
        i++;
    }
}

void modif_matches_p(sticks_t *sticks)
{
    int len_str = my_strlen(sticks->window[sticks->line]);
    int count = sticks->stick_nbr;

    while (count > 0) {
        if (sticks->window[sticks->line][len_str] == '|') {
            sticks->window[sticks->line][len_str] = ' ';
            count--;
        }
        len_str--;
    }
}

int init_matchstick(char **argv)
{
    sticks_t *sticks = malloc(sizeof(sticks_t));
    int i = 0;
    int status = 0;

    sticks->len = 0;
    sticks->lines = my_getnbr(argv[1]);
    sticks->matches_pr = my_getnbr(argv[2]);
    sticks->window = malloc(sizeof(char *) * sticks->lines + 2);
    while (i < (sticks->lines + 2)) {
        sticks->window[i] = malloc(sizeof(char) * (sticks->lines * 2 + 3));
        i++;
    }
    sticks->window = print_matchstick(sticks->window, sticks);
    status = play_matchstick(sticks);
    return (status);
}