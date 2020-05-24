/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include <stdlib.h>

void my_putstr(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    write(1, str, i);
}