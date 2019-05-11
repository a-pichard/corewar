/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** my_strdup
*/

#include "corewar.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    int i = 0;
    char *newstr = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (newstr == NULL)
        my_puterr("malloc error.\n");
    while (str[i] != '\0') {
        newstr[i] = str[i];
        i++;
    }
    newstr[i] = '\0';
    return (newstr);
}