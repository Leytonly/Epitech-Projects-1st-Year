/*
** EPITECH PROJECT, 2018
** init_towers.c
** File description:
** initialise the sprites of the towers
*/

#include "my.h"

void create_tower_sprites(stgame_t *game)
{
    game->towers->tw1_spr = sfSprite_create();
    game->towers->tw2_spr = sfSprite_create();
    game->towers->tw3_spr = sfSprite_create();
    game->towers->tw4_spr = sfSprite_create();
    game->towers->tw5_spr = sfSprite_create();
    game->towers->tw6_spr = sfSprite_create();
    game->towers->tw7_spr = sfSprite_create();
    game->towers->tw8_spr = sfSprite_create();
    game->towers->tw9_spr = sfSprite_create();
}