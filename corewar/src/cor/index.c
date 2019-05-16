/*
** EPITECH PROJECT, 2019
** index.c
** File description:
** index
*/

#include "corewar.h"

int index_of_champ(corewar_t *cor, int n)
{
    for (int i = 0; i < cor->nb_prg; i += 1) {
        if (cor->prgs[i]->index == n)
            return (cor->prgs[i]->nb);
    }
    return (-1);
}

int index_of_int(mem_t mem, int *ins)
{
    for (int i = 0; ins[i] != -1; i += 1) {
        if (ins[i] == mem)
            return (i);
    }
    return (-1);
}

vec_t *sort_process(vec_t *proc, corewar_t *cor)
{
    void *mem;

    for (int i = 0; i < cor->nb_prg - 1; i += 1) {
        if (index_of_champ(cor, ((process_t *)proc->content[i])->reg[0]) <
            index_of_champ(cor, ((process_t *)proc->content[i+1])->reg[0])) {
            mem = proc->content[i];
            proc->content[i] = proc->content[i + 1];
            proc->content[i + 1] = mem;
        }
    }
    return (proc);
}
