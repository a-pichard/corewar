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

int *my_realloc(int *str, char *src, int fr)
{
    int i;
    int j;
    int k;
    int m;
    int *dest;

    for (i = 0; str != NULL && str[i] != -1; i += 1);
    for (j = 0; src[j] != '\0'; j += 1);
    dest = malloc(sizeof(int) * (i + j + 1));
    (dest == NULL)?exit(84):0;
    for (k = 0; k < i; k += 1)
        dest[k] = str[k];
    for (m = 0; k + m < i + j; m += 1)
        dest[k + m] = src[m];
    dest[k + m] = -1;
    (fr) ? free(str) : 0;
    return (dest);
}
