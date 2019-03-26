/*
** EPITECH PROJECT, 2018
** play_navy.c
** File description:
** gameloop of the navy
*/

#include "my.h"

int check_boat_left_self(char **map)
{
    int i = 3;
    int j = 2;
    int count = 0;

    while (i < 11) {
        while (map[i][j] != '\0') {
            if (map[i][j] >= '0' && map[i][j] <= '9')
                count++;
            j++;
        }
        i++;
        j = 0;
    }
    return (count);
}

int check_boat_left_enemy(char **map)
{
    int i = 15;
    int j = 2;
    int count = 0;

    while (i < 22) {
        while (map[i][j] != '\0') {
            if (map[i][j] >= '0' && map[i][j] <= '9')
                count++;
            j++;
        }
        i++;
        j = 2;
    }
    return (count);
}

int play_navy_t2(char **map, int pid)
{
    while (1) {
        my_putstr("waiting for enemy's attack...\n");
        map = wait_attack(map, pid);
        my_putstr("attack:  ");
        map = send_attack(map, pid);
        if (check_boat_left_self(map) != 0) {
            my_putstr("Enemy won\n");
            return(1);
        }
        if (check_boat_left_enemy(map) != 0) {
            my_putstr("I won\n");
            return (0);
        }
    }
    return (2);
}

int play_navy_t1(char **map, int pid)
{
    while (1) {
        my_putstr("attack:  ");
        map = send_attack(map, pid);
        my_putstr("waiting for enemy's attack...\n");
        map = wait_attack(map, pid);
        if (check_boat_left_self(map) != 0) {
            my_putstr("Enemy won\n");
            return(1);
        }
        if (check_boat_left_enemy(map) != 0) {
            my_putstr("I won\n");
            return (0);
        }
    }
    return (2);
}
