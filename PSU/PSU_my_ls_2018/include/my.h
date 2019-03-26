/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct flags {
    int l_flag;
    int r_flag;
    int R_flag;
    int d_flag;
    int t_flag;
    int total;
} flags_t;

void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
int my_putstr_ascii(char const *str);
int my_putstr_maj(char const *str);
int my_getnbr(char const *str);
int my_put_nbr_unsigned(int nb);
int my_putnbr_ubinary(int nb);
int my_strlen(char const *str);
int my_putnbr_base(int nb, char const *str);
void print_flags_base(char flag, va_list list);
void print_flags_charstr(char flag, va_list list);
void print_flags_inthex(char flag, va_list list);
int my_printf(char *str, ...);
void check_flag(char flag, va_list list);
void print_ls_only(int argc, char *argv);
void init_lflag(char *argv);
void init_ls(int argc, char *argv, int total);
flags_t *check_ls_flag(char *argv, flags_t *flags);
void print_lflag(struct stat sb);
char *set_time_format(char *str);
void print_permissions(struct stat sb);
void check_parameters(int argc, char **argv);
void count_blocks(char *argv);
int check_ls_error(char *argv, struct stat sb);

#endif