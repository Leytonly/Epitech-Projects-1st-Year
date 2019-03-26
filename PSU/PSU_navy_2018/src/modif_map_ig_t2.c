/*
** EPITECH PROJECT, 2018
** modif_map_ig.c
** File description:
** modif map while playing
*/

#include "../include/my.h"

char *get_str_bin(char *str_bin, int start)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 9);
    while (i < 8) {
        str[i] = str_bin[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}

char *get_pos_dec(char *str_bin)
{
    int i = 0;
    char *str_letter = malloc(sizeof(char) * (8 + 1));
    char *str_number = malloc(sizeof(char) * (8 + 1));
    char *pos = malloc(sizeof(char) * 3);

    str_letter = get_str_bin(str_bin, 0);
    str_number = get_str_bin(str_bin, 8);

    pos[0] = conv_bin_to_dec(str_letter);
    pos[1] = conv_bin_to_dec(str_number);
    pos[2] = '\0';

    return (pos);
}