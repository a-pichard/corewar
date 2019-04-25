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
    char **array;

    while (tab[i] != NULL) {
        array = my_str_to_word_tab(tab[i]);
        for (int j = 0; array[j] != NULL; j += 1) {
            my_putstr(array[j]);
            my_putchar(' ');
        }
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
