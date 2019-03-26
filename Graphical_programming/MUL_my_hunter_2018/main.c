/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "SFML/Graphics.h"
#include "SFML/System/Vector2.h"
#include "SFML/Window/Export.h"
#include <time.h>
#include <stdlib.h>
#include "include/my.h"

int main(int argc, char **argv)
{
    framebuffer_t *framebuffer = framebuffer_create(1600, 1000);
    gameobject_t *gameobject;
    events_t *events;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("Your goal is to shoot the ducks");
    }
    else
        game_start(gameobject, framebuffer, events);
    return (0);
}