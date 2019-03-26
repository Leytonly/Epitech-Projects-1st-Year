/*
** EPITECH PROJECT, 2019
** navy.c
** File description:
** file where the navy is initialised
*/

#include "my.h"

int check_arg_nbr(int argc, char **argv)
{
    char **map = init_map();
    int status = 0;

    (argc == 2) ? (status = init_navy_t1(argv, map, 0)) :
    (status = init_navy_t2(argv, map, 0));
    if (status == 84)
        my_putstr("Please set a correct position file.\n");
    return (status);
}

int init_navy_t1(char **argv, char **map, int pid)
{
    int fd = 0;
    char *buf = NULL;
    int status = 0;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (84);
    if (check_pos_file(argv[1]) == 84)
        return (84);
    pid = get_two_arg(0);
    buf = malloc(sizeof(char) * 32);
    buf = init_string(buf, 32);
    read(fd, buf, 32);
    map = set_ships(map, buf);
    status = play_navy_t1(map, pid);
    close(fd);
    map = free_map(map);
    free(buf);
    free (map);
    return (status);
}

int init_navy_t2(char **argv, char **map, int pid)
{
    int fd = 0;
    char *buf = NULL;
    int status = 0;

    fd = open(argv[2], O_RDONLY);
    if (fd == -1)
        return (84);
    if (check_pos_file(argv[2]) == 84)
        return (84);
    pid = get_three_arg(0, argv[1]);
    buf = malloc(sizeof(char) * 32);
    buf = init_string(buf, 32);
    read(fd, buf, 32);
    map = set_ships(map, buf);
    status = play_navy_t2(map, pid);
    close(fd);
    map = free_map(map);
    free (buf);
    free (map);
    return (status);
}
