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
#include <stdio.h>

int reg_valid(int n)
{
    if (n <= 0 || n > REG_NUMBER + 1)
        return (0);
    return (1);
}

void st(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 2, 0);
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));

    ((process_t *)proc->content[n])->sleep = op_tab[2].nbr_cycles;
    if (args != NULL && type[2] - 48 == 0 && reg_valid(args[1])) {
        cor = write_size(((process_t *)proc->content[n])->reg[args[1] - 1],
                REG_SIZE, pc + args[2] % IDX_MOD, cor);
        ((process_t *)proc->content[n])->pc = (pc + args[3]) % MEM_SIZE;
    } else if (args != NULL && type[2] - 48 == 1 && type[3] - 48 == 1 &&
            reg_valid(args[2]) && reg_valid(args[1])) {
        ((process_t *) proc->content[n])->reg[args[2] - 1] = ((process_t *) \
        proc->content[n])->reg[args[1] - 1];
        ((process_t *)proc->content[n])->pc = (pc + args[3]) % MEM_SIZE;
    } else
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
    free(type);
    free(args);
}
