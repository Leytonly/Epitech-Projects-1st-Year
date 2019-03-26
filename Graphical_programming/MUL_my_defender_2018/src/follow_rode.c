/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"
#include <stdio.h>

sfVector2f follow_rode1(sfSprite *target, sfVector2f vect,  sfVector2f size)
{
    size = sfSprite_getPosition(target);
    if (size.x <= 1370)
        vect.y = -4;
    size = sfSprite_getPosition(target);
    if (size.y <= 680)
        vect.y = 0;
    return (vect);
}

sfVector2f follow_rode2(sfSprite *target, sfVector2f vect,  sfVector2f size)
{
    size = sfSprite_getPosition(target);
    if (size.x <= 825)
        vect.y = -3.5;
    size = sfSprite_getPosition(target);
    if (size.y <= 450)
        vect.y = 0;
    return (vect);
}

sfVector2f follow_rode3(sfSprite *target, sfVector2f vect,  sfVector2f size)
{
    size = sfSprite_getPosition(target);
    if (size.x <= 800 && size.y <= 450)
        vect.y = +4;
    size = sfSprite_getPosition(target);
    if (size.x <= 550)
        vect.y = 0;
    return (vect);
}

sfVector2f follow_rode4(sfSprite *target, sfVector2f vect,  sfVector2f size)
{
    size = sfSprite_getPosition(target);
    if (size.x <= 400)
        vect.y = +4;
    size = sfSprite_getPosition(target);
    if (size.x <= 300)
        vect.y = 0;
    return (vect);
}

sfVector2f follow_path(sfSprite *target, sfVector2f vect,  sfVector2f size)
{
    vect = follow_rode1(target, vect, size);
    vect = follow_rode2(target, vect, size);
    vect = follow_rode3(target, vect, size);
    vect = follow_rode4(target, vect, size);
    return (vect);
}