/*
** EPITECH PROJECT, 2019
** xor
** File description:
** xor
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"
#include <stdlib.h>

void xor(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 3, 0);
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));

    ((process_t *)proc->content[n])->sleep = op_tab[7].nbr_cycles;
    if (args != NULL && type[0] == '0')
        args[1] = ((process_t *)proc->content[n])->reg[args[1] - 1];
    if (args != NULL && type[2] == '0')
        args[2] = ((process_t *)proc->content[n])->reg[args[2] - 1];
    if (args && type[0] == '0' && type[2] == '0' && type[4] == '0' &&
    REG_VALID(args[1]) && REG_VALID(args[2]) && REG_VALID(args[3])) {
        ((process_t *) proc->content[n])->reg[args[3] - 1] = args[1] ^ args[2];
        ((process_t *)proc->content[n])->pc = (pc + args[4]) % MEM_SIZE;
        cor->prgs[((process_t *)proc->content[n])->chmp]->carry = \
        (((process_t *) proc->content[n])->reg[args[3] - 1] == 0);
    } else
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
    free(type);
    free(args);
}
