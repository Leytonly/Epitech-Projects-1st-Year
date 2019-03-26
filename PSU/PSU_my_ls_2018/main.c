/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "include/my.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        print_ls_only(argc, ".");
    else if (argc > 1)
        check_parameters(argc, argv);
    return (0);
}