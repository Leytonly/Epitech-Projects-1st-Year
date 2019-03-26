/*
** EPITECH PROJECT, 2019
** player_turn.c
** File description:
** player_turn.c
*/

#include "my.h"

int check_arg(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57)
            count++;
        if (str[i] == '\n')
            count--;
        i++;
    }
    if (count != 0) {
        my_putstr("Error : invalid input (positive number expected)\n");
        return (-1);
    }
    else
        return (0);
}

int play_player(sticks_t *sticks)
{
    my_putstr("Your turn:\n");
    while (1) {
        my_putstr("Line: ");
        sticks->st = getline(&sticks->ch_line, &sticks->len, stdin);
        if (sticks->st == -1)
            return (-1);
        sticks->st_line = check_line(sticks);
        if (sticks->st_line == 0) {
            my_putstr("Matchs: ");
            sticks->st = getline(&sticks->ch_stick_nbr, &sticks->len, stdin);
        }
        if (sticks->st == -1)
            return (-1);
        if (sticks->st_line == 0 && (check_matches(sticks) == 0)) {
            print_player_turn(sticks);
            break;
        }
    }
    if (count_sticks(sticks->window, sticks->lines) == 0)
        return (2);
    return (0);
}

void print_player_turn(sticks_t *sticks)
{
    int len = 0;

    modif_matches_p(sticks);
    my_putstr("Player removed ");
    len = my_strlen(sticks->ch_line);
    sticks->ch_stick_nbr[len - 1] = '\0';
    my_putstr(sticks->ch_stick_nbr);
    my_putstr(" match(es) from line ");
    my_putstr(sticks->ch_line);
    print_format(sticks->window, sticks->lines);
    my_putchar('\n');
}

int check_matches(sticks_t *sticks)
{
    if (check_arg(sticks->ch_stick_nbr) == 0) {
        sticks->stick_nbr = my_getnbr(sticks->ch_stick_nbr);
        if (sticks->stick_nbr == 0) {
            my_putstr("Error : you have to remove at least one match\n");
            return (-1);
        }
        if (sticks->stick_nbr > sticks->matches_pr) {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(sticks->matches_pr);
            my_putstr(" matches per turn\n");
            return (-1);
        }
        else if (sticks->match_online < sticks->stick_nbr) {
            my_putstr("Error: not enough matches on this line\n");
            return (-1);
        }
    }
    else
        return (-1);
    return (0);
}

int play_matchstick(sticks_t *sticks)
{
    int ia = 0;
    int player = 0;

    sticks->all_sticks = count_sticks(sticks->window, sticks->lines);
    while (1) {
        player = play_player(sticks);
        if (player == 2) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        if (player == -1)
            return (0);
        ia = play_ai(sticks);
        if (ia == 1) {
            my_putstr("I lost... snif... but i'll get you next time!!\n");
            return (1);
        }
    }
    return (0);
}