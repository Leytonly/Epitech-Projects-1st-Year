/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** function to copy a char at the end of a string
*/

#include "../../include/my.h"

char *my_strcat (char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    while (src[i] != '\0')
    {
        dest[i + len] = src[i];
        i++;
    }
    dest[i + len] = '\0';
    return (dest);
}
