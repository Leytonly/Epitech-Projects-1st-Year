/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** my_defender.
*/

#include "my.h"

sfMusic *add_music(sfMusic* sound)
{
    const char *music = "musics/music.ogg";

    sound = sfMusic_createFromFile(music);
    sfMusic_play(sound);
    sfMusic_setLoop(sound, sfTrue);
    return (sound);
}

sfMusic *add_mus(sfMusic* sound)
{
    const char *music = "musics/wolf_song.ogg";

    sound = sfMusic_createFromFile(music);
    sfMusic_play(sound);
    return (sound);
}

sfMusic *add_m(sfMusic* sound)
{
    const char *music = "musics/shot.ogg";

    sound = sfMusic_createFromFile(music);
    sfMusic_play(sound);
    return (sound);
}

void sound_destroy(sfMusic *sound)
{
    sfMusic_stop(sound);
    sfMusic_destroy(sound);
}