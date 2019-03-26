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

#endif