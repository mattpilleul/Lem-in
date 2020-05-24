/*
** EPITECH PROJECT, 2020
** main
** File description:
** for lemin
*/

#include "my.h"

void disp(par_t *par)
{
    int a = 0;

    my_putstr("#number_of_ants\n");
    for (int i = 0; par->all[i] != NULL; i++) {
        if (a == 0 && is_tunnel(par->all[i])) {
            my_putstr("#tunnels\n");
            a++;
        }
        my_putstr(par->all[i]);
        write(1, "\n", 1);
        if (i == 0)
            my_putstr("#rooms\n");
    }
    my_putstr("#moves\n");
}

void init_struct(m_t *m)
{
    m->par.nbr_ant = 0;
    m->par.all = NULL;
    m->par.tunnel = NULL;
    m->par.room = NULL;
    m->par.start = NULL;
    m->par.end = NULL;
    m->algo.tunnel = NULL;
    m->algo.nbr_ant = 0;
    m->algo.r_start = NULL;
    m->algo.r_end = NULL;
}

int main(void)
{
    m_t m;

    init_struct(&m);
    if (parse_arg(&m.par)) {
        disp(&m.par);
        return (84);
    }
    if (check_arg(&m.par)) {
        disp(&m.par);
        return (84);
    }
    disp(&m.par);
    return 0;
}