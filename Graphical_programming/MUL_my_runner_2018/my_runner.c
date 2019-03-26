/*
** EPITECH PROJECT, 2019
** my_runner.c
** File description:
** my_runner.c
*/

#include "include/my.h"

events_t *start_events(events_t *events)
{
    events->music = play_music(events->music);
    events->clock = sfClock_create();
    events->clock_player = sfClock_create();
    events->clock_jump = sfClock_create();
    return (events);
}

gameobjects_t *init_runner(gameobjects_t *gameobj, move_t *move,
                           sfIntRect rect_p, sfIntRect rect_sh)
{
    create_sprite(gameobj, rect_p, rect_sh);
    init_parallax(gameobj, move);
    return (gameobj);
}

void destroy_runner(gameobjects_t *gameobj, events_t *events, move_t *move)
{
    sfSprite_destroy(gameobj->sp_bg);
    sfSprite_destroy(gameobj->sp_bg2);
    sfSprite_destroy(gameobj->sp_fg);
    sfSprite_destroy(gameobj->sp_fg2);
    sfSprite_destroy(gameobj->sp_sand);
    sfSprite_destroy(gameobj->sp_sand2);
    sfSprite_destroy(gameobj->sp_player);
    sfMusic_destroy(events->music);
    free(gameobj);
    free(events);
    free(move);
}

sfMusic* play_music(sfMusic* music)
{
    const char *file = "music.wav";

    music = sfMusic_createFromFile(file);
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    return (music);
}

void game_start(gameobjects_t *gameobj, events_t *events)
{
    sfVideoMode mode = {1357, 979, 32};
    move_t *move = malloc(sizeof(move_t));
    sfIntRect rect_p = int_rect_p();
    sfIntRect rect_sh = int_rect_sh();

    gameobj->window = sfRenderWindow_create(mode, "My_runner", sfResize |
                                            sfClose, NULL);
    sfRenderWindow_setFramerateLimit(gameobj->window, 60);
    gameobj = init_runner(gameobj, move, rect_p, rect_sh);
    start_events(events);
    while (sfRenderWindow_isOpen(gameobj->window)) {
        checkif_events(gameobj, events, move, rect_p);
        rect_p = move_rect(gameobj, events, rect_p);
        move_sprites(gameobj, move, events);
        player_jump(events, gameobj, move);
        set_score(gameobj->window, events);
        sfRenderWindow_drawText(gameobj->window, events->score, NULL);
    }
    destroy_runner(gameobj, events, move);
}
