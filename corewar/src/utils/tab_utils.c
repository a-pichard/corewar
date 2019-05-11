/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** tab_utils
*/

#include <stdlib.h>

int get_tab_len(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i++;
    }
    return (i);
}

void destroy_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}