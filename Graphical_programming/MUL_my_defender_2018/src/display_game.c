/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"

void display(sfRenderWindow *window, stmenu_t *menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->in_men->bck_spr, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->in_but->rct, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->in_but->rct_s, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->in_but->rct_e, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->in_but->rct_h, NULL);
    sfRenderWindow_display(window);
}

void display_menu(sfRenderWindow *window, stmenu_t *menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->in_men->bck_p_spr, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->in_but->rct, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->in_but->rct_s, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->in_but->rct_e, NULL);
    sfRenderWindow_display(window);
}

void display_h(sfRenderWindow *window, stmenu_t *menu, stgame_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->in_men->bck_spr, NULL);
    game->in_game->info1 = position_info1(game->in_game->info1);
    sfRenderWindow_drawText(window, game->in_game->info1, NULL);
    game->in_game->info2 = position_info2(game->in_game->info2);
    sfRenderWindow_drawText(window, game->in_game->info2, NULL);
    game->in_game->info3 = position_info3(game->in_game->info3);
    sfRenderWindow_drawText(window, game->in_game->info3, NULL);
    sfRenderWindow_display(window);
}

void displays_scenes(sfRenderWindow *window, scn_t *scn)
{
    if (scn->stmenu->start_menu == 0)
        display(window, scn->stmenu);
    if (scn->stmenu->start_menu == 1) {
        display_game2(window, scn->stgame, scn->stmenu);
        scn->stgame->in_game->gold_am += 0.15;
    }
    if (scn->stmenu->start_menu == 2)
        display_menu(window, scn->stmenu);
    if (scn->stmenu->start_menu == 3)
        display_build(window, scn->stmenu, scn->stgame);
    if (scn->stmenu->start_menu == 4)
        display_h(window, scn->stmenu, scn->stgame);
}