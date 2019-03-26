/*
** EPITECH PROJECT, 2019
** modif_map.c
** File description:
** placing the ships on the empty map and freeing the map
*/

#include <stdio.h>
#include "my.h"

char **free_map(char **map)
{
    int i = 0;

    while (i < 24) {
        free(map[i]);
        i++;
    }
    return (0);
}

char *set_spaces(char *pos)
{
    int i = 0;

    while (pos[i] != '\0') {
        if (pos[i] == '\n')
            pos[i] = ' ';
        i++;
    }
    return (pos);
}

int check_vert_hor(char *pos)
{
    int result = 0;

    if (pos[2] == pos[5])
        result = 1;
    else if (pos[3] == pos[6])
        result = 2;
    return (result);
}

char **place_ship_on_board(char **map, char *pos)
{
    int len = pos[0] - 48;
    int l_pos = (pos[2] - 64) * 2;
    int n_pos = (pos[3] - 48) + 2;

    if (check_vert_hor(pos) == 1) {
        for (; len != 0; len--) {
            map[n_pos][l_pos] = pos[0];
            n_pos++;
        }
    }
    else if (check_vert_hor(pos) == 2) {
        for (; len != 0; len--) {
            map[n_pos][l_pos] = pos[0];
            l_pos = l_pos + 2;
        }
    }
    return (map);
}

char **set_ships(char **map, char *buf)
{
    int i = 0;
    char **pos = NULL;
    int k = 0;

    buf = set_spaces(buf);
    pos = my_str_to_word_array(buf);
    while (pos[i] != NULL) {
        map = place_ship_on_board(map, pos[i]);
        i++;
    }
    while (k < 24) {
        my_putstr(map[k]);
        k++;
    }
    return (map);
}
