/*
** EPITECH PROJECT, 2019
** end.c
** File description:
** end
*/

#include "corewar.h"
#include <stdlib.h>

int dec_hexa(int c)
{
    char *res = NULL;
    static const char digits[] = "0123456789ABCDEF";
    unsigned int quotient = c;
    int size = 0;

    do {
        quotient /= 16;
        size++;
    } while (quotient != 0);
    if ((res = malloc(size)) == NULL)
        my_puterr("Erreur d'allocation mémoire...\n");
    res[size] = '\0';
    quotient = c;
    do {
        size--;
        res[size] = digits[quotient % 16];
        quotient /= 16;
    } while (quotient != 0);
    (my_strlen(res) == 1) ? res = my_realloc("0", res) : 0;
    my_putstr(res);
    return (5 - my_strlen(res));
}

void print_space(int n)
{
    for (int i = 0; i < n; i += 1)
        my_putchar(' ');
    my_putchar(':');
}

void print_end(corewar_t *cor, int index)
{
    my_putstr("The player ");
    my_putnbr(cor->prgs[index]->nb);
    my_putstr(" (");
    my_putstr(cor->prgs[index]->hd->prog_name);
    my_putstr(") has won.\n");
}

void end_dump(corewar_t *cor)
{
    int finish = 0;
    int index = 0;

    for (int i = 0; i < MEM_SIZE; i += 1) {
        if (i % 32 == 0) {
            my_putchar('\n');
            print_space(dec_hexa(i));
        }
        my_putchar(' ');
        dec_hexa(cor->memory[i]);
    }
    my_putchar('\n');
    for (int i = 0; cor->prgs[i] != NULL; i += 1) {
        if (cor->prgs[i]->live > finish) {
            finish = cor->prgs[i]->live;
            index = i;
        }
    }
    print_end(cor, index);
    destroy_struct(cor);
    exit(0);
}

void is_end(corewar_t *cor)
{
    int finish = 0;
    int index = 0;

    for (int i = 0; cor->prgs[i] != NULL; i += 1) {
        if (cor->prgs[i]->live > 0) {
            finish += 1;
            index = i;
        }
    }
    if (finish > 1)
        return;
    print_end(cor, index);
    destroy_struct(cor);
    exit(0);
}
