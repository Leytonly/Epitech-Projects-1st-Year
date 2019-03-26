/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"
#include <stdio.h>

void init_button_p(stmenu_t *menu, sfVector2f position, sfVector2f size)
{
    menu->in_but->rct = sfRectangleShape_create();
    sfRectangleShape_setPosition(menu->in_but->rct, position);
    sfRectangleShape_setSize(menu->in_but->rct, size);
    sfRectangleShape_setTexture(menu->in_but->rct, menu->in_men->but_txt,
        sfTrue);
}

void init_button_e(stmenu_t *menu, sfVector2f position, sfVector2f size)
{
    menu->in_but->rct_e = sfRectangleShape_create();
    sfRectangleShape_setPosition(menu->in_but->rct_e, position);
    sfRectangleShape_setSize(menu->in_but->rct_e, size);
    sfRectangleShape_setTexture(menu->in_but->rct_e, menu->in_men->but_e_txt,
        sfTrue);
}

void init_button_s(stmenu_t *menu, sfVector2f position, sfVector2f size)
{
    menu->in_but->rct_s = sfRectangleShape_create();
    sfRectangleShape_setPosition(menu->in_but->rct_s, position);
    sfRectangleShape_setSize(menu->in_but->rct_s, size);
    sfRectangleShape_setTexture(menu->in_but->rct_s, menu->in_men->but_s_txt,
        sfTrue);
}

void init_button_h(stmenu_t *menu, sfVector2f position, sfVector2f size)
{
    menu->in_but->rct_h = sfRectangleShape_create();
    sfRectangleShape_setPosition(menu->in_but->rct_h, position);
    sfRectangleShape_setSize(menu->in_but->rct_h, size);
    sfRectangleShape_setTexture(menu->in_but->rct_h, menu->in_men->but_h_txt,
        sfTrue);
}

void init_sprites(stmenu_t *menu, stgame_t *game)
{
    create_tower_sprites(game);
    init_button_p(menu, (sfVector2f){650, 0}, (sfVector2f){650, 350});
    init_button_e(menu, (sfVector2f){650, 600}, (sfVector2f){650, 350});
    init_button_s(menu, (sfVector2f){650, 300}, (sfVector2f){650, 350});
    init_button_h(menu, (sfVector2f){50, 300}, (sfVector2f){650, 350});
    init_zomby1(game, (sfVector2f){2500, 840}, (sfVector2f){1.25, 1.25});
    init_zomby2(game, (sfVector2f){2700, 840}, (sfVector2f){1.25, 1.25});
    init_zomby3(game, (sfVector2f){2900, 840}, (sfVector2f){1.25, 1.25});
    init_tower(game, (sfVector2f){550, 250}, (sfVector2f){3, 3});
    init_tower2(game, (sfVector2f){1000, 250}, (sfVector2f){3, 3});
    init_tower3(game, (sfVector2f){100, 250}, (sfVector2f){3, 3});
    init_tower4(game, (sfVector2f){1500, 200}, (sfVector2f){3, 3});
}