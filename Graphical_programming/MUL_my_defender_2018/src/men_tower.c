/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"
#include <stdio.h>

void init_tower(stgame_t *game, sfVector2f position, sfVector2f scale)
{
    sfSprite_setPosition(game->in_game->tower_spr, position);
    sfSprite_setScale(game->in_game->tower_spr, scale);
}

void init_tower2(stgame_t *game, sfVector2f position, sfVector2f scale)
{
    sfSprite_setPosition(game->in_game->tower2_spr, position);
    sfSprite_setScale(game->in_game->tower2_spr, scale);
}

void init_tower3(stgame_t *game, sfVector2f position, sfVector2f scale)
{
    sfSprite_setPosition(game->in_game->tower3_spr, position);
    sfSprite_setScale(game->in_game->tower3_spr, scale);
}

void init_tower4(stgame_t *game, sfVector2f position, sfVector2f scale)
{
    sfSprite_setPosition(game->in_game->tower4_spr, position);
    sfSprite_setScale(game->in_game->tower4_spr, scale);
}