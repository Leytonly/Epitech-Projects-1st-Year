/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int argc, char **argv)
{
    int status = 0;

    if (argc == 3) {
        if (check_params(argv) == 84) {
            return (84);
        }
        else
            status = init_matchstick(argv);
    }
    return (status);
}