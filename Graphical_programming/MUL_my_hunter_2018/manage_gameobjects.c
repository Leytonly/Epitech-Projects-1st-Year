/*
** EPITECH PROJECT, 2018
** manage_gameobjects.c
** File description:
** manage_gameobjects.c
*/

#include "SFML/Graphics.h"
#include "SFML/System/Vector2.h"
#include "SFML/Window/Export.h"
#include <time.h>
#include <stdlib.h>
#include "include/my.h"

void manage_mouse_click(sfMouseButtonEvent event)
{
    int pos_x;
    int pos_y;
    pos_x = event.x;
    pos_y = event.y;
    my_putstr("Hit !");
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased)
        manage_mouse_click(event.mouseButton);
}

void create_sprite(sfIntRect rect_p, gameobject_t *gameobject,
                    events_t *events)
{
    sfVideoMode mode = {1600, 1000, 32};

    gameobject->texture_bg = sfTexture_createFromFile("background.jpg", NULL);
    gameobject->texture_duck = sfTexture_createFromFile("duck.png", NULL);
    gameobject->sprite_bg = sfSprite_create();
    gameobject->sprite_duck = sfSprite_create();

    checkif_events(gameobject, events);
    sfSprite_setPosition(gameobject->sprite_duck, (sfVector2f){events->x,
                        events->y});
    sfSprite_setTexture(gameobject->sprite_bg, gameobject->texture_bg, sfTrue);
    sfSprite_setTexture(gameobject->sprite_duck, gameobject->texture_duck,
                       sfTrue);
    sfSprite_setTextureRect(gameobject->sprite_duck, rect_p);
    sfRenderWindow_clear(gameobject->window, sfBlack);
    sfRenderWindow_drawSprite(gameobject->window, gameobject->sprite_bg,
                             NULL);
    sfRenderWindow_drawSprite(gameobject->window, gameobject->sprite_duck,
                             NULL);
    sfRenderWindow_display(gameobject->window);
}

void destroy_sprites(gameobject_t *gameobject, events_t *events)
{
    sfSprite_destroy(gameobject->sprite_bg);
    sfSprite_destroy(gameobject->sprite_duck);
    sfTexture_destroy(gameobject->texture_bg);
    sfTexture_destroy(gameobject->texture_duck);
    sfRenderWindow_destroy(gameobject->window);
}