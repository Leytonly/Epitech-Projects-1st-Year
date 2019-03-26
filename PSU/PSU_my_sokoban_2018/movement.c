/*
** EPITECH PROJECT, 2018
** movement.c
** File description:
** movement of the player 'P'
*/

#include "include/my.h"
#include "ncurses.h"

char *move_player(char *map, char *origin_map)
{
    switch(getch()) {
        case KEY_LEFT: map = move_player_left(map);
            return (map);
        case KEY_RIGHT: map = move_player_right(map);
            return (map);
        case KEY_UP: map = move_player_up(map);
            return (map);
        case KEY_DOWN: map = move_player_down(map);
            return (map);
        case ' ': map = reset_map(map, origin_map);
            return (map);
        default:
            return (map);
    }
}

char *move_player_left(char *map)
{
    int i = get_player_pos(map);
    if (map[i - 1] == ' ') {
        map[i - 1] = 'P';
        map[i] = ' ';
    }
    if (map[i - 1] == 'X' && map[i - 2] == 'X');
    else if (map[i - 1] == 'X' && (map[i - 2] == 'O' && map[i - 2] != '\n'||
             map[i - 2] == ' ')) {
        map[i - 1] = 'P';
        map[i - 2] = 'X';
        map[i] = ' ';
    }
    return (map);
}

char *move_player_right(char *map)
{
    int i = get_player_pos(map);
    if (map[i + 1] == ' ') {
        map[i + 1] = 'P';
        map[i] = ' ';
    }
    if (map[i + 1] == 'X' && map[i + 2] == 'X');
    else if (map[i + 1] == 'X' && (map[i + 2] == 'O' || map[i + 2] == ' ')) {
        map[i + 1] = 'P';
        map[i + 1 * 2] = 'X';
        map[i] = ' ';
    }
    return (map);
}

char *move_player_up(char *map)
{
    int i = get_player_pos(map);
    int len = get_cols_up(map, i);
    int len_x = get_cols_up(map, i - len);

    if (map[i - len] == ' ' && len >= get_player_pos_online(map, i)) {
        map[i - len] = 'P';
        map[i] = ' ';
    }
    if (map[i - len] == 'X' && map[i - len - len_x] == 'X');
    else if (map[i - len] == 'X' && (map[i - len - len_x] == ' ' ||
             map[i - len - len_x] == 'O')) {
        map[i - len - len_x] = 'X';
        map[i - len] = 'P';
        map[i] = ' ';
    }
    return (map);
}

char *move_player_down(char *map)
{
    int i = get_player_pos(map);
    int len = get_lenght(map, i);
    int len_x = get_lenght(map, i + len);

    if (map[i + len] == ' ') {
        map[i + len] = 'P';
        map[i] = ' ';
    }
    if (map[i + len] == 'X' && map[i + len + len_x] == 'X');
    else if (map[i + len] == 'X' && (map[i + len + len_x] == ' ' ||
             map[i + len + len_x] == 'O')) {
        map[i + len + len_x] = 'X';
        map[i + len] = 'P';
        map[i] = ' ';
    }
    return (map);
}
