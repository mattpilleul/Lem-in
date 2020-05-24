/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *ret = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (len == 0)
        return 0;
    for (; str[i] != '\0'; i++)
        ret[i] = str[i];
    ret[i] = '\0';
    return ret;
}