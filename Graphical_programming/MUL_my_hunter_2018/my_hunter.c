/*
** EPITECH PROJECT, 2018
** my_hunter.c
** File description:
** my_hunter.c
*/

#include "SFML/Graphics.h"
#include "SFML/System/Vector2.h"
#include "SFML/Window/Export.h"
#include <time.h>
#include <stdlib.h>
#include "include/my.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer;
    int bitsperpixel = 32;

    framebuffer = malloc(sizeof(framebuffer));
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(width * height * bitsperpixel / 8);
    return (framebuffer);
}

sfIntRect int_rect_p(sfRenderWindow* window)
{
    sfIntRect rect_p;
    rect_p.top = 0;
    rect_p.left = 0;
    rect_p.width = 110;
    rect_p.height = 110;
    return (rect_p);
}

sfIntRect move_rect(sfRenderWindow *window, events_t *events, sfIntRect rect_p)
{
    events->time = sfClock_getElapsedTime(events->clock);
    events->seconds = events->time.microseconds / 1000000.0;

    if (events->seconds > 0.03) {
        rect_p.left = rect_p.left + 110;
        events->x = events->x + 16;
        events->y = events->y + 7;
        sfClock_restart(events->clock);

        if (rect_p.left == 330) {
            rect_p.left = 0;
        }
        if (events->x > 1600 || events->y > 1000) {
            events->x = 0;
            events->y = rand() % 900;
        }
    }
    return (rect_p);
}

void checkif_events(gameobject_t *gameobject, events_t *events)
{
    while (sfRenderWindow_pollEvent(gameobject->window, &events->event)) {
        analyse_events(gameobject->window, events->event);
        if (events->event.type == sfEvtClosed) {
            sfRenderWindow_close(gameobject->window);
        }
    }
}
void game_start(gameobject_t *gameobject, framebuffer_t *framebuffer,
               events_t *events)
{
    sfIntRect rect_p = int_rect_p(gameobject->window);
    sfVideoMode mode = {1600, 1000, 32}; 

    gameobject = malloc(sizeof(gameobject_t));
    events = malloc(sizeof(events_t));
    gameobject->window = sfRenderWindow_create(mode, "My_hunter", sfResize |
                                            sfClose, NULL);
    sfRenderWindow_setFramerateLimit(gameobject->window, 30);
    events->clock = sfClock_create();
    while (sfRenderWindow_isOpen(gameobject->window)) {
        rect_p = move_rect(gameobject->window, events, rect_p);
        create_sprite(rect_p, gameobject, events);
    }
    destroy_sprites(gameobject, events);
}