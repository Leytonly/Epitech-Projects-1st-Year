/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"
#include <stdio.h>

void analyse_event(sfRenderWindow *window, sfEvent event,
    stmenu_t *menu, stgame_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.key.code == sfKeyEscape && (menu->start_menu == 1)) {
        menu->start_menu = 2;
    }
    if ((event.key.code == sfKeyEscape) && ((menu->start_menu == 3) ||
        (menu->start_menu == 4))) {
        menu->start_menu = 0;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        analyse_event2(window, event, menu, game);
    }
}

void analyse_event2(sfRenderWindow *window, sfEvent event,
    stmenu_t *menu, stgame_t *game)
{
    if ((button_play_is_clicked(event, menu->in_but) == 1) &&
        ((menu->start_menu == 0) || (menu->start_menu == 2))) {
        game->in_game->sound1 = add_m(game->in_game->sound1);
        menu->start_menu = 1;
    }
    if ((button_menu_is_clicked(event, menu->in_but) == 1) &&
        (menu->start_menu == 2))
        sfRenderWindow_close(window);
    if ((button_menu_is_clicked(event, menu->in_but) == 1) &&
        (menu->start_menu == 0))
        menu->start_menu = 3;
    if ((button_towers(event) == 1) && (menu->start_menu == 1) &&
        game->in_game->shop_st == 2)
        place_towers(window, game, event);
    if ((button_h_is_clicked(event, menu->in_but) == 1) &&
        (menu->start_menu == 0))
        menu->start_menu = 4;
    if ((button_exit_is_clicked(event, menu->in_but) == 1) &&
        ((menu->start_menu == 2) || (menu->start_menu == 0)))
        sfRenderWindow_close(window);
    game->in_game->shop_st = tower_shop(window, event, game->in_game);
}

int check_life(sfRenderWindow *window, stgame_t *game, stmenu_t *menu)
{
    sfVector2f pos = sfSprite_getPosition(game->in_game->zomby1_spr);
    sfVector2f pos2 = sfSprite_getPosition(game->in_game->zomby2_spr);
    sfVector2f pos3 = sfSprite_getPosition(game->in_game->zomby3_spr);

    if (pos.x < 20) {
        game->in_game->life_am -= 1;
    }
    if (pos2.x < 20) {
        game->in_game->life_am -= 1;
    }
    if (pos3.x < 20) {
        game->in_game->life_am -= 1;
    }
    if (pos.x < 20) {
        game->in_game->wave_am += 1;
    }
    
}