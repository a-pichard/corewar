/*
** EPITECH PROJECT, 2019
** add
** File description:
** add
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"
#include <stdlib.h>

void add(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 4, 0);
    char *type = conv_i_str(dec_to_bin(args[0]));
    int i_chmp = ((process_t *)proc->content[n])->chmp;
    mem_t *reg = ((process_t *)proc->content[n])->reg;

    if (type[0] - 48 == 0 && type[2] - 48 == 0 && type[4] - 48 == 0 &&
    REG_VALID(args[1]) && REG_VALID(args[2]) && REG_VALID(args[3])) {
        ((process_t *) proc->content[n])->reg[args[3]] \
        = reg[args[1]] + reg[args[2]];
        ((process_t *)proc->content[n])->pc = (pc + 5) % MEM_SIZE;
    } else
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
    ((process_t *)proc->content[n])->sleep = op_tab[3].nbr_cycles;
    cor->prgs[i_chmp]->carry = (((process_t *) proc->content[n])->reg[args[3]]
    == 0);
    free(type);
    free(args);
}
