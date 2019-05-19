/*
** EPITECH PROJECT, 2019
** fork
** File description:
** fork
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"

void f_fork(corewar_t *cor, vec_t *proc, int n)
{
    process_t *process;
    int pc = ((process_t *)proc->content[n])->pc;
    op_t op_tab[] = {OP_TAB};
    int *args = get_args(cor->memory, pc, 1, 1);

    process = xmalloc(sizeof(process_t));
    process->pc = (pc + args[0] % IDX_MOD) % MEM_SIZE;
    process->sleep = 0;
    for (int i = 0; i < REG_NUMBER; i += 1)
        process->reg[i] = 0;
    process->chmp = ((process_t *)proc->content[n])->chmp;
    push(proc, process);
    ((process_t *)proc->content[n])->pc = (pc + 3) % MEM_SIZE;
    ((process_t *)proc->content[n])->sleep = op_tab[11].nbr_cycles;
}
