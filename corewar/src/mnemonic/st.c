/*
** EPITECH PROJECT, 2019
** st
** File description:
** st
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"
#include <stdlib.h>

void st(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 3);
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));
    int temp = 0;

    if (type[2] - 48 == 0 && REG_VALID(args[1])) {
        cor->memory[pc + args[2] % IDX_MOD] = ((process_t *) \
        proc->content[n])->reg[args[1]];
        ((process_t *)proc->content[n])->pc = (pc + 4) % MEM_SIZE;
    } else if (type[2] - 48 == 1 && type[3] - 48 == 1 && REG_VALID(args[1])
    && REG_VALID(args[2])) {
        ((process_t *) proc->content[n])->reg[args[2]] = ((process_t *) \
        proc->content[n])->reg[args[1]];
        ((process_t *)proc->content[n])->pc = (pc + 4) % MEM_SIZE;
    } else
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
    ((process_t *)proc->content[n])->sleep = op_tab[2].nbr_cycles;
    free(type);
}
