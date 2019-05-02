/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** tab_utils
*/

#include "asm.h"
#include <stdlib.h>

void print_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
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
