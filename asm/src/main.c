/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "asm.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    char **file = get_file(ac, av);
    char *filename = get_filename(av[1]);

    print_tab(file);
    my_putchar('\n');
    my_putstr(filename);
    free(filename);
    destroy_tab(file);
    return (0);
}