/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "asm.h"
#include <stdlib.h>

static void check_args(int ac, char **av)
{
    if (ac < 2)
        helper(av[0], 84);
    if (!my_strcmp(av[1], "-h"))
        helper(av[0], 0);
}

int main(int ac, char **av)
{
    char **file = NULL;
    char *filename = NULL;
    int i = 1;

    check_args(ac, av);
    while (i != ac) {
        file = get_file(av[0], av[i]);
        filename = get_filename(av[i]);
        parser_file(file, filename);
        destroy_tab(file);
        free(filename);
        i++;
    }
    return (0);
}
