/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>

typedef struct gameobject {
    sfSprite *sprite_bg;
    sfSprite *sprite_duck;
    sfTexture *texture_bg;
    sfTexture *texture_duck;
    sfRenderWindow *window;
}gameobject_t;

typedef struct events {
    float pos_x;
    float pos_y;
    float x;
    float y;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds;
}events_t;

typedef struct framebuffer {
    int width;
    int height;
    sfUint8 *pixels;
}framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void game_start(gameobject_t *gameobject, framebuffer_t *framebuffer,
               events_t *events);
void create_sprite(sfIntRect rect, gameobject_t *gameobject,
               events_t *events);
void destroy_sprites(gameobject_t *gameobject, events_t *events);
sfIntRect int_rect(sfRenderWindow* window);
sfIntRect move_rect(sfRenderWindow *window, events_t *events, sfIntRect rect);
void my_putchar(char c);
void analyse_events(sfRenderWindow *window, sfEvent event);
void manage_mouse_click(sfMouseButtonEvent event);
void checkif_events(gameobject_t *gameobject, events_t *events);
int my_putstr(char const *str);


#endif