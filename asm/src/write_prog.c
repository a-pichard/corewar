/*
** EPITECH PROJECT, 2019
** write_prog.c
** File description:
** prog
*/

#include "asm.h"
#include "op.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char my_bin(char **str, int n, int i, op_t op_tab[])
{
    long bin = 0;
    int t;
    int len = 3;

    for (int m = 0; m != op_tab[i].nbr_args; m += 1) {
        t = type(str[n + m + 1]);
        if (t == -1)
            my_puterr("invalid instruction\n");
        if (t == T_DIR)
            bin += 10;
        if (t == T_REG)
            bin += 1;
        if (t == T_IND)
            bin += 11;
        bin = bin * 100;
        len -= 1;
    }
    for (int i = len; i > 0; i -= 1)
        bin = bin * 100;
    return ((char) bin_to_dec(bin, 0));
}

file_t *my_instruct(int i, file_t *cor, char *instruct, int m)
{
    int t = type(instruct);
    op_t op_tab[] = {OP_TAB};

    if (t == T_REG)
        cor->buf = pars_reg(instruct, cor->buf);
    if (t == T_DIR) {
        if (!m && (op_tab[i].code == 9 || op_tab[i].code == 10 ||
                op_tab[i].code == 12 || op_tab[i].code == 15))
            return (pars_dir(instruct, cor, 1));
        if (m == 1 && (op_tab[i].code == 10 || op_tab[i].code == 11 ||
                op_tab[i].code == 14))
            return (pars_dir(instruct, cor, 1));
        if (m == 2 && (op_tab[i].code == 11 || op_tab[i].code == 14))
            return (pars_dir(instruct, cor, 1));
        cor = pars_dir(instruct, cor, 0);
    }
    if (t == T_IND)
        cor = pars_ind(instruct, cor);
    return (cor);
}

file_t *write_instruction(char **str, file_t *cor, int i, op_t op_tab[])
{
    int n = (is_lab(str[0])) ? 1 : 0;
    char bin = my_bin(str, n, i, op_tab);

    cor->buf = add_char_buf(cor->buf, op_tab[i].code, 1);
    (op_tab[i].code != 1 && op_tab[i].code != 9 && op_tab[i].code != 12 &&
        op_tab[i].code != 15) ? cor->buf = add_char_buf(cor->buf, bin, 1) : 0;
    for (int m = 0; m != op_tab[i].nbr_args; m += 1) {
        cor = my_instruct(i, cor, str[n + m + 1], m);
    }
    for (int i = 0; str[i] != NULL; i += 1)
        free(str[i]);
    free(str);
    return (cor);
}

file_t *write_op(char **str, file_t *cor, char **file, int *j)
{
    int i;
    char **mem = my_str_to_word_tab(file[*j]);
    op_t op_tab[] = {OP_TAB};
    int n = (is_lab(str[0])) ? 1 : 0;

    for (i = 0; op_tab[i].mnemonique != NULL && str[n] != NULL &&
            my_strcmp(op_tab[i].mnemonique, str[n]); i += 1);
    if (op_tab[i].mnemonique == NULL || str[n] == NULL) {
        if (str[1] == NULL) {
            return (write_op(my_str_to_word_tab(file[pars_label(*j, file)]),
                cor, file, destroy_array_t(mem, destroy_array_t(str, j))));
        }
        return (write_op(str, cor, file, destroy_array_t(mem, j)));
    }
    if (str[n] != NULL && my_strcmp(str[n], mem[n]))
        *j = pars_label(*j, file);
    cor->pos = *j;
    return (write_instruction(str, cor, destroy_array(mem, i), op_tab));
}

file_t *prog(char **file, int i, buf_t *buf)
{
    file_t *cor = malloc(sizeof(file_t));

    (cor == NULL) ? my_puterr("malloc err\n") : 0;
    cor->file = file;
    cor->buf = buf;
    cor->start = i;
    while (file[i] != NULL) {
        while (file[i] != NULL && empty_line(file[i]))
            i += 1;
        if (file[i] != NULL) {
            cor = write_op(my_str_to_word_tab(file[i]), cor, file, &i);
            i += 1;
        }
    }
    return (cor);
}
