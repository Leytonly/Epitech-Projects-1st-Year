/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"
#include <stdio.h>

int button_play_is_clicked(sfEvent event, but_t *button)
{
    sfVector2f target_pos;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    target_pos = sfRectangleShape_getPosition(button->rct);
    if (x >= target_pos.x + 85 &&
        x <= target_pos.x + 520 &&
        y >= target_pos.y + 55 &&
        y <= target_pos.y + 295)
        return (1);
    return (0);
}

int button_exit_is_clicked(sfEvent event, but_t *button)
{
    sfVector2f target_pos;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    target_pos = sfRectangleShape_getPosition(button->rct_e);
    if (x >= target_pos.x + 85 &&
        x <= target_pos.x + 520 &&
        y >= target_pos.y + 55 &&
        y <= target_pos.y + 295)
        return (1);
    return (0);
}

int button_menu_is_clicked(sfEvent event, but_t *button)
{
    sfVector2f target_pos;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    target_pos = sfRectangleShape_getPosition(button->rct_s);
    if (x >= target_pos.x + 85 &&
        x <= target_pos.x + 520 &&
        y >= target_pos.y + 55 &&
        y <= target_pos.y + 295)
        return (1);
    return (0);
}

int button_h_is_clicked(sfEvent event, but_t *button)
{
    sfVector2f target_pos;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    target_pos = sfRectangleShape_getPosition(button->rct_h);
    if (x >= target_pos.x + 85 &&
        x <= target_pos.x + 520 &&
        y >= target_pos.y + 55 &&
        y <= target_pos.y + 295)
        return (1);
    return (0);
}

int button_towers(sfEvent event)
{
    sfVector2f target_pos;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if (x >= 1399 && x <= 1504 && y >= 285 && y <= 332 ||
        x >= 1387 && x <= 1494 && y >= 748 && y <= 792 ||
        x >= 1291 && x <= 1396 && y >= 648 && y <= 698 ||
        x >= 1061 && x <= 1170 && y >= 769 && y <= 816 ||
        x >= 1028 && x <= 1134 && y >= 555 && y <= 615 ||
        x >= 817 && x <= 921 && y >= 558 && y <= 610 ||
        x >= 650 && x <= 753 && y >= 428 && y <= 479 ||
        x >= 437 && x <= 542 && y >= 585 && y <= 636 ||
        x >= 585 && x <= 693 && y >= 665 && y <= 720) {
        return (1);
    }
    return (0);
}