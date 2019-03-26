/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"

void display_build2(sfRenderWindow *window, stmenu_t *menu, stgame_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->in_men->bck_spr, NULL);
    sfRenderWindow_drawSprite(window, game->in_game->tower_spr, NULL);
    sfRenderWindow_drawSprite(window, game->in_game->tower2_spr, NULL);
    sfRenderWindow_drawSprite(window, game->in_game->tower3_spr, NULL);
    sfRenderWindow_drawSprite(window, game->in_game->tower4_spr, NULL);
    game->in_game->t1_men = position_t1_men(game->in_game->t1_men);
    sfRenderWindow_drawText(window, game->in_game->t1_men, NULL);
    game->in_game->t2_men = position_t2_men(game->in_game->t2_men);
    sfRenderWindow_drawText(window, game->in_game->t2_men, NULL);
    game->in_game->t3_men = position_t3_men(game->in_game->t3_men);
    sfRenderWindow_drawText(window, game->in_game->t3_men, NULL);
    game->in_game->t4_men = position_t4_men(game->in_game->t4_men);
}

void display_build(sfRenderWindow *window, stmenu_t *menu, stgame_t *game)
{
    display_build2(window, menu, game);
    sfRenderWindow_drawText(window, game->in_game->t4_men, NULL);
    game->in_game->t1_bio = position_t1_bio(game->in_game->t1_bio);
    sfRenderWindow_drawText(window, game->in_game->t1_bio, NULL);
    game->in_game->t2_bio = position_t2_bio(game->in_game->t2_bio);
    sfRenderWindow_drawText(window, game->in_game->t2_bio, NULL);
    game->in_game->t3_bio = position_t3_bio(game->in_game->t3_bio);
    sfRenderWindow_drawText(window, game->in_game->t4_bio, NULL);
    game->in_game->t4_bio = position_t4_bio(game->in_game->t4_bio);
    sfRenderWindow_drawText(window, game->in_game->t3_bio, NULL);
    sfRenderWindow_display(window);
}

void display_game3(sfRenderWindow *window, stgame_t *game, stmenu_t *menu)
{
    sfIntRect rect;

    rect = frame_zomby(game->in_game->frame, rect);
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTextureRect(game->in_game->zomby1_spr, rect);
    sfSprite_setTextureRect(game->in_game->zomby2_spr, rect);
    sfSprite_setTextureRect(game->in_game->zomby3_spr, rect);
    sfSprite_move(game->in_game->zomby1_spr, game->in_game->zomby1_m);
    sfSprite_move(game->in_game->zomby2_spr, game->in_game->zomby2_m);
    sfSprite_move(game->in_game->zomby3_spr, game->in_game->zomby3_m);
    sfRenderWindow_drawSprite(window, game->in_game->map_spr, NULL);
    game->in_game->zomby1_spr = position_sprites(game->in_game->zomby1_spr,
        game->in_game);
    sfRenderWindow_drawSprite(window, game->in_game->zomby1_spr, NULL);
    game->in_game->zomby2_spr = position_sprites(game->in_game->zomby2_spr,
        game->in_game);
}

void display_game(sfRenderWindow *window, stgame_t *game, stmenu_t *menu)
{
    display_game3(window, game, menu);
    sfRenderWindow_drawSprite(window, game->in_game->zomby2_spr, NULL);
    game->in_game->zomby3_spr = position_sprites(game->in_game->zomby3_spr,
        game->in_game);
    sfRenderWindow_drawSprite(window, game->in_game->zomby3_spr, NULL);
    display_shop(window, game->in_game);
    display_towers(window, game);
}

void display_game2(sfRenderWindow *window, stgame_t *game, stmenu_t *menu)
{
    display_game(window, game, menu);
    check_life(window, game, menu);
    if (game->in_game->tower_st == 5)
            sfRenderWindow_drawText(window, game->in_game->not_eg, NULL);
    sfText_setString(game->in_game->gold, int_to_char(game->in_game->gold_am));
    sfText_setString(game->in_game->life, int_to_char(game->in_game->life_am));
    sfText_setString(game->in_game->wave, int_to_char(game->in_game->wave_am));
    game->in_game->life = position_life(game->in_game->life);
    sfRenderWindow_drawText(window, game->in_game->life, NULL);
    game->in_game->gold = position_gold(game->in_game->gold);
    sfRenderWindow_drawText(window, game->in_game->gold, NULL);
    game->in_game->wave = position_wave(game->in_game->wave);
    sfRenderWindow_drawText(window, game->in_game->wave, NULL);
    sfRenderWindow_display(window);
}