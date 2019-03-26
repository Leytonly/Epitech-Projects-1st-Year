/*
** EPITECH PROJECT, 2018
** init_shop.c
** File description:
** init the sprites of the shop for the towers
*/

#include "my.h"

void load_shop_objects(game_t *game)
{
    game->shop_htower_txt = sfTexture_createFromFile(
        "sprites/holy_tower_button.png", NULL);
    game->shop_atower_txt = sfTexture_createFromFile(
        "sprites/archer_tower_button.png", NULL);
    game->shop_rtower_txt = sfTexture_createFromFile(
        "sprites/rock_tower_button.png", NULL);
    game->shop_wtower_txt = sfTexture_createFromFile(
        "sprites/wizard_tower_button.png", NULL);
    game->shop_htower_spr = sfSprite_create();
    game->shop_atower_spr = sfSprite_create();
    game->shop_rtower_spr = sfSprite_create();
    game->shop_wtower_spr = sfSprite_create();
    sfSprite_setTexture(game->shop_atower_spr, game->shop_atower_txt,
        sfTrue);
    sfSprite_setTexture(game->shop_rtower_spr, game->shop_rtower_txt,
        sfTrue);
    sfSprite_setTexture(game->shop_wtower_spr, game->shop_wtower_txt,
        sfTrue);
    sfSprite_setTexture(game->shop_htower_spr, game->shop_htower_txt,
        sfTrue);
    set_shop_position(game);
}

void set_shop_position(game_t *game)
{
    game->gold_am = 100;
    game->life_am = 10;
    game->wave_am = 1;
    sfSprite_setPosition(game->shop_htower_spr, (sfVector2f){3, 594});
    sfSprite_setPosition(game->shop_atower_spr, (sfVector2f){150, 610});
    sfSprite_setPosition(game->shop_rtower_spr, (sfVector2f){340, 850});
    sfSprite_setPosition(game->shop_wtower_spr, (sfVector2f){290, 700});
    sfSprite_scale(game->shop_htower_spr, (sfVector2f){0.4, 0.4});
    sfSprite_scale(game->shop_atower_spr, (sfVector2f){0.4, 0.4});
    sfSprite_scale(game->shop_rtower_spr, (sfVector2f){0.4, 0.4});
    sfSprite_scale(game->shop_wtower_spr, (sfVector2f){0.4, 0.4});
}