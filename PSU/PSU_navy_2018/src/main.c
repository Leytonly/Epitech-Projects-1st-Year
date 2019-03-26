/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "stdio.h"
#include "my.h"

int main(int argc, char **argv)
{
    int status = 0;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        print_help();
    else if (argc == 2 || argc == 3)
        check_arg_nbr(argc, argv);
    return (status);
}