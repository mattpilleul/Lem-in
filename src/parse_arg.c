/*
** EPITECH PROJECT, 2020
** parse_arg
** File description:
** for lemin
*/

#include "my.h"

int is_tunnel(char *str)
{
    int minus = 0;
    int first_tun = 0;
    int sec_tun = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (minus == 0 && str[i] != '-')
            first_tun++;
        else if (minus != 0 && str[i] != '-')
            sec_tun++;
        else
            minus++;
    }

    return (minus == 1 && first_tun >= 1 && sec_tun >= 1);
}

void get_tunnel(par_t *par)
{
    int i = 0;
    int tun = 0;

    while (par->all[i] != NULL) {
        if (is_tunnel(par->all[i]))
            tun++;
        i++;
    }
    par->tunnel = malloc(sizeof(char *) * (tun + 1));
    for (i = 0, tun = 0;par->all[i] != NULL; i++) {
        if (is_tunnel(par->all[i])) {
            par->tunnel[tun] = my_strdup(par->all[i]);
            tun++;
        }
    }
    par->tunnel[tun] = NULL;
}

int manag_arg(par_t *par)
{
    clean_com(par);
    del_space_end_line(par);
    par->nbr_ant = my_getnbr(par->all[0]);
    get_tunnel(par);
    if (par->nbr_ant == 0)
        return 1;
    return 0;
}

int parse_arg(par_t *par)
{
    size_t size = 0;
    int i = 0;

    par->all = malloc(sizeof(char *) * 4096);
    for (int a = 0; a < 4096; a++)
        par->all[a] = NULL;
    while (getline(&par->all[i], &size, stdin) > 0)
        i++;
    par->all[i] = NULL;
    if (error_end_start(par) == 1) {
        manag_arg(par);
        return 1;
    }
    return (manag_arg(par));
}
