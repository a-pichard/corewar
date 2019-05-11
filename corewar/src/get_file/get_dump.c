/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_dump
*/

#include "corewar.h"
#include <stdio.h>

static int get_nb_dash_dump(int ac, char **av, int *index)
{
    int i = 1;
    int count = 0;

    while (i < ac) {
        if (!my_strcmp(av[i], "-dump")) {
            *index = i;
            count++;
        }
        i++;
    }
    return (count);
}

int get_dump(int ac, char **av)
{
    int index;
    int nb_dump =  get_nb_dash_dump(ac, av, &index);
    char *dump = NULL;

    if (nb_dump == 0)
        return (-1);
    if (nb_dump > 1)
        return (-2);
    dump = av[index + 1];
    if (!is_nb_pos(dump))
        return (-2);
    return (my_atoi(dump));
}