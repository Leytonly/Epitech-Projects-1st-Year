/*
** EPITECH PROJECT, 2019
** minishell.c
** File description:
** minishell.c
*/

#include "my.h"

void debug(char *str)
{
    int i = 0;
    int breaki = 300;

    while(breaki) {
        if (str[i] >= 20 && str[i] <= 126)
            printf("%c", str[i]);
        else
            printf("i");
        i++;
        breaki--;
    }
}

char *replace_to_spaces(char *path)
{
    int i = 0;

    while (path[i] != '\0') {
        if (path[i] == ':')
            path[i] = ' ';
        i++;
    }
    return (path);
}

char **get_env(char *path, char **tab_path, char **env)
{
    int i = 0;
    int j = 5;
    int k = 0;

    while (env[i] != NULL) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
            env[i][3] == 'H' && env[i][4] == '=') {
            path = malloc(sizeof(char) * my_strlen(env[i]) - 4);
            while (env[i][j] != '\0') {
                path[k] = env[i][j];
                j++;
                k++;
            }
            path[k] = '\0';
        }
        i++;
    }
    path = replace_to_spaces(path);
    tab_path = my_str_to_word_array(path);
    return (tab_path);
}

char *remove_tab(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\t' || str[i] == '\n')
            str[i] = ' ';
        i++;
    }
    return (str);
}
int check_env(char **tab)
{
    int res = 0;

    if (tab[0][0] == 's' && tab[0][1] == 'e' && tab[0][2] == 't' &&
        tab[0][3] == 'e' && tab[0][4] == 'n' && tab[0][5] == 'v' )
        res = 1;
    if (tab[0][0] == 'u' && tab[0][1] == 'n' && tab[0][2] == 's' &&
        tab[0][3] == 'e' && tab[0][4] == 't' && tab[0][5] == 'e' &&
        tab[0][6] == 'n' && tab[0][7] == 'v')
        res = 2;
    return (res);
}

int count_env_lines(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++);
    return (i);
}

char **manage_env_mod(path_t *paths, char **env, int status, char **tab)
{
    int i = 0;
    char **new_env = NULL;
    int lines = count_env_lines(env);

    if (status == 1) {
        new_env = malloc(sizeof(char *) * (lines + 1));
        while (env[i] != NULL) {   
            new_env[i] = malloc(sizeof(char) * my_strlen(env[i]));
            my_strcpy(new_env[i], env[i]);
            i++;
        }
        new_env[i] = malloc(sizeof(char) * my_strlen(tab[1]));
        my_strcpy(new_env[i], tab[1]);
        my_strcat(new_env[i], "=");
        my_strcat(new_env[i], tab[2]);
    }
    //else if (status == 2)
        //unset_env()
    return (env);
}

int check_arg(path_t *paths, char **env)
{
    int i = 0;

    if (paths->tab[0][0] == 'e' && paths->tab[0][1] == 'x' &&
        paths->tab[0][2] == 'i' && paths->tab[0][3] == 't') {
        my_putstr("exit\n");
        free(paths->str);
        exit(0);
    }
    else if (paths->tab[0][0] == '.' && paths->tab[0][1] == '/')
        i = 1;
    else
        i = 0;
    if (i ==  1)
        exec_fc(paths->tab, env, paths->tab[0]);
    else if (check_env(paths->tab) > 0)
        env = manage_env_mod(paths, env, check_env(paths->tab), paths->tab);
    else
        get_arg(paths->tab, env, paths->path);
    return (0);
}

int init_minishell(char **env)
{
    path_t *paths = malloc(sizeof(path_t));

    while (paths) {
        if (env[0] == NULL) {
            env[0] = "PATH=/usr/bin";
            env[1] = NULL;
        }
        paths->path = get_env(paths->path_string, paths->tab_path, env);
        my_putstr("$>");
        paths->status = getline(&paths->str, &paths->len, stdin);
        if (paths->status == -1) {
            free(paths->str);
            exit(0);
        }
        paths->str = remove_tab(paths->str);
        paths->tab = my_str_to_word_array(paths->str);
        check_arg(paths, env);
    }
    free(paths);
    return(0);
}