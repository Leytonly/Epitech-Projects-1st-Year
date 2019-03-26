/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"

void load_texture(menu_t *menu, game_t *game)
{
    game->map_txt = sfTexture_createFromFile("sprites/test_map.png", NULL);
    game->zomby1_txt = sfTexture_createFromFile("sprites/zomby.png", NULL);
    game->zomby2_txt = sfTexture_createFromFile("sprites/zomby.png", NULL);
    game->zomby3_txt = sfTexture_createFromFile("sprites/zomby.png", NULL);
    game->tower_txt = sfTexture_createFromFile("sprites/tower_archer.png",
        NULL);
    game->tower2_txt = sfTexture_createFromFile("sprites/tower_rock.png",
        NULL);
    game->tower3_txt = sfTexture_createFromFile("sprites/tower_wizard.png",
        NULL);
    game->tower4_txt = sfTexture_createFromFile("sprites/tower_holy.png",
        NULL);
    menu->bck_txt = sfTexture_createFromFile("sprites/menu.jpg", NULL);
    menu->bck_p_txt = sfTexture_createFromFile("sprites/menu_pause.jpg", NULL);
    menu->but_txt = sfTexture_createFromFile("sprites/mouse_on_button.png",
        NULL);
    menu->but_e_txt = sfTexture_createFromFile("sprites/button_e.png", NULL);
    menu->but_s_txt = sfTexture_createFromFile("sprites/button_e.png",
    NULL);
    menu->but_h_txt = sfTexture_createFromFile("sprites/info.png", NULL);
}

void create_sprite(menu_t *menu, game_t *game)
{
    game->map_spr = sfSprite_create();
    game->zomby1_spr = sfSprite_create();
    game->zomby2_spr = sfSprite_create();
    game->zomby3_spr = sfSprite_create();
    game->tower_spr = sfSprite_create();
    game->tower2_spr = sfSprite_create();
    game->tower3_spr = sfSprite_create();
    game->tower4_spr = sfSprite_create();
    menu->bck_spr = sfSprite_create();
    menu->bck_p_spr = sfSprite_create();
    menu->but_spr = sfSprite_create();
    menu->but_e_spr = sfSprite_create();
    menu->but_s_spr = sfSprite_create();
    menu->but_h_spr = sfSprite_create();
    text_init(game);
}

void set_texture(menu_t *menu, game_t *game)
{
    load_texture(menu, game);
    create_sprite(menu, game);
    load_shop_objects(game);
    sfSprite_setTexture(game->map_spr, game->map_txt, sfTrue);
    sfSprite_setTexture(game->zomby1_spr, game->zomby1_txt, sfTrue);
    sfSprite_setTexture(game->zomby2_spr, game->zomby2_txt, sfTrue);
    sfSprite_setTexture(game->zomby3_spr, game->zomby3_txt, sfTrue);
    sfSprite_setTexture(game->tower_spr, game->tower_txt, sfTrue);
    sfSprite_setTexture(game->tower2_spr, game->tower2_txt, sfTrue);
    sfSprite_setTexture(game->tower3_spr, game->tower3_txt, sfTrue);
    sfSprite_setTexture(game->tower4_spr, game->tower4_txt, sfTrue);
    sfSprite_setTexture(menu->bck_spr, menu->bck_txt, sfTrue);
    sfSprite_setTexture(menu->bck_p_spr, menu->bck_p_txt, sfTrue);
    sfSprite_setTexture(menu->but_spr, menu->but_txt, sfTrue);
    sfSprite_setTexture(menu->but_e_spr, menu->but_e_txt, sfTrue);
    sfSprite_setTexture(menu->but_s_spr, menu->but_s_txt, sfTrue);
    sfSprite_setTexture(menu->but_h_spr, menu->but_h_txt, sfTrue);
}

void load_window(sfRenderWindow *window)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    scn_t *scn = malloc(sizeof(scn_t));
    scn->stmenu = malloc(sizeof(stmenu_t));
    scn->stgame = malloc(sizeof(stgame_t));
    scn->stgame->in_game = malloc(sizeof(game_t));
    scn->stmenu->in_but = malloc(sizeof(but_t));
    scn->stmenu->in_men = malloc(sizeof(menu_t));
    scn->stgame->towers = malloc(sizeof(towers_t));

    scn->stmenu->start_menu = 0;
    set_texture(scn->stmenu->in_men, scn->stgame->in_game);
    init_sprites(scn->stmenu, scn->stgame);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_event(window, event, scn->stmenu, scn->stgame);
            displays_scenes(window, scn);
        clock_zomby(clock, scn->stgame->in_game);
    }
    destroy(window, scn->stmenu, scn->stgame, clock);
    free(scn);
}