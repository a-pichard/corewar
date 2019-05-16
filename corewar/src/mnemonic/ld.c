/*
** EPITECH PROJECT, 2019
** ld
** File description:
** ld
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"

void ld(corewar_t *cor, process_t *proc)
{
    int pc = proc->pc;
    op_t op_tab[] = {OP_TAB};
    char *type = conv_i_str(dec_to_in(cor->memory[(pc + 1) % MEM_SIZE]));
    int i = 0;
    int temp = 0;

    if (type[0] - 48 == 0 && type[2] - 48 == 0) {
        temp = cor->memory[(pc + 2) % MEM_SIZE];
        cor->memory[(pc + 3) % MEM_SIZE] = temp;
        proc->pc = (pc + 3) % MEM_SIZE;
    } else
        my_putstr("error");
    proc->sleep = op_tab[1].nbr_cycles;
    //cor->prgs[0]->carry = 1;
    free(type);
}