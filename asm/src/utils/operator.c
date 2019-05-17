/*
** EPITECH PROJECT, 2019
** operator.c
** File description:
** operator
*/

#include "asm.h"
#include "op.h"
#include <stddef.h>
#include <stdio.h>

int char_instr(char *str, char c)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] == c)
            return (1);
    return (0);
}

int instruction(char **str, int n, int i, op_t op_tab[])
{
    int dest = 1;
    int mem;
    int k;

    (op_tab[i].code != 1 && op_tab[i].code != 9 && op_tab[i].code != 12 &&
        op_tab[i].code != 15) ? dest += 1 : 0;
    for (k = n; str[k] != NULL; k += 1);
    (k - n - 1 != op_tab[i].nbr_args) ? my_puterr("Invalid instruction\n") : 0;
    for (int m = 0; m != op_tab[i].nbr_args; m += 1) {
        if ((mem = type(str[n + m + 1])) == -1 || !(mem & op_tab[i].type[m]))
            my_puterr("Invalid instruction\n");
        (mem == T_DIR) ? mem = DIR_SIZE : (mem == T_IND) ? mem = IND_SIZE : 0;
        (mem == DIR_SIZE && !m && (op_tab[i].code == 9 || op_tab[i].code == 10
            || op_tab[i].code == 12 || op_tab[i].code == 15))?mem = IND_SIZE:0;
        (mem == DIR_SIZE && m == 1 && (op_tab[i].code == 11 || op_tab[i].code ==
            10 || op_tab[i].code == 14))?mem = IND_SIZE:0;
        (mem == DIR_SIZE && m == 2 && (op_tab[i].code == 11 ||
                op_tab[i].code == 14)) ? dest += 2 : (dest += mem);
    }
    return (destroy_array(str, dest));
}

int pars_label(int i, char **file)
{
    i += 1;
    while (file[i] != NULL && empty_line(file[i]))
        i += 1;
    return (i);
}

int operator(char **str, int n, char **file, int *j)
{
    int i;
    char **mem = my_str_to_word_tab(file[*j]);
    op_t op_tab[] = {OP_TAB};

    for (i = 0; op_tab[i].mnemonique != NULL &&
            my_strcmp(op_tab[i].mnemonique, str[n]); i += 1);
    if (op_tab[i].mnemonique == NULL) {
        if (str[n][my_strlen(str[n]) - 1] != LABEL_CHAR || n ||
            (mem[1] == NULL && my_strcmp(str[n], mem[n])))
            my_puterr("Invalid syntax\n");
        if (my_strlen(str[n]) == 1 || !is_lab(str[n]))
            my_puterr("Invalid label\n");
        if (str[1] == NULL)
            return (operator(my_str_to_word_tab(file[pars_label(*j, file)]),
                destroy_array(mem, destroy_array(str, 0)), file, j));
        return (operator(str, destroy_array(mem, 1), file, j));
    }
    if (my_strcmp(str[n], mem[n]))
        *j = pars_label(*j, file);
    return (instruction(str, n, destroy_array(mem, i), op_tab));
}
