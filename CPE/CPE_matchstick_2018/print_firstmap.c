/*
** EPITECH PROJECT, 2019
** print_firstmap.c
** File description:
** print_firstmap.c
*/

#include "my.h"

char *print_stick(char *window, int lines)
{
    int i = 0;
    static int sticks = 1;
    static int temp = 1;

    while (i < sticks && lines > 0) {
        window[lines] = '|';
        lines++;
        i++;
    }
    if (i == sticks && lines > 0) {
        i = 0;
        sticks = sticks + 2;
        lines = lines - temp;
        temp++;
    }
    return (window);
}

char *fill_middle(char *window, sticks_t *sticks, int temp)
{
    int i = 0;

    while (i < sticks->lines * 2 + 1) {
        if (i == 0 || i == sticks->lines * 2)
            window[i] = '*';
        else
            window[i] = ' ';
        i++;
    }
    window[sticks->lines * 2 + 1] = '\n';
    window[sticks->lines * 2 + 2] = '\0';
    window = print_stick(window, temp);
    my_putstr(window);
    return (window);
}

char *fill_top_bottom(char *window, sticks_t *sticks)
{
    int i = 0;

    while (i < sticks->lines * 2 + 1) {
        window[i] = '*';
        i++;
    }
    window[sticks->lines * 2 + 1] = '\n';
    window[sticks->lines * 2 + 2] = '\0';
    my_putstr(window);
    return (window);
}

char **print_matchstick(char **window, sticks_t *sticks)
{
    int i = 0;
    int temp = sticks->lines;

    while (i < (sticks->lines + 2)) {
        if (i == 0 || i == (sticks->lines + 1))
            window[i] = fill_top_bottom(window[i], sticks);
        else {
            fill_middle(window[i], sticks, temp);
            temp = temp - 1;
        }
        i++;
    }
    return (window);
}