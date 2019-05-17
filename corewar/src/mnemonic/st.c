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

void st(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    char *type = conv_i_str(dec_to_bin(cor->memory[(pc + 1) % MEM_SIZE]));
    int temp = 0;

    if (type[0] - 48 == 0) {
        temp = cor->memory[(pc + 2) % MEM_SIZE];
        cor->memory[(pc + 3) % MEM_SIZE] = temp;
        ((process_t *)proc->content[n])->pc = (pc + 3) % MEM_SIZE;
    }
    //else
    // {
    //   offset = VM_MEMORY_ADRESS(champ->PC + (argv[1] % IDX_MOD));
    //   addr = (unsigned int *) &(arena->MemoryMap[offset]);
    //   print_int((char *) addr, champ->Args[argv[0]]);
    // }
    ((process_t *)proc->content[n])->sleep = op_tab[2].nbr_cycles;
    free(type);
}
