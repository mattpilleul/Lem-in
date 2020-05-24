/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int ne(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
        return (nb);
    }
    return (nb);
}

void my_put_nbr(int nb)
{
    long nbr = 1;

    nb = ne(nb);
    if (nb == 0) {
        my_putchar('0');
    }
    while (nb % nbr != nb) {
        nbr *= 10;
    }
    for (; nbr >= 10; nbr /= 10) {
        my_putchar((nb % nbr) / (nbr / 10) + 48);
    }
}