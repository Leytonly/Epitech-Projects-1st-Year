/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"
#include <stdio.h>

game_t *moove_zomby(game_t *game)
{
    sfVector2f size;

    game->zomby1_m.x = -5;
    game->zomby1_m.y = 0;
    game->zomby2_m.x = -5;
    game->zomby2_m.y = 0;
    game->zomby3_m.x = -5;
    game->zomby3_m.y = 0;
    follow_rode_d(game, size);
    return (game);
}

sfSprite *position_sprites(sfSprite *target, game_t *game)
{
    sfVector2f size;

    size = sfSprite_getPosition(target);
    if (size.x <= 10) {
        size.x = 4000;
        size.y = 805;
        sfSprite_setPosition(target, size);
        game->sound2 = add_mus(game->sound2);
    }
    return (target);
}