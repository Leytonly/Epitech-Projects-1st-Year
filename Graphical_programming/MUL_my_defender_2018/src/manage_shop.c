/*
** EPITECH PROJECT, 2018
** manage_shop.c
** File description:
** manage the shop for the towers
*/

#include "my.h"

int tower_shop(sfRenderWindow *window, sfEvent event, game_t *game)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if (game->shop_st == 1) {
        game->tower_st = set_tower_status(game, x, y);
        return (2);
    }
    if (x >= 0 && x <= 285 && y >= 787 && y <= 972 ||
        x >= 49 && x <= 230 && y >= 737 && y <= 785 && game->shop_st != 1) {
            return (1);
    }
    return (0);

}

void display_shop(sfRenderWindow *window, game_t *game)
{
    if (game->shop_st == 1) {
        sfRenderWindow_drawSprite(window, game->shop_atower_spr, NULL);
        sfRenderWindow_drawSprite(window, game->shop_rtower_spr, NULL);
        sfRenderWindow_drawSprite(window, game->shop_wtower_spr, NULL);
        sfRenderWindow_drawSprite(window, game->shop_htower_spr, NULL);
    }
}

int set_tower_status(game_t *game, int x, int y)
{
    if (x >= 159 && x <= 270 && y >= 620 && y <= 722 && game->gold_am >= 30)
        return (1);
    else if (x >= 159 && x <= 270 && y >= 620 && y <= 722 &&
        game->gold_am <= 30)
        return (5);
    if (x >= 303 && x <= 408 && y >= 710 && y <= 816 && game->gold_am >= 70)
        return (2);
    else if (x >= 303 && x <= 408 && y >= 710 && y <= 816 &&
        game->gold_am <= 70)
        return (5);
    if (x >= 352 && x <= 459 && y >= 859 && y <= 963 && game->gold_am >= 50)
        return (3);
    else if (x >= 352 && x <= 459 && y >= 859 && y <= 963 &&
        game->gold_am <= 50)
        return (5);
    if (x >= 15 && x <= 120 && y >= 603 && y <= 712 && game->gold_am >= 150)
        return (4);
    else if (x >= 15 && x <= 120 && y >= 603 && y <= 712 &&
        game->gold_am <= 150)
        return (5);
    return (0);
}

void place_towers(sfRenderWindow *window, stgame_t *game, sfEvent event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if (x >= 437 && x <= 542 && y >= 585 && y <= 636)
        set_tower(window, game, (sfVector2f){422, 545}, game->towers->tw1_spr);
    if (x >= 585 && x <= 693 && y >= 665 && y <= 720)
        set_tower(window, game, (sfVector2f){575, 630}, game->towers->tw2_spr);
    if (x >= 650 && x <= 753 && y >= 428 && y <= 479)
        set_tower(window, game, (sfVector2f){635, 390}, game->towers->tw3_spr);
    if (x >= 817 && x <= 921 && y >= 558 && y <= 610)
        set_tower(window, game, (sfVector2f){800, 518}, game->towers->tw4_spr);
    if (x >= 1028 && x <= 1134 && y >= 555 && y <= 615)
        set_tower(window, game, (sfVector2f){1015, 520},
            game->towers->tw5_spr);
    if (x >= 1061 && x <= 1170 && y >= 769 && y <= 816)
        set_tower(window, game, (sfVector2f){1045, 720},
            game->towers->tw6_spr);
    place_towers2(window, game, x, y);
}

void place_towers2(sfRenderWindow *window, stgame_t *game, int x, int y)
{
    if (x >= 1291 && x <= 1396 && y >= 648 && y <= 698)
        set_tower(window, game, (sfVector2f){1277, 604},
            game->towers->tw7_spr);
    if (x >= 1387 && x <= 1494 && y >= 748 && y <= 792)
        set_tower(window, game, (sfVector2f){1370, 706},
            game->towers->tw8_spr);
    if (x >= 1399 && x <= 1504 && y >= 285 && y <= 332)
        set_tower(window, game, (sfVector2f){1388, 242},
            game->towers->tw9_spr);
}