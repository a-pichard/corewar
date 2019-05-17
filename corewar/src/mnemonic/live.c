/*
** EPITECH PROJECT, 2019
** live
** File description:
** live
*/

#include "corewar.h"
#include "op.h"
#include "vec.h"

static void print_alive(int nb, char *prg_name)
{
    my_putstr("The player ");
    my_putnbr(nb);
    my_putstr(" (");
    my_putstr(prg_name);
    my_putstr(") is alive.\n");
}

void live(corewar_t *cor, vec_t *proc, int n)
{
    int index_proc = ((process_t *)proc->content[n])->pc;
    int parameter = 0;
    int x = 3;
    op_t op_tab[] = {OP_TAB};

    for (int i = 0; i <= 3; i++, x--)
        parameter += cor->memory[index_proc + (i + 1)] * power_bytes(256, x);
    cor->prgs[parameter]->live++;
    print_alive(cor->prgs[parameter]->nb, cor->prgs[parameter]->hd->prog_name);
    ((process_t *)proc->content[n])->pc = (((process_t *)proc->content[n])->pc + 4) % MEM_SIZE;
    ((process_t *)proc->content[n])->sleep = op_tab[0].nbr_cycles;
}
