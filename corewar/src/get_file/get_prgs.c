/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_files
*/

#include "corewar.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

int is_contain_cor(char *str)
{
    int len = my_strlen(str) - 1;

    if (len < 5)
        return (0);
    if (str[len] != 'r' || str[len - 1] != 'o' ||
        str[len - 2] != 'c' || str[len - 3] != '.') {
        return (0);
    }
    return (1);
}

static int get_nb_champ(int ac, char **av)
{
    int i = 1;
    int count = 0;

    while (i != ac) {
        if (is_contain_cor(av[i]))
            count++;
        i++;
    }
    return (count);
}

static void init_struct(corewar_t *prgs, int ac, char **av)
{
    int i = 0;

    prgs->nb_prg = get_nb_champ(ac, av);
    prgs->prgs = xmalloc(sizeof(champ_t *) * (prgs->nb_prg + 1));
    while (i < prgs->nb_prg + 1) {
        prgs->prgs[i] = NULL;
        i++;
    }
    prgs->dump = get_dump(ac, av);
    if (prgs->dump == -2) {
        free(prgs->prgs);
        free(prgs);
        helper(av[0], 84);
    }
}

static int same_nb_prog(corewar_t *champ)
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

corewar_t *get_prgs(int ac, char **av)
{
    corewar_t *prgs = xmalloc(sizeof(corewar_t));

    if (ac == 2 && !my_strcmp(av[1], "-h")) {
        free(prgs);
        helper(av[0], 0);
    }
    init_struct(prgs, ac, av);
    get_input(prgs, ac, av);
    if (prgs->nb_prg <= 1 || prgs->nb_prg > 4 || same_nb_prog(prgs)) {
        destroy_struct(prgs);
        return (NULL);
    }
    for (int i = 0; i <= MEM_SIZE; i += 1)
        prgs->memory[i] = '\0';
    prgs = set_nb_prog(prgs);
    prgs = set_addr(prgs);
    return (prgs);
}
