/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** is_nb_pos
*/

#include <stddef.h>

int is_nb_pos(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}