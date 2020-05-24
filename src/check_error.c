/*
** EPITECH PROJECT, 2020
** main
** File description:
** for lemin
*/

#include "my.h"

int error_room(char **room, int len)
{
    char **name = malloc(sizeof(char *) * len);
    char **x = malloc(sizeof(char *) * len);
    char **y = malloc(sizeof(char *) * len);

    make_name(room, &name);
    make_x(room, &x);
    make_y(room, &y);
    for (int i = 0; room[i] != NULL; i++) {
        if (room_error(name, x, y, i) == 1)
            return 1;
    }
    return 0;
}

int check_room(par_t *par)
{
    int nbr_room = 0;
    char **room = {0};

    for (int i = 0; par->all[i] != NULL; i++) {
        if (is_room(par->all[i]) == 0) {
            nbr_room++;
        }
    }
    room = malloc(sizeof(char *) * (nbr_room + 1));
    for (int i = 0, nbr_room = 0; par->all[i] != NULL; i++) {
        if (is_room(par->all[i]) == 0) {
            room[nbr_room] = my_strdup(par->all[i]);
            nbr_room++;
        }
    }
    room[nbr_room] = NULL;
    return (error_room(room, nbr_room + 1));
}

int check_arg(par_t *par)
{
    int a = check_room(par);
    int tun = 0;
    int room = 0;

    if (par->end == NULL || par->start == NULL)
        return 1;
    for (int i = 1; par->all[i] != NULL; i++) {
        if (is_tunnel(par->all[i]) == 1 && room == 1) {
            tun = 1;
            continue;
        } if (is_room(par->all[i]) == 0 && tun == 0) {
            room = 1;
            continue;
        }
        if (my_strcmp(par->all[i], "##end") == 0 || \
        my_strcmp(par->all[i], "##start") == 0)
            continue;
        return 1;
    }
    return (a);
}