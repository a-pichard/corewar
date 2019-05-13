/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_intput
*/

#include "corewar.h"
#include "op.h"
#include <stdlib.h>

static int get_new_ac(int ac, char **av)
{
    int i = 0;

    while (i < ac) {
        if (!my_strcmp(av[i], "-dump"))
            return (ac - 3);
        i++;
    }
    return (ac - 1);
}

static char **dup_args(int ac, char **av)
{
    int new_ac = get_new_ac(ac, av);
    char **new_av = xmalloc(sizeof(char *) * (new_ac + 1));
    int i = 0;
    int j = 1;

    while (i < new_ac) {
        if (my_strcmp(av[j], "-dump")) {
            new_av[i] = my_strdup(av[j]);
            i++;
            j++;
        } else {
            j += 2;
        }
    }
    new_av[i] = NULL;
    return (new_av);
}

static int fill_arg(int *nb, int *addr, char **av, int *i)
{
    if (!my_strcmp(av[*i], "-n") || !my_strcmp(av[*i], "-a")) {
        if (!is_nb_pos(av[(*i) + 1]))
            return (1);
        if (!my_strcmp(av[*i], "-n") && *nb == -1)
            ((*nb = my_atoi(av[(*i) + 1])) < 0) ? exit(84) : 0;
        else if (!my_strcmp(av[*i], "-n"))
            return (1);
        if (!my_strcmp(av[*i], "-a") && *addr == -1)
            ((*addr = my_atoi(av[(*i) + 1]) % MEM_SIZE) < 0) ? exit(84) : 0;
        else if (!my_strcmp(av[*i], "-a"))
            return (1);
        (*i) = (*i) + 2;
    }
    return (0);
}

static int fill_data(champs_t *prgs, int ac, char **av, int *i)
{
    int j = 0;
    int nb = -1;
    int addr = -1;

    if (fill_arg(&nb, &addr, av, i))
        return (1);
    if (*i >= ac)
        return (1);
    if (fill_arg(&nb, &addr, av, i))
        return (1);
    if (*i >= ac)
        return (1);
    if (!is_contain_cor(av[*i]))
        return (1);
    for (j = 0; prgs->prgs[j] != NULL; j++);
    prgs->prgs[j] = get_prg(av[*i], nb, addr);
    (*i)++;
    if (prgs->prgs[j] == NULL)
        return (1);
    return (0);
}

void get_input(champs_t *prgs, int ac, char **av)
{
    int i = 0;

    av = dup_args(ac, av);
    ac = get_tab_len(av);
    while (av[i] != NULL) {
        if (fill_data(prgs, ac, av, &i)) {
            destroy_tab(av);
            destroy_struct(prgs);
            exit(84);
        }
    }
    destroy_tab(av);
}
