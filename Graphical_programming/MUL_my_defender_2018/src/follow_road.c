/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"
#include <stdio.h>

void follow_rode_d(game_t *game, sfVector2f size)
{
    game->zomby1_m = follow_path(game->zomby1_spr, game->zomby1_m, size);
    game->zomby2_m = follow_path(game->zomby2_spr, game->zomby2_m, size);
    game->zomby3_m = follow_path(game->zomby3_spr, game->zomby3_m, size);
}