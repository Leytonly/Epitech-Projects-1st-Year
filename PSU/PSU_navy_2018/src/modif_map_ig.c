/*
** EPITECH PROJECT, 2018
** modif_map_ig.c
** File description:
** modif map while playing
*/

#include "my.h"

char **mod_atk_map_enemy(char **map, char *atk_pos)
{
    int p_letter = (atk_pos[0] - 64) * 2;
    int p_num = atk_pos[1] - 34;
    if (map[p_num][p_letter] == '.' || map[p_num][p_letter] == ' ')
        map[p_num][p_letter] = 'o';
    else
        map[p_num][p_letter] = 'x';
    return (map);
}

char **mod_atk_map_self(char **map, char *atk_pos)
{
    int p_letter = (atk_pos[0] - 64) * 2;
    int p_num = atk_pos[1] - 34;
    if (map[p_num][p_letter] == '.' || map[p_num][p_letter] == ' ')
        map[p_num][p_letter] = 'o';
    else
        map[p_num][p_letter] = 'x';
    return (map);
}

void print_map(char **map)
{
    int i = 0;

    while (i != 24) {
        my_putstr(map[i]);
        i++;
    }
}

void print_attack(char *attack)
{
    my_putchar(attack[0]);
    my_putchar(attack[1]);
    my_putstr(": hit\n\n");
}