/*
** EPITECH PROJECT, 2019
** zjmp
** File description:
** zjmp
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"

void zjmp(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};

    if (cor->prgs[0]->carry == 1)
        ((process_t *)proc->content[n])->pc += cor->memory[(pc + 1) % MEM_SIZE] % IDX_MOD;
    ((process_t *)proc->content[n])->sleep = op_tab[8].nbr_cycles;
}
