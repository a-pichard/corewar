/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "corewar.h"
#include "op.h"
#include <stdio.h>

void print_prg(unsigned char *prg, int end)
{
    int i = 0;

    while (i != end) {
        printf("%x ", prg[i]);
        i++;
    }
    printf("\n");
}

int same_nb_prog(champs_t *champ)
{
    int mem;
    int br = 0;

    for (int j = 0; champ->prgs[j + 1] != NULL; j += 1) {
        if (champ->prgs[j]->hd->magic != COREWAR_EXEC_MAGIC)
            return (1);
        mem = champ->prgs[j]->nb;
        for (int i = j + 1; !br && champ->prgs[i] != NULL; i += 1)
            (mem != -1 && mem == champ->prgs[i]->nb) ? br = 1 : 0;
        if (br)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    champs_t *champ = get_prgs(ac, av);

    /* CES PRINTF SERVENT A PRINT LES INFOS DE CE QUI A ETE LU (FICHIERS .cor)*/
    for (int i = 0; champ->prgs[i] != NULL; i += 1) {
        printf("%x %s %d %s\n", champ->prgs[i]->hd->magic, champ->prgs[i]->hd->prog_name, champ->prgs[i]->hd->prog_size, champ->prgs[i]->hd->comment);
        printf("%d %d\n", champ->prgs[i]->nb, champ->prgs[i]->addr);
        print_prg(champ->prgs[i]->prg, champ->prgs[i]->hd->prog_size);
    }
    printf("dump = %d\nnb_prg = %d\n", champ->dump, champ->nb_prg);
    if (champ->nb_prg <= 1 || same_nb_prog(champ)) {
        destroy_struct(champ);
        return (84);
    }
    champ = set_nb_prog(champ);
    destroy_struct(champ);
    return (0);
}
