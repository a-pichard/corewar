/*
** EPITECH PROJECT, 2019
** sti
** File description:
** sti
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"
#include <stdlib.h>

void sti(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 3, 0);
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));

    ((process_t *)proc->content[n])->sleep = op_tab[10].nbr_cycles;
    if (type[0] != '0' || (type[4] == '1' && type[5] == '1') ||
        !REG_VALID(args[1]) || (type[2] == '0' && !REG_VALID(args[2])) ||
        (type[4] == '0' && !REG_VALID(args[3]))) {
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
        return;
    }
    if (type[2] == '0')
        args[2] = ((process_t *)proc->content[n])->reg[args[2] - 1];
    if (type[4] == '0')
        args[3] = ((process_t *)proc->content[n])->reg[args[3] - 1];
    cor->memory[((pc + args[2] + args[3]) % IDX_MOD) % MEM_SIZE] =
        ((process_t *)proc->content[n])->reg[args[1] - 1];
    ((process_t *)proc->content[n])->pc = (pc + 6) % MEM_SIZE;
    free(type);
}
