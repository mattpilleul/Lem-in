/*
** EPITECH PROJECT, 2020
** main
** File description:
** for lemin
*/

#include "my.h"

int is_room(char *str)
{
    int space = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            space++;
    }
    if (space != 2)
        return 1;
    return 0;
}

void make_x(char **room, char ***x)
{
    int j = 0;
    int len = 0;
    int i = 0;

    for (i = 0; room[i] != NULL; i++, len = 0) {
        for (j = 0; room[i][j] != ' '; j++);
        j++;
        for (int k = j; room[i][k] != ' '; k++)
            len++;
        (*x)[i] = malloc(sizeof(char) * (len + 1));
        for (int k = j, c = 0; room[i][k] != ' '; k++, c++)
            (*x)[i][c] = room[i][k];
        (*x)[i][len] = '\0';
    }
    (*x)[i] = NULL;
}

void make_y(char **room, char ***y)
{
    int j = 0;
    int len = 0;
    int s = 0;
    int i = 0;

    for (i = 0; room[i] != NULL; i++, len = 0) {
        for (j = 0, s = 0; s != 2; j++, s += (room[i][j] == ' ') ? 1: 0);
        j++;
        for (int k = j; room[i][k] != '\0'; k++)
            len++;
        (*y)[i] = malloc(sizeof(char) * (len + 1));
        for (int k = j, c = 0; room[i][k] != '\0'; k++, c++)
            (*y)[i][c] = room[i][k];
        (*y)[i][len] = '\0';
    }
    (*y)[i] = NULL;
}

void make_name(char **room, char ***name)
{
    int j = 0;
    int i = 0;

    for (i = 0; room[i] != NULL; i++) {
        (*name)[i] = my_strdup(room[i]);
        for (j = 0; (*name)[i][j] != ' '; j++);
        (*name)[i][j] = '\0';
    }
    (*name)[i] = NULL;
}

int room_error(char **name, char **x, char **y, int i)
{
    for (int j = 0; name[j] != NULL; j++) {
        if (my_strcmp(name[i], name[j]) == 0 && i != j)
            return 1;
        if (my_strcmp(x[i], x[j]) == 0 && my_strcmp(y[i], y[j]) == 0 && i != j)
            return 1;
    }
    for (int abs = 0; x[i][abs] != '\0'; abs++) {
        if (x[i][abs] < '0' || x[i][abs] > '9')
            return 1;
    }
    for (int ord = 0; y[i][ord] != '\0'; ord++) {
        if (y[i][ord] < '0' || y[i][ord] > '9')
            return 1;
    }
    return 0;
}