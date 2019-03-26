/*
** EPITECH PROJECT, 2019
** fill_empty_map.c
** File description:
** fill_empty_map.c
*/

#include "my.h"

char **fill_map(char **map)
{
    map[0] = fill_lines_positions_p1(map[0]);
    map[11] = fill_empty_lines(map[11]);
    map[12] = fill_lines_positions_p2(map[12]);
    map[23] = fill_empty_lines(map[23]);
    return (map);
}

char *fill_empty_lines(char *map)
{
    map[0] = '\n';
    map[1] = '\0';
    return (map);
}

char *fill_lines_positions_p1(char *map)
{
    map[0] = 'm';
    map[1] = 'y';
    map[2] = ' ';
    map[3] = 'p';
    map[4] = 'o';
    map[5] = 's';
    map[6] = 'i';
    map[7] = 't';
    map[8] = 'i';
    map[9] = 'o';
    map[10] = 'n';
    map[11] = 's';
    map[12] = ':';
    map[13] = '\n';
    map[14] = '\0';
    return (map);
}

char *fill_lines_positions_p2(char *map)
{
    map[0] = 'e';
    map[1] = 'n';
    map[2] = 'e';
    map[3] = 'm';
    map[4] = 'y';
    map[5] = 39;
    map[6] = 's';
    map[7] = ' ';
    map[8] = 'p';
    map[9] = 'o';
    map[10] = 's';
    map[11] = 'i';
    map[12] = 't';
    map[13] = 'i';
    map[14] = 'o';
    map[15] = 'n';
    map[16] = 's';
    map[17] = ':';
    map[18] = '\n';
    map[19] = '\0';
    return (map);
}