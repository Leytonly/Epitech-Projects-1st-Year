/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "include/my.h"

int main(int argc, char **argv)
{
    gameobjects_t *gameobj = malloc(sizeof(gameobjects_t));
    events_t *events = malloc(sizeof(events_t));

    game_start(gameobj, events);
    return (0);
}