/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void my_putchar(char c);
void my_put_nbr(int nb);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char *src);
void my_putstr(char const *str);
char *my_revstr(char *str);
char *get_base(int pi, int len);
char set_signal_value(int nb);
void first_sig(int andi);
void second_sig(int andi);
void sig(int i, int pi, int j);
int get_three_arg(int i, char *pi);
int get_two_arg(int i);
void print_help(void);
int char_to_binstr(char *str);
int conv_bin_to_dec(char *str);
int init_navy_t1(char **argv, char **map, int pid);
int init_navy_t2(char **argv, char **map, int pid);
char **my_str_to_word_array(char *str);
int check_arg_nbr(int argc, char **argv);
char **init_map(void);
int my_get_nbr(char *str);
char **malloc_map(void);
char *fill_middle_map(char *map, int count);
char *fill_letters_map(char *map);
char **fill_map(char **map);
char **set_ships(char **map, char *buf);
char *set_spaces(char *pos);
int check_vert_hor(char *pos);
int check_pos_file(char *file);
int check_line_lenght(char *str);
int play_navy_t1(char **map, int pid);
int play_navy_t2(char **map, int pid);
char **check_attack(char *attack, char **map);
char *get_attack_pos(char *attack);
char *init_string(char *str, int nb);
char *fill_lines_positions_p1(char *map);
char *fill_lines_positions_p2(char *map);
char *fill_empty_lines(char *map);
char **free_map(char **map);
void print_map(char **map);
void print_attack(char *attack);
char **mod_atk_map_enemy(char **map, char *atk_pos);
char **mod_atk_map_self(char **map, char *atk_pos);
int check_file_endchar(char *buf);
char **wait_attack(char **map, int pid);
char **send_attack(char **map, int pid);
void send_kill(int pid, char *attack);
void send_hit(int pid, int i);
char *get_pos_dec(char *str_bin);
char *get_str_bin(char *str_bin, int start);

#endif
