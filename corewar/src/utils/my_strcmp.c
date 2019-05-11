/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** my_strcmp
*/

#include "corewar.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}