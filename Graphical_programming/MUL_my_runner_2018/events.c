/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events.c
*/

#include "include/my.h"

void manage_mouse_click(sfMouseButtonEvent event)
{
    int pos_x;
    int pos_y;
    pos_x = event.x;
    pos_y = event.y;
}

void checkif_events(gameobjects_t *gameobj, events_t *events, move_t *move,
                    sfIntRect rect_p)
{
    while (sfRenderWindow_pollEvent(gameobj->window, &events->event)) {
        if (events->event.type == sfEvtClosed)
            sfRenderWindow_close(gameobj->window);
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            sfSprite_move(gameobj->sp_player, (sfVector2f){0, -5.5});
            move_sprites(gameobj, move, events);
        }
    }
}

void player_jump(events_t *events, gameobjects_t *gameobj, move_t *move)
{
    events->time = sfClock_getElapsedTime(events->clock_jump);
    events->seconds = events->time.microseconds / 1000000.0;
    sfVector2f player_pos;

    if (events->seconds > 0.05) {
        player_pos = sfSprite_getPosition(gameobj->sp_player);
        if (player_pos.y < 790)
            sfSprite_move(gameobj->sp_player, (sfVector2f){0, 5});
            move_sprites(gameobj, move, events);
            sfClock_restart(events->clock_jump);
    }
}

void set_score(sfRenderWindow *window, events_t *events)
{
    events->font = sfFont_createFromFile("font.ttf");
    events->score = sfText_create();
    sfText_setString(events->score, "Score :");
    sfText_setFont(events->score, events->font);
    sfText_setCharacterSize(events->score, 50);
    sfText_setColor(events->score, sfWhite);
    sfText_setPosition(events->score, (sfVector2f){500, 500});
}