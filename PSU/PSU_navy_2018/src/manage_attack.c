/*
** EPITECH PROJECT, 2018
** manage_navy.c
** File description:
** attack management (sending and receiving)
*/

#include "my.h"

char *get_attack_pos(char *attack)
{
    int st = 0;
    char *pos = malloc(sizeof(char) * 3);

    pos = init_string(pos, 3);
    if (attack[0] < 'A' || attack[0] > 'H')
        st++;
    if (attack[1] < '1' || attack[1] > '8')
        st++;
    if (st != 0 || my_strlen(attack) != 3)
        return (NULL);
    pos[0] = attack[0];
    pos[1] = attack[1];
    pos[2] = '\0';
    return (pos);
}

char **check_attack(char *attack, char **map)
{
    char * atk_pos = NULL;

    while (1) {
        atk_pos = malloc(sizeof(char) * 3);
        atk_pos = init_string(atk_pos, 3);
        atk_pos = get_attack_pos(attack);
        if (atk_pos == NULL) {
            my_putstr("wrong position\nattack:  ");
            free(atk_pos);
            free(attack);
            attack = malloc(sizeof(char) * 128);
            attack = init_string(attack, 128);
            read(0, attack, 128);
        }
        else {
            map = mod_atk_map_enemy(map, atk_pos);
            break;
        }
    }
    return (map);
}

void send_kill(int pid, char *attack)
{
    int i = 0;
    int j = 0;
    char *char_letter = get_base(attack[0], 8);
    char *char_number = get_base(attack[1], 8);

    for (; i < 8 ; i++) {
        if (char_letter[i] == '0')
            kill(pid, SIGUSR1);
        if (char_letter[i] == '1')
            kill(pid, SIGUSR2);
        usleep(1500);
    }
    for (; j < 8 ; j++) {
        if (char_number[j] == '0')
            kill(pid, SIGUSR1);
        if (char_number[j] == '1')
            kill(pid, SIGUSR2);
        usleep(1500);
    }
}

char **send_attack(char **map, int pid)
{
    char *attack = NULL;
    int status = 0;
    int i = 0;

    attack = malloc(sizeof(char) * 128);
    attack = init_string(attack, 128);
    status = read(0, attack, 128);
    if (status != -1) {
        map = check_attack(attack, map);
        //send_kill(pid, attack);
        i = check_hit();
        print_map(map);
    }
    free(attack);
    return (map);
}

char **wait_attack(char **map, int pid)
{
    char *tab = malloc((sizeof(char) * 16) + 1);
    char *atk_pos = malloc(sizeof(char) * 3);
    int t = 0;
    int i = 0;

    for (; i < 16; i++) {
        signal(SIGUSR1, first_sig);
        signal(SIGUSR2, second_sig);
        pause();
        tab[t] = set_signal_value(2);
        t++;
    }
    atk_pos = get_pos_dec(tab);
    send_hit(pid, 0);
    
    return (map);
}
