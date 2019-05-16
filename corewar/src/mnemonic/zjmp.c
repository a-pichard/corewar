/*
** EPITECH PROJECT, 2019
** zjmp
** File description:
** zjmp
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"

void zjmp(corewar_t *cor, process_t *proc)
{
    int pc = proc->pc;
    op_t op_tab[] = {OP_TAB};

    if (cor->prgs[0]->carry == 1)
        proc->pc += cor->memory[(pc + 1) % MEM_SIZE] % IDX_MOD;
    proc->sleep = op_tab[8].nbr_cycles;
}