/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "corewar.h"
#include "op.h"
#include <stdio.h>

void print_prg(corewar_t *cor)
{
    /* CES PRINTF SERVENT A PRINT LES INFOS DE CE QUI A ETE LU (FICHIERS .cor)*/
    for (int i = 0; cor->prgs[i] != NULL; i += 1) {
        printf("%x %s %d %s\n", cor->prgs[i]->hd->magic, cor->prgs[i]->hd->prog_name, cor->prgs[i]->hd->prog_size, cor->prgs[i]->hd->comment);
        printf("%d %d\n", cor->prgs[i]->nb, cor->prgs[i]->addr);
        for (int j = 0; j != cor->prgs[i]->hd->prog_size; j++) {
            printf("%x ", cor->prgs[i]->prg[j]);
        }
        printf("\n");
    }
}

int main(int ac, char **av)
{
    corewar_t *cor = get_prgs(ac, av);

    if (cor == NULL)
        return (84);
    //print_prg(cor);
    destroy_struct(cor);
    return (0);
}
