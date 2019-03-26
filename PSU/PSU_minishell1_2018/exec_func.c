/*
** EPITECH PROJECT, 2019
** exec_func.c
** File description:
** exec_func.c
*/

#include <sys/wait.h>
#include "my.h"

int exec_fc(char **tab, char **env, char *path)
{
    pid_t pid;
    
    pid = fork();
    if (pid != 0)
        wait(0);
    else if (pid == 0) {
        execve(path, tab, env);
        
    }
    return (0);
}

int get_arg(char **tab, char **env, char **path)
{
    int i = 0;
    int acc = 0;
    int count = 0;
    
    while (path[i] != NULL) {
        my_strcat(path[i], "/");
        my_strcat(path[i], tab[0]);
        acc = access(path[i], F_OK);
        if (acc == 0) {
            exec_fc(tab, env, path[i]);
            count++;
        }
        i++;
    }
    if (count == 0)
        my_putstr("Command not found\n");
    return (0);
}