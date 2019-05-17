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
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));
    int temp = 0;

    if (type[0] - 48 == 0 && type[2] - 48 == 0 && type[4] - 48 == 0) {
        cor->memory[pc + 4] = cor->memory[pc + 2] | cor->memory[pc + 3];
        ((process_t *)proc->content[n])->pc = (pc + 4) % MEM_SIZE;
    } else
        my_putstr("is not a register\n");
    ((process_t *)proc->content[n])->sleep = op_tab[6].nbr_cycles;
    //cor->prgs[0]->carry = 1;
    free(type);
}
