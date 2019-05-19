/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "corewar.h"
#include "op.h"
#include <stdio.h>

int main(int ac, char **av)
{
    corewar_t *cor = get_prgs(ac, av);

    if (cor == NULL)
        return (84);
    set_cor(cor);
    destroy_struct(cor);
    return (0);
}
