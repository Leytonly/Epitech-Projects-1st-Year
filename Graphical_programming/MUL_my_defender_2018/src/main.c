/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** game defender.
*/

#include "my.h"

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfMusic* sound = NULL;

    usage_func(ac, av);
    if (ac == 1) {
        window = sfRenderWindow_create(mode, "My Defender",
            sfResize | sfClose, NULL);
        sfRenderWindow_setFramerateLimit(window, 30);
        sound = add_music(sound);
        load_window(window);
        sound_destroy(sound);
        sfRenderWindow_destroy(window);
    }
    return (0);
}