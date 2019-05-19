/*
** EPITECH PROJECT, 2019
** ldi
** File description:
** ldi
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"
#include <stdlib.h>

void lldi_suit(vec_t *proc, int n, corewar_t *cor, int *args)
{
    int pc = ((process_t *)proc->content[n])->pc;
    int i_chmp = ((process_t *)proc->content[n])->chmp;
    int add = 0;
    int dest = 0;

    for (int i = 0; i < IND_SIZE; i += 1)
        add += cor->memory[(pc + (args[1] + i)) % MEM_SIZE] *
            my_pow(256, IND_SIZE - 1 - i);
    add += args[2];
    for (int i = 0; i < REG_SIZE; i += 1)
        dest += cor->memory[(pc + (add + i)) % MEM_SIZE] *
            my_pow(256, REG_SIZE - 1 - i);
    ((process_t *)proc->content[n])->reg[args[3] - 1] = dest;
    ((process_t *)proc->content[n])->pc = (pc + args[4]) % MEM_SIZE;
    cor->prgs[i_chmp]->carry = REG_VALID(args[3]) ? \
        (((process_t *)proc->content[n])->reg[args[3] - 1] == 0) : 0;
}

void lldi(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 3, 0);
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));
    int i_chmp = ((process_t *)proc->content[n])->chmp;

    ((process_t *)proc->content[n])->sleep = op_tab[9].nbr_cycles;
    if (args != NULL || (type[2] == '1' && type[3] == '1') || type[4] != '0' ||
        !REG_VALID(args[3]) || (type[0] == '0' && !REG_VALID(args[1])) ||
        (type[2] == '0' && !REG_VALID(args[2]))) {
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
        return;
    }
    if (type[0] == '0')
        args[1] = ((process_t *)proc->content[n])->reg[args[1] - 1];
    if (type[2] == '0')
        args[2] = ((process_t *)proc->content[n])->reg[args[2] - 1];
    lldi_suite(proc, n, cor, args);
    free(type);
}
