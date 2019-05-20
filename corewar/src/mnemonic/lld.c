/*
** EPITECH PROJECT, 2019
** lld
** File description:
** lld
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"
#include <stdlib.h>

void lld(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 2, 0);
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));
    int i_chmp = ((process_t *) proc->content[n])->chmp;

    ((process_t *)proc->content[n])->sleep = op_tab[1].nbr_cycles;
    if (args != NULL && type[2] - 48 == 0 && REG_VALID(args[2])) {
        ((process_t *)proc->content[n])->reg[args[2] - 1] =
            read_size(REG_SIZE, pc + args[1], cor);
        ((process_t *)proc->content[n])->pc = (pc + args[3]) % MEM_SIZE;
        cor->prgs[i_chmp]->carry = (args[2] == 0);
    } else
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
    free(type);
    free(args);
}
