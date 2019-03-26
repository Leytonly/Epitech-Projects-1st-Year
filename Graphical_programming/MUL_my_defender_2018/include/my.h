/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>

#ifndef _MY_H_
# define _MY_H_

typedef struct towers_s
{
    sfSprite *tw1_spr;
    sfSprite *tw2_spr;
    sfSprite *tw3_spr;
    sfSprite *tw4_spr;
    sfSprite *tw5_spr;
    sfSprite *tw6_spr;
    sfSprite *tw7_spr;
    sfSprite *tw8_spr;
    sfSprite *tw9_spr;
    int tower1;
    int tower2;
    int tower3;
    int tower4;
    int tower5;
    int tower6;
    int tower7;
    int tower8;
    int tower9;
}towers_t;

typedef struct game_s
{
    sfTexture *map_txt;
    sfTexture *zomby1_txt;
    sfTexture *zomby2_txt;
    sfTexture *zomby3_txt;
    sfTexture *tower_txt;
    sfTexture *tower2_txt;
    sfTexture *tower3_txt;
    sfTexture *tower4_txt;
    sfTexture *shop_wtower_txt;
    sfTexture *shop_rtower_txt;
    sfTexture *shop_atower_txt;
    sfTexture *shop_htower_txt;
    sfSprite *map_spr;
    sfSprite *zomby1_spr;
    sfSprite *zomby2_spr;
    sfSprite *zomby3_spr;
    sfSprite *tower_spr;
    sfSprite *tower2_spr;
    sfSprite *tower3_spr;
    sfSprite *tower4_spr;
    sfSprite *shop_wtower_spr;
    sfSprite *shop_rtower_spr;
    sfSprite *shop_atower_spr;
    sfSprite *shop_htower_spr;
    sfVector2f zomby1_m;
    sfVector2f zomby2_m;
    sfVector2f zomby3_m;
    sfFont *fon;
    sfText *life;
    sfText *gold;
    sfText *t4_men;
    sfText *t3_men;
    sfText *t2_men;
    sfText *t1_men;
    sfText *t4_bio;
    sfText *t3_bio;
    sfText *t2_bio;
    sfText *t1_bio;
    sfText *not_eg;
    sfText *wave;
    sfText *info1;
    sfText *info2;
    sfText *info3;
    sfMusic* sound1;
    sfMusic* sound2;
    int frame;
    int shop_st;
    int tower_st;
    int life_am;
    float gold_am;
    int wave_am;
}game_t;

typedef struct menu_s
{
    sfTexture *bck_txt;
    sfTexture *bck_p_txt;
    sfTexture *but_txt;
    sfTexture *but_e_txt;
    sfTexture *but_s_txt;
    sfTexture *but_h_txt;
    sfSprite *but_spr;
    sfSprite *but_e_spr;
    sfSprite *but_s_spr;
    sfSprite *but_h_spr;
    sfSprite *bck_spr;
    sfSprite *bck_p_spr;
}menu_t;

typedef struct but_s {
    sfRectangleShape *rct;
    sfRectangleShape *rct_e;
    sfRectangleShape *rct_s;
    sfRectangleShape *rct_h;
}but_t;

typedef struct stmenu_s
{
    but_t *in_but;
    menu_t *in_men;
    int start_menu;
}stmenu_t;

typedef struct stgame_s
{
    game_t *in_game;
    towers_t *towers;
}stgame_t;

typedef struct scn_s
{
    stgame_t *stgame;
    stmenu_t *stmenu;
}scn_t;


void analyse_event(sfRenderWindow *window, sfEvent event,
    stmenu_t *menu, stgame_t *game);
void analyse_event2(sfRenderWindow *window, sfEvent event,
    stmenu_t *menu, stgame_t *game);
void my_putchar(char c);
void my_putstr(char *s);
void usage_func(int ac, char **av);
void display(sfRenderWindow *window, stmenu_t *menu);
char *int_to_char(int i);
int button_play_is_clicked(sfEvent event, but_t *button);
int button_exit_is_clicked(sfEvent event, but_t *button);
void load_texture(menu_t *menu, game_t *game);
void load_window(sfRenderWindow *window);
void destroy(sfRenderWindow *window, stmenu_t *menu, stgame_t *game,
    sfClock *clock);
void init_button_p(stmenu_t *menu, sfVector2f position, sfVector2f size);
void init_button_e(stmenu_t *menu, sfVector2f position, sfVector2f size);
void display_game(sfRenderWindow *window, stgame_t *game, stmenu_t *menu);
void create_sprite(menu_t *menu, game_t *game);
void set_texture(menu_t *menu, game_t *game);
void init_sprites(stmenu_t *menu, stgame_t *game);
void init_zomby1(stgame_t *game, sfVector2f position, sfVector2f scale);
void init_zomby2(stgame_t *game, sfVector2f position, sfVector2f scale);
void init_zomby3(stgame_t *game, sfVector2f position, sfVector2f scale);
void displays_scenes(sfRenderWindow *window, scn_t *scn);
void display_menu(sfRenderWindow *window, stmenu_t *menu);
void init_button_sauv(stmenu_t *menu, sfVector2f position, sfVector2f size);
void sound_destroy(sfMusic *sound);
sfMusic *add_music(sfMusic* sound);
sfIntRect frame_zomby(int frame, sfIntRect rectangle);
void clock_zomby(sfClock *clock, game_t *zomby);
game_t *moove_zomby(game_t *game);
void destroy2(sfRenderWindow *window, stmenu_t *menu, stgame_t *game,
    sfClock *clock);
sfSprite *position_sprites(sfSprite *target, game_t *game);
void follow_rode_d(game_t *game, sfVector2f size);
sfVector2f follow_path(sfSprite *target, sfVector2f vect,  sfVector2f size);
int button_towers(sfEvent event);
void load_shop_objects(game_t *game);
void display_shop(sfRenderWindow *window, game_t *game);
void set_shop_position(game_t *game);
sfText *position_life(sfText *target);
void text_init(game_t *game);
sfText *position_gold(sfText *target);
sfText *position_wave(sfText *target);
int button_menu_is_clicked(sfEvent event, but_t *button);
void init_tower(stgame_t *game, sfVector2f position, sfVector2f scale);
void init_tower2(stgame_t *game, sfVector2f position, sfVector2f scale);
void init_tower3(stgame_t *game, sfVector2f position, sfVector2f scale);
sfText *position_t1_men(sfText *target);
sfText *position_t2_men(sfText *target);
sfText *position_t3_men(sfText *target);
sfText *position_t1_bio(sfText *target);
sfText *position_t2_bio(sfText *target);
sfText *position_t3_bio(sfText *target);
sfMusic *add_mus(sfMusic* sound);
sfMusic *add_m(sfMusic* sound);
void display_game2(sfRenderWindow *window, stgame_t *game, stmenu_t *menu);
void display_build(sfRenderWindow *window, stmenu_t *menu, stgame_t *game);
void display(sfRenderWindow *window, stmenu_t *menu);
int button_h_is_clicked(sfEvent event, but_t *button);
void display_h(sfRenderWindow *window, stmenu_t *menu, stgame_t *game);
int set_tower_status(game_t *game, int x, int y);
void place_towers(sfRenderWindow *window, stgame_t *game, sfEvent event);
void display_towers(sfRenderWindow *window, stgame_t *game);
void set_tower(sfRenderWindow *window, stgame_t *game, sfVector2f pos,
    sfSprite *sprite);
void create_tower_sprites(stgame_t *game);
void place_towers2(sfRenderWindow *window, stgame_t *game, int x, int y);
int tower_shop(sfRenderWindow *window, sfEvent event, game_t *game);
sfText *position_info1(sfText *target);
sfText *position_info2(sfText *target);
sfText *position_info3(sfText *target);
sfText *position_t4_bio(sfText *target);
sfText *position_t4_men(sfText *target);
void init_tower4(stgame_t *game, sfVector2f position, sfVector2f scale);
void display_menu(sfRenderWindow *window, stmenu_t *menu);
void shop_text_init(game_t* game);
int check_life(sfRenderWindow *window, stgame_t *game, stmenu_t *menu);

#endif