/*
** EPITECH PROJECT, 2018
** map_checking.c
** File description:
** check lines, columns and the player position
*/

#include "include/my.h"

int get_lenght(char *map, int i)
{
    int count = 0;

    while (map[i] != '\n')
        i = i - 1;
    if (map[i] == '\n') {
        i = i + 1;
        while (map[i] != '\n') {
            i = i + 1;
            count = count + 1;
        }
    }
    count = count + 1;
    return (count);
}

int get_cols_up(char *map, int i)
{
    int count = 0;

    while (map[i] != '\n' && map[i] != 0)
        i = i - 1;
    if (map[i] == '\n') {
        i = i - 1;
        while (map[i] != '\n' && map[i] != 0) {
            i = i - 1;
            count = count + 1;
        } 
    }
    count = count + 1;
    return (count);
}

int get_cols_down(char *map, int i)
{
    int count = 0;

    while (map[i] != '\n')
        i = i + 1;
    if (map[i] == '\n') {
        i = i + 1;
        while (map[i] != '\n') {
            i = i + 1;
            count = count + 1;
        }
    }
    count = count + 1;
    return (count);
}

int check_line_up(char *map, int i)
{
    int len = get_cols_up(map, i);
    int len_ppos = get_player_pos_online(map, i);
    int result = 0;

    if (map[i - len_ppos - len - 1] == 0)
        result = 0;
    else
        result = 1;
    return (result);
}

int line_nbr(char *map)
{
    int i = 0;
    int j = 0;
    
    while (map[i] != '\0') {
        if (map[i] == '\n')
            j++;
        i++;
    }
    return (j);
}
