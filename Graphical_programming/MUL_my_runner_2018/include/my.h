/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio/Music.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Graphics/Sprite.h>
#include "SFML/Window.h"



typedef struct gameobject {
    sfTexture *tx_player;
    sfTexture *tx_fg;
    sfTexture *tx_sand;
    sfTexture *tx_bg;
    sfTexture *tx_fg2;
    sfTexture *tx_sand2;
    sfTexture *tx_bg2;
    sfTexture *tx_shark;
    sfSprite *sp_player;
    sfSprite *sp_fg;
    sfSprite *sp_sand;
    sfSprite *sp_bg;
    sfSprite *sp_fg2;
    sfSprite *sp_sand2;
    sfSprite *sp_bg2;
    sfSprite *sp_shark;
    sfRenderWindow *window;
}gameobjects_t;

typedef struct events {
    sfEvent event;
    sfClock *clock;
    sfClock *clock_player;
    sfClock *clock_jump;
    sfTime time;
    float seconds;
    sfMusic *music;
    sfFont *font;
    sfText *score;
}events_t;

typedef struct move {
    sfVector2f ofst_far;
    sfVector2f ofst_sand;
    sfVector2f ofst_fg;
    sfVector2f ofst_player;
    sfVector2f ofst_far_plx;
    sfVector2f ofst_sand_plx;
    sfVector2f ofst_fg_plx;
}move_t;

void manage_mouse_click(sfMouseButtonEvent event);
void my_putchar(char c);
void my_putstr(char const *str);
sfIntRect int_rect_p(void);
sfIntRect int_rect_sh(void);
sfMusic *play_music(sfMusic *music);
gameobjects_t *init_runner(gameobjects_t *gameobj, move_t *move,
                           sfIntRect rect_p, sfIntRect rect_sh);
void destroy_runner(gameobjects_t *gameobj, events_t *events, move_t *move);
sfIntRect move_rect(gameobjects_t *gameobj, events_t *events, sfIntRect rect_p);
void analyse_events(sfRenderWindow *window, sfEvent event);
void checkif_events(gameobjects_t *gameobj, events_t *events, move_t *move,
                    sfIntRect rect_p);
void set_scale(gameobjects_t *gameobj, sfIntRect rect_p, sfIntRect rect_sh);
void init_parallax(gameobjects_t *gameobj, move_t *move);
void check_parallax(gameobjects_t *gameobj, move_t *move);
events_t *start_events(events_t *events);
void set_parallax(sfSprite *sprite);
void set_parallax_fg(sfSprite *sprite);
void set_texture(gameobjects_t *gameobj);
void set_shark(sfSprite *sprite);
move_t *set_offset(move_t *move);
void set_score(sfRenderWindow *window, events_t *events);
void player_jump(events_t *events, gameobjects_t *gameobj, move_t *move);
void create_sprite(gameobjects_t *gameobj, sfIntRect rect_p,
                   sfIntRect rect_sh);
void draw_sprites(gameobjects_t *gameobj);
void move_sprites(gameobjects_t *gameobj, move_t *move, events_t *events);
void game_start(gameobjects_t *gameobj, events_t *events);
gameobjects_t *create_sp_prlx(gameobjects_t *gameobj, sfTexture *tx_parallax,
                            sfSprite *sp_parallax, char *file);


#endif