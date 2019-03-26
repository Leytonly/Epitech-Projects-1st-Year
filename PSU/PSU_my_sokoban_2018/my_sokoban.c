/*
** EPITECH PROJECT, 2018
** my_sokoban.c
** File description:
** my_sokoban.c
*/

#include <ncurses.h>
#include "include/my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void print_help(void)
{
    my_printf("USAGE\n\t./my_sokoban map\nDESCRIPTION\n");
    my_printf("\tmap  file representing the warehouse map,");
    my_printf(" containing '#' for walls,\n");
    my_printf("\t     'P' for the player, 'X' for boxes and '0'");
    my_printf(" for storages locations.\n");
}

char *clone_map(char *map, char *origin_map)
{
    int i = 0;
    int j = 0;

    while (map[i] != '\0') {
        i++;
    }
    origin_map = malloc(sizeof(char) * i + 1);
    while (map[j] != '\0') {
        origin_map[j] = map[j];
        j++;
    }
    return (origin_map);

}

void print_window_message(void)
{
    move((LINES / 2), ((COLS / 2) - 14));
    printw("Veuillez agrandir la fenêtre");
}

int my_sokoban(char *map)
{
    char *origin_map = clone_map(map, origin_map);

    initscr();
    while (1) {
        clear();
        keypad(stdscr, TRUE);
        noecho();
        if (LINES < line_nbr(map) || COLS < check_longest_line(map))
            print_window_message();
        else
        printw("%s\n", map);
        map = move_player(map, origin_map);
        refresh();
    }
    endwin();
}

int main(int argc, char **argv)
{
    char *map;
    int fd;
    struct stat sb;
    int size_b = 0;

    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            print_help();
        else {
            stat(argv[1], &sb);
            fd = open(argv[1], O_RDONLY);
            if (fd == -1)
                return (1);
            size_b = sb.st_size;
            map = malloc(sizeof(char) * size_b + 1);
            read(fd, map, size_b);
            my_sokoban(map);
            close(fd);
        }
    }
}
