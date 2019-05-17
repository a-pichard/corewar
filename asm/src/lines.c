/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** lines
*/

#include "asm.h"

int empty_line(char *str)
{
    for (int i = 0; str[i]; i += 1) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
            return (0);
    }
    return (1);
}

char *get_quotes(char *str, int n)
{
    for (int i = 0; str[i]; i += 1)
        str[i] = str[i + 1];
    str[my_strlen(str) - 1] = '\0';
    if (my_strlen(str) > n)
        my_puterr("name or comment too long\n");
    return (str);
}