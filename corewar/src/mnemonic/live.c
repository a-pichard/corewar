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
    my_putstr("(");
    my_putstr(prg_name);
    my_putstr(") is alive.\n");
}

void live(corewar_t *cor, vec_t *proc, int n)
{
    int pc = ((process_t *)proc->content[n])->pc;
    int parameter = -1;
    int arg = 0;
    op_t op_tab[] = {OP_TAB};
    char *name;

    for (int i = 0; i < REG_SIZE; i += 1)
        arg += cor->memory[(pc + i + 1) % MEM_SIZE] *
            my_pow(256, REG_SIZE - i - 1);
    ((process_t *)proc->content[n])->sleep = op_tab[0].nbr_cycles;
    for (int i = 0; cor->prgs[i] != NULL; i += 1)
        if (cor->prgs[i]->nb == arg)
            parameter = i;
    if (parameter != -1) {
        name = cor->prgs[parameter]->hd->prog_name;
        print_alive(cor->prgs[parameter]->nb, name);
    }
    ((process_t *)proc->content[n])->pc = (pc + 5) % MEM_SIZE;
}
