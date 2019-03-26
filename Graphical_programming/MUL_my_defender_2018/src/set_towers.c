/*
** EPITECH PROJECT, 2018
** manage_shop.c
** File description:
** manage the shop for the towers
*/

#include "my.h"

void check_tower(sfRenderWindow *window, stgame_t *game, sfVector2f pos,
    sfSprite *sprite)
{
    sfTexture *archer = sfTexture_createFromFile("sprites/tower_archer.png",
        NULL);
    sfTexture *holy = sfTexture_createFromFile("sprites/tower_holy.png",
        NULL);
    if (game->in_game->tower_st == 1) {
        sfSprite_setTexture(sprite, archer, sfTrue);
        game->in_game->gold_am -= 30;
        game->towers->tower1 = 1;
    }
    if (game->in_game->tower_st == 4) {
        sfSprite_setTexture(sprite, holy, sfTrue);
        game->in_game->gold_am -= 150;
        game->towers->tower1 = 4;
    }
}

void set_tower(sfRenderWindow *window, stgame_t *game, sfVector2f pos,
    sfSprite *sprite)
{
    sfTexture *rock = sfTexture_createFromFile("sprites/tower_rock.png",
        NULL);
    sfTexture *wizard = sfTexture_createFromFile("sprites/tower_wizard.png",
        NULL);
    if (game->in_game->tower_st == 2) {
        game->in_game->gold_am -= 70;
        sfSprite_setTexture(sprite, wizard, sfTrue);
        game->towers->tower1 = 2;
    }
    if (game->in_game->tower_st == 3) {
        sfSprite_setTexture(sprite, rock, sfTrue);
        game->in_game->gold_am -= 50;
        game->towers->tower1 = 3;
    }
    check_tower(window, game, pos, sprite);
    sfSprite_setPosition(sprite, pos);
}

void display_towers(sfRenderWindow *window, stgame_t *game)
{
    if (game->towers->tower1 != 0);
        sfRenderWindow_drawSprite(window, game->towers->tw1_spr, NULL);
    if (game->towers->tower2 != 0);
        sfRenderWindow_drawSprite(window, game->towers->tw2_spr, NULL);
    if (game->towers->tower3 != 0);
        sfRenderWindow_drawSprite(window, game->towers->tw3_spr, NULL);
    if (game->towers->tower4 != 0);
        sfRenderWindow_drawSprite(window, game->towers->tw4_spr, NULL);
    if (game->towers->tower5 != 0);
        sfRenderWindow_drawSprite(window, game->towers->tw5_spr, NULL);
    if (game->towers->tower6 != 0);
        sfRenderWindow_drawSprite(window, game->towers->tw6_spr, NULL);
    if (game->towers->tower7 != 0);
        sfRenderWindow_drawSprite(window, game->towers->tw7_spr, NULL);
    if (game->towers->tower8 != 0);
        sfRenderWindow_drawSprite(window, game->towers->tw8_spr, NULL);
    if (game->towers->tower9 != 0);
        sfRenderWindow_drawSprite(window, game->towers->tw9_spr, NULL);
}