/*
** EPITECH PROJECT, 2019
** rect_p.c
** File description:
** rect_p.c
*/

#include "include/my.h"

sfIntRect move_rect(gameobjects_t *gameobj, events_t *events, sfIntRect rect_p)
{
    events->time = sfClock_getElapsedTime(events->clock_player);
    events->seconds = events->time.microseconds / 1000000.0;
    sfVector2f player_pos;

    if (events->seconds > 0.12) {
        rect_p.left = rect_p.left - 60;
        sfSprite_setTextureRect(gameobj->sp_player, rect_p);
        sfClock_restart(events->clock_player);
        if (rect_p.left == 32)
            rect_p.left = 512;
    }

    return (rect_p);
}

sfIntRect int_rect_p(void)
{
    sfIntRect rect_p;
    rect_p.top = 46;
    rect_p.left = 512;
    rect_p.width = 58;
    rect_p.height = 40;
    return (rect_p);
}

sfIntRect int_rect_sh(void)
{
    sfIntRect rect_p;
    rect_p.top = 0;
    rect_p.left = 490;
    rect_p.width = 190;
    rect_p.height = 82;
    return (rect_p);
}