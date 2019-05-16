/*
** EPITECH PROJECT, 2019
** set_cor.c
** File description:
** set cor env
*/

#include "corewar.h"
#include "vec.h"
#include <stdio.h>

void check_ins(int *cycle, corewar_t *cor, vec_t *proc)
{
    int ins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, -1};
    void (*function[])(corewar_t *cor, process_t *proc) = FUNCTION_INS;
    int n;

    for (int i = 0; cor->prgs[i] != NULL; i += 1) {
        if (cor->prgs[i]->live >= NBR_LIVE) {
            *cycle = CYCLE_TO_DIE;
            return;
        }
    }
    for (int i = 0; i < (int) proc->element; i += 1) {
        n = index_of_int(cor->memory[((process_t *)proc->content[i])->pc], ins);
        if (n == -1) {
            ((process_t *)proc->content[i])->pc =
                (((process_t *)proc->content[i])->pc + 1) % MEM_SIZE;
            continue;
        }
        (function[n])(cor, (process_t *)proc->content[i]);
    }
}

void my_vm(corewar_t *cor, vec_t *proc)
{
    int cycle_d;
    int cycle;

    for (cycle_d = CYCLE_TO_DIE; cycle_d > 0; cycle -= CYCLE_DELTA) {
        for (cycle = 0; cycle < cycle_d; cycle += 1) {
            check_ins(&cycle, cor, proc);
        }
        for (int i = 0; cor->prgs[i] != NULL; i += 1)
            cor->prgs[i]->live = 0;
        for (int i = 0; i < (int) proc->element; i += 1)
            ((process_t *)proc->content[i])->sleep = 0;
    }
}

int set_cor(corewar_t *cor)
{
    process_t *proc;
    vec_t *process = create_vec();

    for (int i = 0; i < cor->nb_prg; i += 1) {
        proc = xmalloc(sizeof(process_t));
        proc->pc = cor->prgs[i]->addr;
        proc->sleep = 0;
        for (int i = 0; i < REG_NUMBER; i += 1)
            proc->reg[i] = 0;
        proc->reg[0] = cor->prgs[i]->index;
        push(process, proc);
    }
    for (int i = 0; i < cor->nb_prg - 1; i += 1)
        process = sort_process(process, cor);
    //my_vm(cor, process);
    return (0);
}
