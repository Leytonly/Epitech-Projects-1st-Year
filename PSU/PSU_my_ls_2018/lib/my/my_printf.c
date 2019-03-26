/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "../../include/my.h"

void print_flags_base(char flag, va_list list)
{
    int o = 0;
    int u = 0;
    int b = 0;

    switch (flag) {
        case 'o':
            o = va_arg(list, int);
            my_putnbr_base(o, "01234567");
            break;
        case 'u':
            u = va_arg(list, unsigned int);
            my_put_nbr_unsigned(u);
            break;
        case 'b':
            b = va_arg(list, int);
            my_putnbr_ubinary(b);
            break;
        default :
            break;
    }
}

void print_flags_charstr(char flag, va_list list)
{
    char c;
    char *s;
    char *S;

    switch (flag) {
        case 'c':
            c = va_arg(list, int);
            my_putchar(c);
            break;
        case 's':
            s = va_arg(list, char *);
            my_putstr(s);
            break;
        case 'S':
            S = va_arg(list, char *);
            my_putstr_ascii(S);
            break;
        default :
            break;
    }
}

void print_flags_inthex(char flag, va_list list)
{
    int di = 0;
    int x = 0;
    int X = 0;

    switch (flag) {
        case 'd': case 'i' :
            di = va_arg(list, int);
            my_put_nbr(di);
            break;
        case 'x' :
            x = va_arg(list, int);
            my_putnbr_base(x, "0123456789abcdef");
            break;
        case 'X' :
            X = va_arg(list, int);
            my_putnbr_base(x, "0123456789ABCDEF");
            break;
        default :
            break;
    }
}

void check_flag(char flag, va_list list)
{
    switch (flag) {
        case '%':
            my_putchar('%');
            break;
        case ' ':
            break;
        default :
            print_flags_inthex(flag, list);
            print_flags_charstr(flag, list);
            print_flags_base(flag, list);
    }
}

int my_printf(char *str, ...)
{
    int i = 0;
    va_list list;

    va_start(list, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            check_flag(str[i+1], list);
            i++;
        }
        else
            my_putchar(str[i]);
        i++;
    }
    va_end(list);
    return (0);
}
