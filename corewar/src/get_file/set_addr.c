/*
** EPITECH PROJECT, 2019
** set_addr.c
** File description:
** set addr prg
*/

#include "op.h"
#include "corewar.h"
#include <stddef.h>
#include <stdio.h>

int have_addr(corewar_t *prgs)
{
    int finish = 0;

    for (int i = 0; prgs->prgs[i] != NULL; i += 1) {
        if (prgs->prgs[i]->addr == -1)
            finish += 1;
    }
    return (finish);
}

corewar_t *place_addr(corewar_t *prgs, int n)
{
    int addr = prgs->prgs[n]->addr;
    int i;

    for (i = 0; i < prgs->prgs[n]->hd->prog_size; i += 1) {
        if (prgs->memory[(addr + i) % MEM_SIZE] != '\0') {
            my_puterr("invalid mem\n");
        }
        prgs->memory[(addr + i) % MEM_SIZE] = prgs->prgs[n]->prg[i];
    }
    prgs->prgs[n]->p_addr = 1;
    return (prgs);
}

int choose_addr(corewar_t *prgs, int rest)
{
    int size = 0;
    int addr = 0;
    int i;
    int j;
    int k;

    if (rest == prgs->nb_prg)
        return (0);
    for (i = 0; i < MEM_SIZE && prgs->memory[i] == '\0'; i += 1);
    for (; i % MEM_SIZE < MEM_SIZE && prgs->memory[i] != '\0'; i += 1);
    k = i;
    j = i;
    while (j % MEM_SIZE != i - 1) {
        for (j = k; j % MEM_SIZE != i - 1 && prgs->memory[j] == '\0'; j += 1);
        (size < j - k) ? addr = k : 0;
        (size < j - k) ? size = j - k : 0;
        for (k = j; prgs->memory[k % MEM_SIZE] != '\0'; k += 1);
    }
    return ((addr + size / (rest + 1)) % MEM_SIZE);
}

corewar_t *set_addr(corewar_t *prgs)
{
    int finish;
    int n = 0;

    while ((finish = have_addr(prgs)) != 0) {
        for (int i = 0; prgs->prgs[i] != NULL; i += 1)
            (prgs->prgs[i]->addr != -1 && !prgs->prgs[i]->p_addr) ?
            prgs = place_addr(prgs, i) : 0;
        if (prgs->prgs[n]->addr == -1)
            prgs->prgs[n]->addr = choose_addr(prgs, finish);
        n += 1;
    }
    for (int i = 0; prgs->prgs[i] != NULL; i += 1)
        (prgs->prgs[i]->addr != -1 && !prgs->prgs[i]->p_addr) ?
            prgs = place_addr(prgs, i) : 0;
    return (prgs);
}
