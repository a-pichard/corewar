/*
** EPITECH PROJECT, 2019
** lld
** File description:
** lld
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"

void lld(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 3);
    char *type = conv_i_str(dec_to_bin(args[0]));
    int i_chmp = ((process_t *) proc->content[n])->chmp;

    if (type[2] - 48 == 0 && REG_VALID(args[2])) {
        ((process_t *)proc->content[n])->reg[args[2]] = pc + args[1];
        ((process_t *)proc->content[n])->pc = (pc + 4) % MEM_SIZE;
    } else
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
    ((process_t *)proc->content[n])->sleep = op_tab[1].nbr_cycles;
    cor->prgs[i_chmp]->carry = (args[2] == 0);
    free(type);
    free(args);
}