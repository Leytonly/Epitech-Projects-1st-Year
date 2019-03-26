/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"
#include <stdio.h>

void init_zomby1(stgame_t *game, sfVector2f position, sfVector2f scale)
{
    sfSprite_setPosition(game->in_game->zomby1_spr, position);
    sfSprite_setScale(game->in_game->zomby1_spr, scale);
}

void init_zomby2(stgame_t *game, sfVector2f position, sfVector2f scale)
{
    sfSprite_setPosition(game->in_game->zomby2_spr, position);
    sfSprite_setScale(game->in_game->zomby2_spr, scale);
}

void init_zomby3(stgame_t *game, sfVector2f position, sfVector2f scale)
{
    sfSprite_setPosition(game->in_game->zomby3_spr, position);
    sfSprite_setScale(game->in_game->zomby3_spr, scale);
}

sfIntRect frame_zomby(int frame, sfIntRect rectangle)
{
    rectangle.left = 256 - (64 * frame);
    rectangle.top = 0;
    rectangle.width = 64;
    rectangle.height = 32;
    return (rectangle);
}

void clock_zomby(sfClock *clock, game_t *zomby)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.2) {
        sfClock_restart(clock);
        zomby->frame++;
        zomby = moove_zomby(zomby);
    }
    if (zomby->frame == 4)
        zomby->frame = 0;
}