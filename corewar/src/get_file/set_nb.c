/*
** EPITECH PROJECT, 2019
** set_nbr.c
** File description:
** set nb prog
*/

#include "corewar.h"
#include <stddef.h>

int choose_nb(corewar_t *champ)
{
    int finish = 0;
    int n = -1;

    while (!finish) {
        n += 1;
        finish = 1;
        for (int i = 0; champ->prgs[i] != NULL; i += 1)
            (champ->prgs[i]->nb == n) ? finish = 0 : 0;
    }
    return (n);
}

corewar_t *set_nb_prog(corewar_t *champ)
{
    for (int i = 0; champ->prgs[i] != NULL; i += 1) {
        if (champ->prgs[i]->nb == -1)
            champ->prgs[i]->nb = choose_nb(champ);
    }
    return (champ);
}
