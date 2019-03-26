/*
** EPITECH PROJECT, 2019
** sprites.c
** File description:
** sprites.c
*/

#include "include/my.h"

void draw_sprites(gameobjects_t *gameobj)
{
    sfRenderWindow_drawSprite(gameobj->window, gameobj->sp_bg, NULL);
    sfRenderWindow_drawSprite(gameobj->window, gameobj->sp_bg2, NULL);
    sfRenderWindow_drawSprite(gameobj->window, gameobj->sp_sand, NULL);
    sfRenderWindow_drawSprite(gameobj->window, gameobj->sp_sand2, NULL);
    sfRenderWindow_drawSprite(gameobj->window, gameobj->sp_fg, NULL);
    sfRenderWindow_drawSprite(gameobj->window, gameobj->sp_fg2, NULL);
    sfRenderWindow_drawSprite(gameobj->window, gameobj->sp_shark, NULL);
    sfRenderWindow_drawSprite(gameobj->window, gameobj->sp_player, NULL);
}

void move_sprites(gameobjects_t *gameobj, move_t *move, events_t *events)
{
    events->time = sfClock_getElapsedTime(events->clock);
    events->seconds = events->time.microseconds / 1000000.0;
    if (events->seconds > 0.01) {
        sfRenderWindow_clear(gameobj->window, sfBlack);
        sfSprite_move(gameobj->sp_bg, move->ofst_far);
        sfSprite_move(gameobj->sp_bg2, move->ofst_far);
        sfSprite_move(gameobj->sp_sand, move->ofst_sand);
        sfSprite_move(gameobj->sp_sand2, move->ofst_sand);
        sfSprite_move(gameobj->sp_fg, move->ofst_fg);
        sfSprite_move(gameobj->sp_fg2, move->ofst_fg);
        sfSprite_move(gameobj->sp_shark, move->ofst_fg);
        check_parallax(gameobj, move);
        draw_sprites(gameobj);
        sfRenderWindow_display(gameobj->window);
        sfClock_restart(events->clock);
    }
}

void set_texture(gameobjects_t *gameobj)
{
    sfSprite_setTexture(gameobj->sp_bg, gameobj->tx_bg, sfTrue);
    sfSprite_setTexture(gameobj->sp_bg2, gameobj->tx_bg, sfTrue);
    sfSprite_setTexture(gameobj->sp_sand, gameobj->tx_sand, sfTrue);
    sfSprite_setTexture(gameobj->sp_sand2, gameobj->tx_sand, sfTrue);
    sfSprite_setTexture(gameobj->sp_fg, gameobj->tx_fg, sfTrue);
    sfSprite_setTexture(gameobj->sp_fg2, gameobj->tx_fg, sfTrue);
    sfSprite_setTexture(gameobj->sp_shark, gameobj->tx_shark, sfTrue);
    sfSprite_setTexture(gameobj->sp_player, gameobj->tx_player, sfTrue);
}
void set_scale(gameobjects_t *gameobj, sfIntRect rect_p, sfIntRect rect_sh)
{
    sfVector2f scale;
    sfVector2f player;
    int pos = rand() % 700;

    scale.x = 5.3;
    scale.y = 5.3;
    player.x = 3.3;
    player.y = 3.3;
    set_texture(gameobj);
    sfSprite_setScale(gameobj->sp_bg, scale);
    sfSprite_setScale(gameobj->sp_bg2, scale);
    sfSprite_setScale(gameobj->sp_sand, scale);
    sfSprite_setScale(gameobj->sp_sand2, scale);
    sfSprite_setScale(gameobj->sp_fg, scale);
    sfSprite_setScale(gameobj->sp_fg2, scale);
    sfSprite_setTextureRect(gameobj->sp_shark, rect_sh);
    sfSprite_setPosition(gameobj->sp_shark, (sfVector2f){1356.8, pos});
    sfSprite_setTextureRect(gameobj->sp_player, rect_p);
    sfSprite_setScale(gameobj->sp_player, player);
}

void create_sprite(gameobjects_t *gameobj, sfIntRect rect_p, sfIntRect rect_sh)
{
    gameobj->tx_bg = sfTexture_createFromFile("images/far.png", NULL);
    gameobj->sp_bg = sfSprite_create();
    gameobj->sp_bg2 = sfSprite_create();
    gameobj->tx_sand = sfTexture_createFromFile("images/sand.png", NULL);
    gameobj->sp_sand = sfSprite_create();
    gameobj->sp_sand2 = sfSprite_create();
    gameobj->tx_fg = sfTexture_createFromFile("images/fg.png", NULL);
    gameobj->sp_fg = sfSprite_create();
    gameobj->sp_fg2 = sfSprite_create();
    gameobj->tx_shark = sfTexture_createFromFile("images/shark.png", NULL);
    gameobj->sp_shark = sfSprite_create();
    gameobj->tx_player = sfTexture_createFromFile("images/player.png", NULL);
    gameobj->sp_player = sfSprite_create();
    set_scale(gameobj, rect_p, rect_sh);
}

move_t *set_offset(move_t *move)
{
    move->ofst_far.x = -0.5;
    move->ofst_sand.x = -2;
    move->ofst_fg.x = -3;
    move->ofst_player.x = 10;
    move->ofst_player.y = 750;
    move->ofst_far_plx.x = 1356.8;
    move->ofst_sand_plx.x = 1356.8;
    move->ofst_fg_plx.x = 2713.6;
    return (move);
}