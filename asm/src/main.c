/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "asm.h"

int main(int ac, char **av)
{
    char **file = get_file(ac, av);

    print_tab(file);
    destroy_tab(file);
    return (0);
}