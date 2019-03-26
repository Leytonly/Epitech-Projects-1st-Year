/*
** EPITECH PROJECT, 2019
** parallax.c
** File description:
** parallax.c
*/

#include "include/my.h"

void check_parallax(gameobjects_t *gameobj, move_t *move)
{
    set_shark(gameobj->sp_shark);
    set_parallax(gameobj->sp_bg);
    set_parallax(gameobj->sp_bg2);
    set_parallax(gameobj->sp_sand);
    set_parallax(gameobj->sp_sand2);
    set_parallax_fg(gameobj->sp_fg);
    set_parallax_fg(gameobj->sp_fg2);
}

void init_parallax(gameobjects_t *gameobj, move_t *move)
{
    set_offset(move);
    sfSprite_setPosition(gameobj->sp_bg2, move->ofst_far_plx);
    sfSprite_setPosition(gameobj->sp_sand2, move->ofst_sand_plx);
    sfSprite_setPosition(gameobj->sp_fg2, move->ofst_fg_plx);
    sfSprite_setPosition(gameobj->sp_player, move->ofst_player);
}

void set_parallax(sfSprite *sprite)
{
    sfVector2f sprite_pos;
    sfVector2f new_pos;

    new_pos.x = 1356.8;
    sprite_pos = sfSprite_getPosition(sprite);
    if (sprite_pos.x < -1354.8)
        sfSprite_setPosition(sprite, new_pos);
}

void set_shark(sfSprite *sprite)
{
    sfVector2f sprite_pos;
    sfVector2f new_pos;

    new_pos.x = 1356.8;
    new_pos.y = rand() % 700;
    sprite_pos = sfSprite_getPosition(sprite);
    if (sprite_pos.x < -200)
        sfSprite_setPosition(sprite, new_pos);
}

void set_parallax_fg(sfSprite *sprite)
{
    sfVector2f sprite_pos;
    sfVector2f new_pos;

    new_pos.x = 2713.6;
    sprite_pos = sfSprite_getPosition(sprite);
    if (sprite_pos.x < -2700.6)
        sfSprite_setPosition(sprite, new_pos);
}