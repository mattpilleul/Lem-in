/*
** EPITECH PROJECT, 2020
** parse_arg
** File description:
** for lemin
*/

#include "my.h"

void del_line(par_t *par, int *i)
{
    int a = (*i);

    while (par->all[a] != NULL) {
        par->all[a] = par->all[(a) + 1];
        (a)++;
    }
}

void del_space_end_line(par_t *par)
{
    int len = 0;

    for (int i = 0; par->all[i] != NULL; i++) {
        len = my_strlen(par->all[i]);
        for (int j = len - 1; par->all[i][j] == ' '; j--)
            par->all[i][j] = '\0';
    }
}

int modify_str(par_t *par, int *i, int j)
{
    if (par->all[*i][j] == '#') {
        if (my_strcmp("##start", par->all[*i]) == 0) {
            par->start = my_strdup(par->all[(*i) + 1]);
            (*i)++;
            return 0;
        } if (my_strcmp("##end", par->all[(*i)]) == 0) {
            par->end = my_strdup(par->all[(*i) + 1]);
            (*i)++;
            return 0;
        }
        par->all[(*i)][j] = '\0';
        if (j == 0) {
            del_line(par, i);
            return 0;
        } else
            return j;
    }
    return j + 1;
}

void get_end_start(algo_t *algo)
{
    for (int i = 0; algo->r_start[i] != '\0'; i++) {
        if (algo->r_start[i] == 32)
            algo->r_start[i] = '\0';
    }
    for (int j = 0; algo->r_end[j] != '\0'; j++) {
        if (algo->r_end[j] == 32)
            algo->r_end[j] = '\0';
    }
}

void clean_com(par_t *par)
{
    for (int i = 0; par->all[i] != NULL; i++) {
        for (int j = 0; par->all[i][j] != '\0'; j++)
            par->all[i][j] = (par->all[i][j] != '\n') ? par->all[i][j]: '\0';
    }
    for (int i = 0; par->all[i] != NULL; i++) {
        for (int j = 0; par->all[i][j] != '\0';) {
            j = modify_str(par, &i, j);
            if (par->all[i] == NULL)
                return;
        }
    }
}