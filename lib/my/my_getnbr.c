/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int compt = 0;
    int c = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if ((str[j] < '0' || str[j] > '9') && str[j] != '-')
            return 0;
    }
    while (str[i] == '-') {
        i++;
        compt += 1;
    }
    while (str[i] <= 57 && str[i] >= 48) {
        c = c + str[i] - 48;
        c = c * 10;
        i++;
    }
    c = c / 10;
    return (c);
}