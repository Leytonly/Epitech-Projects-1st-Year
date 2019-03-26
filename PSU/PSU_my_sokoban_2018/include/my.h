/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putstr_modified(char const *str);
int my_putstr_maj(char const *str);
int my_getnbr(char const *str);
int my_put_nbr_modif(int nb);
int my_putnbr_ubinary(int nb);
int my_strlen(char const *str);
int my_putnbr_base(int nb, char const *str);
void print_flags3(char flag, va_list list);
void print_flags2(char flag, va_list list);
void print_flags(char flag, va_list list);
int my_printf(char *str, ...);
void check_flag(char flag, va_list list);
int my_sokoban(char *map);
int line_nbr(char *map);
int check_longest_line(char *map);
int check_line_up(char *map, int i);
int get_cols_up(char *map, int i);
int get_cols_down(char *map, int i);
int get_lenght(char *map, int i);
int get_player_pos_online(char *map, int i);
char *move_player(char *map, char *origin_map);
char *clone_map(char *map, char *origin_map);
char *reset_map(char *map, char *origin_map);
char *move_player_down(char *map);
char *move_player_up(char *map);
char *move_player_right(char *map);
char *move_player_left(char *map);
int get_player_pos(char *map);
void print_help(void);

#endif