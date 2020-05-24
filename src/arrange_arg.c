/*
** EPITECH PROJECT, 2020
** main
** File description:
** for lemin
*/

#include "my.h"

void malloc_arr(int i, char **tunnel, algo_t *algo)
{
    for (; tunnel[i] != NULL; i++);
    algo->tunnel = malloc(sizeof(char **) * (i + 1));
    algo->tunnel[i] = NULL;
    for (i = 0; tunnel[i] != NULL; i++) {
        algo->tunnel[i] = malloc(sizeof(char *) * 3);
        algo->tunnel[i][2] = NULL;
    }
}

void range_tunnel(char **tunnel, algo_t *algo)
{
    int i = 0;
    int j = 0;
    int len = 0;
    int len_s = 0;

    malloc_arr(i, tunnel, algo);
    for (i = 0; tunnel[i] != NULL; i++) {
        for (len = 0; tunnel[i][len] != '-'; len++);
        algo->tunnel[i][0] = malloc(sizeof(char) * (len + 1));
        for (len = 0; tunnel[i][len] != '-'; len++)
            algo->tunnel[i][0][len] = tunnel[i][len];
        algo->tunnel[i][0][len] = '\0';
        len++;
        for (len_s = len; tunnel[i][len_s] != '\0'; len_s++);
        algo->tunnel[i][1] = malloc(sizeof(char) * (len_s + 1));
        for (j = 0, len_s = len; tunnel[i][len_s] != '\0'; len_s++, j++)
            algo->tunnel[i][1][j] = tunnel[i][len_s];
        algo->tunnel[i][1][j] = '\0';
        algo->tunnel[i][2] = NULL;
    }
}

void arrange_arg(par_t *par, algo_t *algo)
{
    algo->nbr_ant = par->nbr_ant;
    if (par->end != NULL && par->start != NULL) {
        algo->r_end = my_strdup(par->end);
        algo->r_start = my_strdup(par->start);
    }
    range_tunnel(par->tunnel, algo);
}

int error_end_start(par_t *par)
{
    int tmp = 0;

    for (int x = 0; par->all[x] != NULL; x++) {
        tmp = my_strlen(par->all[x]);
        if (par->all[x][tmp - 1] != '\n')
            return 1;
    }
    return 0;
}