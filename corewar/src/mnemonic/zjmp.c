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
    int *args = get_args(cor->memory, pc, 1);
    int i_chmp = ((process_t *)proc->content[n])->chmp;

    if (cor->prgs[i_chmp]->carry == 1)
        ((process_t *)proc->content[n])->pc = \
        (pc + args[0] % IDX_MOD) % MEM_SIZE;
    else
        ((process_t *)proc->content[n])->pc = (pc + 2) % MEM_SIZE;
    ((process_t *)proc->content[n])->sleep = op_tab[8].nbr_cycles;
}