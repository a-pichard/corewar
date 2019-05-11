/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "corewar.h"
#include <stdio.h>
/*
void print_prg(unsigned char *prg, int end)
{
    int i = 0;

    while (i != end) {
        printf("%x ", prg[i]);
        i++;
    }
    printf("\n");
}*/

int main(int ac, char **av)
{
    champs_t *champ = get_prgs(ac, av);

    /* CES PRINTF SERVENT A PRINT LES INFOS DE CE QUI A ETE LU (2 FICHIERS .cor)
    printf("%d %s %d %s\n", champ->prgs[0]->hd->magic, champ->prgs[0]->hd->prog_name, champ->prgs[0]->hd->prog_size, champ->prgs[0]->hd->comment);
    printf("%d %d\n", champ->prgs[0]->nb, champ->prgs[0]->addr);
    print_prg(champ->prgs[0]->prg, champ->prgs[0]->hd->prog_size);
    printf("%d %s %d %s\n", champ->prgs[1]->hd->magic, champ->prgs[1]->hd->prog_name, champ->prgs[1]->hd->prog_size, champ->prgs[1]->hd->comment);
    printf("%d %d\n", champ->prgs[1]->nb, champ->prgs[1]->addr);
    print_prg(champ->prgs[1]->prg, champ->prgs[1]->hd->prog_size);
    printf("dump = %d\nnb_prg = %d\n", champ->dump, champ->nb_prg);*/
    destroy_struct(champ);
    return (0);
}