/*
** EPITECH PROJECT, 2018
** text.c
** File description:
** text
*/

#include <stdio.h>
#include "my.h"

void shop_text_init(game_t *game)
{
    game->not_eg = sfText_create();
    sfText_setFont(game->not_eg, game->fon);
    sfText_setCharacterSize(game->not_eg, 80);
    sfText_setColor(game->not_eg, sfWhite);
    sfText_setString(game->not_eg, "Not enough gold");
    sfText_setPosition(game->not_eg, (sfVector2f){630, 900});
}

void text4_init(game_t *game)
{
    sfText_setString(game->t3_men, "ARCHER");
    sfText_setString(game->t4_men, "HOLY");
    sfText_setFont(game->life, game->fon);
    sfText_setFont(game->gold, game->fon);
    sfText_setFont(game->wave, game->fon);
    sfText_setFont(game->t1_men, game->fon);
    sfText_setFont(game->info2, game->fon);
    sfText_setFont(game->info3, game->fon);
    sfText_setCharacterSize(game->t1_bio, 50);
    sfText_setCharacterSize(game->t2_bio, 50);
    sfText_setCharacterSize(game->t3_bio, 50);
    sfText_setCharacterSize(game->t4_bio, 50);
    sfText_setCharacterSize(game->info1, 75);
    sfText_setCharacterSize(game->info2, 75);
    sfText_setCharacterSize(game->info3, 75);
    sfText_setColor(game->t1_bio, sfWhite);
    sfText_setColor(game->info3, sfWhite);
    sfText_setColor(game->info2, sfWhite);
    sfText_setColor(game->t2_bio, sfWhite);
    sfText_setColor(game->t3_bio, sfWhite);
    sfText_setColor(game->t4_bio, sfWhite);
}

void text3_init(game_t *game)
{
    sfText_setString(game->t1_bio,
        "\t\t\t\t70$\nThis tower slow the\nenemies and deal a lot\nof damages");
    sfText_setString(game->t2_bio,
        "\t\t\t\t50$\nThis tower do a\nlot of damages in a\nzone");
    sfText_setString(game->t3_bio,
        "\t\t\t\t30$\nThis tower deal\ndamages at a single\ntarget.");
    sfText_setString(game->t4_bio,
        "\t\t\t\t150$\nThis tower purifies\nenemies by making\nthem allied.");
    sfText_setString(game->info1,
        "The goal of the game is to survive the most possible wave, ");
    sfText_setString(game->info2,
        "the enemies who cross the line of the flags lose 1 point of");
    sfText_setString(game->info3,
        "life in the castle, when the castle has no more life you lose.");
    sfText_setFont(game->t1_bio, game->fon);
    sfText_setFont(game->t2_bio, game->fon);
    sfText_setFont(game->t3_bio, game->fon);
    sfText_setFont(game->t4_bio, game->fon);
    sfText_setFont(game->info1, game->fon);
    text4_init(game);
}

void text2_init(game_t *game)
{
    sfText_setFont(game->t2_men, game->fon);
    sfText_setFont(game->t3_men, game->fon);
    sfText_setFont(game->t4_men, game->fon);
    sfText_setCharacterSize(game->life, 35);
    sfText_setCharacterSize(game->gold, 35);
    sfText_setCharacterSize(game->wave, 35);
    sfText_setCharacterSize(game->t1_men, 80);
    sfText_setCharacterSize(game->t2_men, 80);
    sfText_setCharacterSize(game->t3_men, 80);
    sfText_setCharacterSize(game->t4_men, 80);
    sfText_setColor(game->life, sfWhite);
    sfText_setColor(game->gold, sfWhite);
    sfText_setColor(game->wave, sfWhite);
    sfText_setColor(game->t1_men, sfWhite);
    sfText_setColor(game->t2_men, sfWhite);
    sfText_setColor(game->t3_men, sfWhite);
    sfText_setColor(game->t4_men, sfWhite);
    sfText_setColor(game->info1, sfWhite);
    shop_text_init(game);
    text3_init(game);
}

void text_init(game_t *game)
{
    game->info2 = sfText_create();
    game->info3 = sfText_create();
    game->gold = sfText_create();
    game->wave = sfText_create();
    game->t1_men = sfText_create();
    game->t2_men = sfText_create();
    game->t3_men = sfText_create();
    game->t4_men = sfText_create();
    game->life = sfText_create();
    game->info1 = sfText_create();
    game->t1_bio = sfText_create();
    game->t2_bio = sfText_create();
    game->t3_bio = sfText_create();
    game->t4_bio = sfText_create();
    game->fon = sfFont_createFromFile("sprites/orange juice 2.0.ttf");
    sfText_setString(game->life, "10");
    sfText_setString(game->gold, "100");
    sfText_setString(game->wave, "1");
    sfText_setString(game->t1_men, "WIZARD");
    sfText_setString(game->t2_men, "ROCK");
    text2_init(game);
}