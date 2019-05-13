/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** destroy_structs
*/

#include "corewar.h"
#include <stddef.h>
#include <stdlib.h>

void destroy_struct(corewar_t *prgs)
{
    int i = 0;

    while (prgs->prgs[i] != NULL) {
        if (prgs->prgs[i]->hd != NULL)
            free(prgs->prgs[i]->hd);
        if (prgs->prgs[i]->prg != NULL)
            free(prgs->prgs[i]->prg);
        free(prgs->prgs[i]);
        i++;
    }
    free(prgs->prgs);
    free(prgs);
}