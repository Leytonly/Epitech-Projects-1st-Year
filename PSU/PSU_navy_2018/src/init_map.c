/*
** EPITECH PROJECT, 2018
** init_map.c
** File description:
** initialise the empty map
*/

#include <stdio.h>
#include "my.h"

char *fill_middle_map(char *map, int count)
{
    int i = 2;

    map[0] = '0' + count;
    map[1] = '|';
    while (i < 17) {
        if (i % 2 == 0)
            map[i] = '.';
        else
            map[i] = ' ';
        i++;
    }
    map[17] = '\n';
    map[18] = '\0';
    return (map);
}

char **malloc_map(void)
{
    int i = 0;
    char **map = NULL;

    map = malloc(sizeof(char *) * 24);
    while (i < 24) {
        map[i] = malloc(sizeof(char) * 20);
        map[i] = init_string(map[i], 20);
        i++;
    }
    return (map);
}

char *fill_letters_map(char *map)
{
    int i = 0;
    int letter = 65;

    while (i < 19) {
        if (i == 0 || ((i % 2 != 0) && i >= 2 && i <= 16))
            map[i] = ' ';
        if ((i % 2 == 0) && i >= 2 && i <= 16) {
            map[i] = letter;
            letter++;
        }
        if (i == 1)
            map[i] = '|';
        if (i == 17)
            map[i] = '\n';
        i++;
        if (i == 18)
            map[i] = '\0';
    }
    return (map);
}

char *fill_over_letters(char *map)
{
    int i = 0;

    while (i < 18) {
        if (i == 1)
            map[i] = '+';
        else if (i == 17)
            map[i] = '\n';
        else
            map[i] = '-';
        i++;
    }
    map[i] = '\0';
    return (map);
}

char **init_map(void)
{
    char **map = malloc_map();
    int j = 0;
    int count = 1;

    map = fill_map(map);
    while (j != 24) {
        if (j == 1 || j == 13)
            map[j] = fill_letters_map(map[j]);
        if (j == 2 || j == 14)
            map[j] = fill_over_letters(map[j]);
        if ((j > 2 && j < 11) || (j > 14 && j < 23)) {
            map[j] = fill_middle_map(map[j], count);
            count++;
        }
        else
            count = 1;
        j++;
    }
    return (map);
}
