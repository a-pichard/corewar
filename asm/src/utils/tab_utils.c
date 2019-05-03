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

    if (tab == NULL)
        return;
    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int destroy_array(char **tab, int ret)
{
    if (tab == NULL)
        return (ret);
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
    return (ret);
}

int *destroy_array_t(char **tab, int *ret)
{
    if (tab == NULL)
        return (ret);
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
    return (ret);
}
