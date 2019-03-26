/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct sticks {
    char *ch_line;
    char *ch_stick_nbr;
    int line;
    int stick_nbr;
    int match_online;
    size_t len;
    int st_line;
    int lines;
    int status;
    int st;
    int matches_pr;
    int all_sticks;
    char **window;
}sticks_t;

void my_putchar(char c);
int my_getnbr(char const *str);
void my_put_nbr(int nb);
int my_strlen(char const *str);
void my_putstr(char const *str);
int calc_sticks(char *window);
int init_matchstick(char **argv);
int count_lines(char **window, int lines);
int play_ai(sticks_t *sticks);
int play_matchstick(sticks_t *sticks);
int check_input(char *str);
void modif_matches_p(sticks_t *sticks);
int check_line(sticks_t *sticks);
void print_format(char **window, int lines);
int count_sticks(char **window, int lines);
int check_matches(sticks_t *sticks);
int play_player(sticks_t *sticks);
char *print_stick(char *window, int lines);
char **print_matchstick(char **window, sticks_t *sticks);
char *fill_top_bottom(char *window, sticks_t *sticks);
char *fill_middle(char *window, sticks_t *sticks, int temp);
void print_player_turn(sticks_t *sticks);
int check_params(char **argv);
int check_arg(char *str);
int calc_sticks(char *window);
int play_ai(sticks_t *sticks);
void print_ia(sticks_t *sticks);


#endif