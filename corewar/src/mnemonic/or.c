/*
** EPITECH PROJECT, 2019
** or
** File description:
** or
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"
#include <stdlib.h>

void or(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 3, 0);
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));
    int i_chmp = ((process_t *)proc->content[n])->chmp;
    mem_t *reg = ((process_t *)proc->content[n])->reg;

    ((process_t *)proc->content[n])->sleep = op_tab[6].nbr_cycles;
    if (args != NULL && type[0] == '0' && type[2] == '0' && type[4] == '0' &&
    REG_VALID(args[1]) && REG_VALID(args[2]) && REG_VALID(args[3])) {
        ((process_t *) proc->content[n])->reg[args[3] - 1] \
        = reg[args[1] - 1] | reg[args[2] - 1];
        ((process_t *)proc->content[n])->pc = (pc + args[4]) % MEM_SIZE;
    } else {
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
        return;
    }
    cor->prgs[i_chmp]->carry = \
    (((process_t *) proc->content[n])->reg[args[3] - 1] == 0);
    free(type);
    free(args);
}
