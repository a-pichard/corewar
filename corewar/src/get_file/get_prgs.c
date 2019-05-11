/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_files
*/

#include "corewar.h"
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

static void init_struct(champs_t *prgs, int ac, char **av)
{
    int i = 0;

    prgs->nb_prg = get_nb_champ(ac, av);
    prgs->prgs = xmalloc(sizeof(file_t *) * (prgs->nb_prg + 1));
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

champs_t *get_prgs(int ac, char **av)
{
    champs_t *prgs = xmalloc(sizeof(champs_t));

    init_struct(prgs, ac, av);
    get_input(prgs, ac, av);
    return (prgs);
}