/*
** EPITECH PROJECT, 2018
** text.c
** File description:
** text
*/

#include <stdio.h>
#include "my.h"

sfText *position_t1_men(sfText *target)
{
    sfVector2f pos;

    pos.x = 100;
    pos.y = 50;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_t2_men(sfText *target)
{
    sfVector2f pos;

    pos.x = 1100;
    pos.y = 50;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_t3_men(sfText *target)
{
    sfVector2f pos;

    pos.x = 600;
    pos.y = 50;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_life(sfText *target)
{
    sfVector2f pos;

    pos.x = 100;
    pos.y = 10;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_gold(sfText *target)
{
    sfVector2f pos;

    pos.x = 175;
    pos.y = 10;
    sfText_setPosition(target, pos);
    return (target);
}