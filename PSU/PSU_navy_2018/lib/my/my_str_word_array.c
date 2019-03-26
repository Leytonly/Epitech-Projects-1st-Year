/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** string to sting_tab
*/

#include "../../include/my.h"

int count_spaces(char *str)
{
    int i = 0;
    int p = 1;

    for (i = 0 ; str[i] != '\0' ; i++)
        if (str[i] == ' ')
            p++;
    return (p);
}

int get_word_size(char *str, int pos)
{
    int i = 0;

    while (str[pos+i] != ' ' && str[pos+i] != '\0')
        i++;
    return (i);
}

char *get_next_word(char *str, int pos)
{
    int i = 0;
    char *tab_case = malloc(sizeof(char) * get_word_size(str, pos) + 1);

    tab_case[get_word_size(str, pos)] = '\0';
    for (i = 0 ; str[pos+i] != ' ' && str[pos+i] != '\0' ; i++)
        tab_case[i] = str[pos+i];
    return (tab_case);
}

char **my_str_to_word_array(char *str)
{
    int i;
    int sp_nb = count_spaces(str);
    char **word_array = malloc(sizeof(char *)*(sp_nb + 1));
    int pos = 0;

    for (i = 0 ; i < sp_nb ; i++){
        word_array[i] = get_next_word(str, pos);
        while (str[pos] != ' ' && str[pos] != '\0')
            pos++;
        while (str[pos] == ' ' && str[pos] != '\0')
            pos++;
    }
    word_array[i] = NULL;
    return (word_array);
}
