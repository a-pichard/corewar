/*
** EPITECH PROJECT, 2019
** live
** File description:
** live
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"

void live(corewar_t *cor, process_t *proc)
{
    int index_proc = proc->pc;
    int parameter = 0;
    int x = 3;
    op_t op_tab[] = {OP_TAB};

    for (int i = 0; i <= 3; i++, x--)
        parameter += cor->memory[index_proc + (i + 1)] * power_bytes(256, x);
    cor->prgs[parameter]->live++;
    printf("Le joueur %d (%s) est en vie.", cor->prgs[parameter]->index, \
    cor->prgs[parameter]->hd->prog_name);
    proc->pc = (proc->pc + 4) % MEM_SIZE;
    proc->sleep = op_tab[0].nbr_cycles;
}