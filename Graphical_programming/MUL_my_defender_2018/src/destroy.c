/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"

void destroy(sfRenderWindow *window, stmenu_t *menu, stgame_t *game,
    sfClock *clock)
{
    sfSprite_destroy(menu->in_men->bck_spr);
    sfSprite_destroy(menu->in_men->bck_p_spr);
    sfSprite_destroy(menu->in_men->but_spr);
    sfSprite_destroy(menu->in_men->but_e_spr);
    sfSprite_destroy(menu->in_men->but_s_spr);
    sfSprite_destroy(menu->in_men->but_h_spr);
    sfSprite_destroy(game->in_game->map_spr);
    sfSprite_destroy(game->in_game->zomby1_spr);
    sfSprite_destroy(game->in_game->zomby2_spr);
    sfSprite_destroy(game->in_game->zomby3_spr);
    sfSprite_destroy(game->in_game->tower_spr);
    sfTexture_destroy(menu->in_men->bck_txt);
    sfTexture_destroy(menu->in_men->bck_p_txt);
    sfTexture_destroy(menu->in_men->but_txt);
    sfTexture_destroy(menu->in_men->but_e_txt);
    sfTexture_destroy(menu->in_men->but_s_txt);
    sfTexture_destroy(menu->in_men->but_h_txt);
    sfTexture_destroy(game->in_game->map_txt);
    sfTexture_destroy(game->in_game->zomby1_txt);
    destroy2(window, menu, game, clock);
}

void destroy2(sfRenderWindow *window, stmenu_t *menu, stgame_t *game,
    sfClock *clock)
{
    sfTexture_destroy(game->in_game->zomby2_txt);
    sfTexture_destroy(game->in_game->zomby3_txt);
    sfRectangleShape_destroy(menu->in_but->rct);
    sfRectangleShape_destroy(menu->in_but->rct_e);
    sfRectangleShape_destroy(menu->in_but->rct_s);
    sfRectangleShape_destroy(menu->in_but->rct_h);
    sfTexture_destroy(game->in_game->tower_txt);
    sfTexture_destroy(game->in_game->tower2_txt);
    sfTexture_destroy(game->in_game->tower3_txt);
    sfTexture_destroy(game->in_game->tower4_txt);
    sfSprite_destroy(game->in_game->tower2_spr);
    sfSprite_destroy(game->in_game->tower3_spr);
    sfSprite_destroy(game->in_game->tower4_spr);
    sfClock_destroy(clock);
}