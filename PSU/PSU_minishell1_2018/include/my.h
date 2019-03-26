/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


typedef struct path {
    char *str;
    char** tab;
    char *path_string;
    char **path;
    char **tab_path;
    size_t len;
    int status;
}path_t;

void my_putchar(char c);
int my_getnbr(char const *str);
void my_put_nbr(int nb);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char *src);
void my_putstr(char const *str);
int count_chars(char *argv);
char* clean_string(char *argv, int i, int j, int temp);
int count_words(char *argv);
char **malloc_array(char **array, char *argv);
char *replace_to_spaces(char *path);
char **my_str_to_word_array(char *argv);
char *my_strcat(char *dest, char const *src);
int init_minishell(char **env);
char **get_env(char *path, char **tab_path, char **env);
char *replace_to_spaces(char *path);
int get_arg(char **tab, char **env, char **path);
int exec_fc(char **tab, char **env, char *path);


#endif