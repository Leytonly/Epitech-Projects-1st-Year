/*
** EPITECH PROJECT, 2018
** text.c
** File description:
** text
*/

#include <stdio.h>
#include "my.h"

sfText *position_info2(sfText *target)
{
    sfVector2f pos;

    pos.x = 75;
    pos.y = 450;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_info3(sfText *target)
{
    sfVector2f pos;

    pos.x = 75;
    pos.y = 750;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_t4_bio(sfText *target)
{
    sfVector2f pos;

    pos.x = 1480;
    pos.y = 700;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_t4_men(sfText *target)
{
    sfVector2f pos;

    pos.x = 1600;
    pos.y = 50;
    sfText_setPosition(target, pos);
    return (target);
}