/*
** EPITECH PROJECT, 2019
** aff
** File description:
** aff
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"
#include <stdlib.h>

void aff(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 2, 0);
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));

    ((process_t *)proc->content[n])->sleep = op_tab[15].nbr_cycles;
    if (args != NULL && type[0] - 48 == 0 && REG_VALID(args[1])) {
        my_putchar(((process_t *)proc->content[n])->reg[args[1] - 1] % 256);
        ((process_t *)proc->content[n])->pc = (pc + 3) % MEM_SIZE;
    } else
        ((process_t *)proc->content[n])->pc = (pc + 1) % MEM_SIZE;
    free(type);
}
