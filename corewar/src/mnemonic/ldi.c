/*
** EPITECH PROJECT, 2019
** ldi
** File description:
** ldi
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"

void ldi(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 4);
    char *type = conv_i_str(dec_to_bin(args[0]));
    int i_chmp = ((process_t *) proc->content[n])->chmp;
    int add = 0;

    if (type[0] - 48 == 1 && type[1] - 48 == 1 && type[2] - 48 == 1
    && type[3] - 48 == 0 && type[4] - 48 == 0 && REG_VALID(args[3])) {

        ((process_t *)proc->content[n])->pc = (pc + 5) % MEM_SIZE;
    } else
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
    cor->prgs[i_chmp]->carry = REG_VALID(args[3]) ?
    (((process_t *)proc->content[n])->reg[args[3]] == 0) : 0;
}