/*
** EPITECH PROJECT, 2019
** ai_turn.c
** File description:
** ai_turn.c
*/

#include "my.h"

int check_line(sticks_t *sticks)
{
    int i = 0;
    i = check_arg(sticks->ch_line);
        if (i == 0) {
        sticks->line = my_getnbr(sticks->ch_line);
        sticks->match_online = calc_sticks(sticks->window[sticks->line]);
    }
    else
        return (-1); 
    if ((sticks->line) > (sticks->lines)) {
        my_putstr("Error: this line is out of range\n");
        return (-1);
    }
    return (0);
}

void print_ia(sticks_t *sticks)
{
    modif_matches_p(sticks);
    my_putstr("IA removed ");
    my_put_nbr(sticks->stick_nbr);
    my_putstr(" match(es) from line ");
    my_put_nbr(sticks->line);
    my_putchar('\n');
    print_format(sticks->window, sticks->lines);
    my_putchar('\n');
}

int play_ai(sticks_t *sticks)
{
    int i = 0;

    while (1) {
        sticks->line = (rand() % sticks->lines) + 1;
        sticks->stick_nbr = (rand() % sticks->matches_pr) + 1;
        i = calc_sticks(sticks->window[sticks->line]);
        if (i != 0 && sticks->stick_nbr != 0 && i >= sticks->stick_nbr) {
            print_ia(sticks);
            break;
        }
    }
    if (count_sticks(sticks->window, sticks->lines) == 0)
        return (1);
    return (0);
}

int count_lines(char **window, int lines)
{
    int i = 0;
    int count = 0;

    while (i < lines) {
        if (calc_sticks(window[i + 1]) != 0)
            count++;
        i++;
    }
    return (count);
}