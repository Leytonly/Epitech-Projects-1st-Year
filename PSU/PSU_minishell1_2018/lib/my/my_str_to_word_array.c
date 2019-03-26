/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "../../include/my.h"

int count_chars(char *argv)
{
    int i = 0;
    int count = 0;
    int spaces = 0;

    while (argv[i] != '\0') {
        if (argv[i] != ' ') {
            count++;
            spaces++;
    }
        else if (argv[i] == ' ' && argv[i + 1] != ' ' && spaces != 0) 
            count++;
        i++;
    }
    
    return (count);
}

char* clean_string(char *argv, int i, int j, int temp)
{
    char *cl_string = NULL;
    int count = count_chars(argv);
    
    cl_string = malloc(sizeof(char) * count);
    while (argv[temp] == ' ')
        temp++;
    i = temp;
    while (argv[i] != '\0') {
        if (argv[i] == ' ' && argv[i + 1] == ' ')
            i++;
        if ((argv[i] == ' ' && argv[i + 1] != ' ') || argv[i] != ' ') {
            cl_string[j] = argv[i];
            j++;
        }
        i++;
    }
    if (cl_string[j - 1] == ' ')
        cl_string[j - 1] = '\0';    
    else
        cl_string[j] = '\0';
    return (cl_string);
}

int count_words(char *argv)
{
    int temp = 0;
    int count = 0;
    
    argv = clean_string(argv, 0, 0, 0);
    while (argv[temp] != '\0') {
        if (argv[temp] == ' ' && argv[temp + 1] != '\0')
            count++;
        temp++;
    }
    count++;
    return (count);
}

char **malloc_array(char **array, char *argv)
{
    int i = 0;
    int j = 0;
    int count = count_words(argv);

    array = malloc(sizeof(char *) * count);
    count = 0;
    while (argv[i] != '\0') {
        count = count + 1;
        if (argv[i + 1] == '\0')  {
            count = count + 1;
            array[j] = malloc(sizeof(char) * (count + 1));
            count = 0;
        }
        if (argv[i] == ' ' && argv[i + 1] != '\0') {
            array[j] = malloc(sizeof(char) * (count + 1));
            count = 0;
            j++;
        }
        i++;
    }
    return (array);
}

char **my_str_to_word_array(char *argv)
{
    char **array = NULL;
    int i = 0;
    int j = 0;
    int temp = 0;
    int ch = 0;

    argv = clean_string(argv, 0, 0, 0);
    array = malloc_array(array, argv);
    while (argv[ch] != '\0') {
        if (argv[ch] == ' ') {
            array[i][j] = '\0';
            i++;
            j = 0;
            ch++;
        }
        array[i][j] = argv[ch];
        j++;
        ch++;
    }
    array[i][j] = '\0';
    return (array);
}