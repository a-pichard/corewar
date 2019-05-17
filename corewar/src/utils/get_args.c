/*
** EPITECH PROJECT, 2019
** get arg
** File description:
** get args of instrcution
*/

#include "corewar.h"

int *get_args(mem_t *memory, int pc, int nbr_arg)
{
    int *arg = xmalloc(sizeof(int) * (nbr_arg + 1));

    for (int i = 0; i <= nbr_arg; i++)
        arg[i] = memory[(pc + (i + 1)) % MEM_SIZE];
    return (arg);
}