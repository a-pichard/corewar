/*
** EPITECH PROJECT, 2019
** ld
** File description:
** ld
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"
#include <stdlib.h>

void ld(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *arg = get_args(cor->memory, pc, 3);
    char *type = conv_i_str(dec_to_bin(arg[0]));
    int i_chmp = ((process_t *) proc->content[n])->chmp;

    if (type[2] - 48 == 0) {
        ((process_t *)proc->content[n])->reg[2] = pc + arg[2] % IDX_MOD;
        ((process_t *)proc->content[n])->pc = (pc + 4) % MEM_SIZE;
    } else
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
    ((process_t *)proc->content[n])->sleep = op_tab[1].nbr_cycles;
    cor->prgs[i_chmp]->carry = (arg[2] == 0);
    free(type);
}
