/*
** EPITECH PROJECT, 2018
** use_func
** File description:
** tools.
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *s)
{
    for (int i = 0 ; s[i] != 0 ; i++)
        my_putchar(s[i]);
}

void usage_func(int ac, char **av)
{
    if ((ac == 2) && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Finite runner created with CSFML.\n\n");
        my_putstr("USAGE\n\n");
        my_putstr(" ./my_runner\n\n");
        my_putstr("USER INTERACTIONS\n\n");
        my_putstr("SPACE_KEY    jump up.\n");
        my_putstr("KEY_UP    jump up.\n");
        my_putstr("KEY_DOWN    jump down.\n");
        my_putstr("ESCAPE_KEY    exit game.\n");
    }
}

char *int_to_char(int a)
{
    char *str = NULL;
    int b = 0;
    int c = a;

    while (c) {
        c /= 10;
        b++;
    }
    str = malloc(sizeof(char) * (b + 1));
    if (str == NULL)
        return (NULL);
    c = b - 1;
    while (c >= 0) {
        str[c] = a % 10 + '0';
        a /= 10;
        c--;
    }
    str[b] = '\0';
    return (str);
}