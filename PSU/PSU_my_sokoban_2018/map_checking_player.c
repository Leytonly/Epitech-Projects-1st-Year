/*
** EPITECH PROJECT, 2018
** map_checking_player.c
** File description:
** map_checking_player.c
*/

int get_player_pos_online(char *map, int i)
{
    int count = 0;

    while (map[i] != '\n')
        i = i - 1;
    if (map[i] == '\n') {
        i = i + 1;
        count = count + 1;
    }
    while (map[i] != 'P') {
        i++;
        count++;
    }
    return (count);
}

int get_player_pos(char *map)
{
    int i = 0;
    while (map[i] != 'P') {
        i++;
    }
    return (i);
}

int check_longest_line(char *map)
{
    int i = 0;
    int j = 0;
    int longest_line = 0;

    while (map[i] != '\0') {
        if (longest_line <= j) {
            longest_line = j;
        }
        if (map[i] == '\n') {
            j = 0;
        }
        i = i + 1;
        j = j + 1;
    }
    longest_line = longest_line - 1;
    return (longest_line);
}

char *reset_map(char *map, char *origin_map)
{
    int i = 0;

    while (map[i] != '\0') {
        map[i] = origin_map[i];
        i++;
    }
    return (map);
}