/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** my.h
*/

#ifndef __LEMIN__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct par_s {
    int nbr_ant;
    char **all;
    char **tunnel;
    char **room;
    char *start;
    char *end;
}par_t;

typedef struct algo_s {
    char ***tunnel;
    int nbr_ant;
    char *r_start;
    char *r_end;
}algo_t;

typedef struct m_s {
    par_t par;
    algo_t algo;
}m_t;

int parse_arg(par_t *par);
void arrange_arg(par_t *par, algo_t *algo);
char *my_strdup(char *str);
int my_getnbr(char const *str);
void clean_com(par_t *par);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);
void get_end_start(algo_t *algo);
void my_putstr(char *str);
int check_arg(par_t *par);
void del_space_end_line(par_t *par);
int room_error(char **name, char **x, char **y, int i);
void make_name(char **room, char ***name);
void make_y(char **room, char ***y);
void make_x(char **room, char ***x);
int is_room(char *str);
int error_end_start(par_t *par);
int is_tunnel(char *str);

#endif