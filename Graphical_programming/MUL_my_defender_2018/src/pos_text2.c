/*
** EPITECH PROJECT, 2018
** text.c
** File description:
** text
*/

#include <stdio.h>
#include "my.h"

sfText *position_wave(sfText *target)
{
    sfVector2f pos;

    pos.x = 350;
    pos.y = 10;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_t1_bio(sfText *target)
{
    sfVector2f pos;

    pos.x = 100;
    pos.y = 700;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_t2_bio(sfText *target)
{
    sfVector2f pos;

    pos.x = 1050;
    pos.y = 700;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_t3_bio(sfText *target)
{
    sfVector2f pos;

    pos.x = 600;
    pos.y = 700;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_info1(sfText *target)
{
    sfVector2f pos;

    pos.x = 75;
    pos.y = 150;
    sfText_setPosition(target, pos);
    return (target);
}