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

op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
  };

int char_instr(char *str, char c)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] == c)
            return (1);
    return (0);
}

int is_ind(char *str)
{
    int br = 0;

    if (*str == LABEL_CHAR) {
        str++;
        while (*str && !br) {
            (!char_instr(LABEL_CHARS, *str)) ? br = 1 : 0;
            str++;
        }
    } else {
        while (*str && !br) {
            (*str < '0' || *str > '9') ? br = 1 : 0;
            str++;
        }
    }
    if (br)
        return (0);
    return (1);
}

int is_reg(char *str)
{
    if (*str != 'r')
        return (0);
    str++;
    if (my_atoi(str) > REG_NUMBER)
        return (0);
    return (1);
}

int is_dir(char *str)
{
    int br = 0;

    if (*str != DIRECT_CHAR)
        return (0);
    str++;
    if (*str == LABEL_CHAR) {
        str++;
        while (*str && !br) {
            (!char_instr(LABEL_CHARS, *str)) ? br = 1 : 0;
            str++;
        }
    } else {
        while (*str && !br) {
            (*str < '0' || *str > '9') ? br = 1 : 0;
            str++;
        }
    }
    if (br)
        return (0);
    return (1);
}

int type(char *str)
{
    if (is_dir(str))
        return (T_DIR);
    if (is_reg(str))
        return (T_REG);
    if (is_ind(str))
        return (T_IND);
    return (-1);
}

int instruction(char **str, int n, int i)
{
    int dest = 1;
    int mem;
    int k;

    (op_tab[i].code != 1 && op_tab[i].code != 9 && op_tab[i].code != 12 &&
        op_tab[i].code != 15) ? dest += 1 : 0;
    for (k = n; str[k] != NULL; k += 1);
    (k - n - 1 != op_tab[i].nbr_args) ? my_puterr("Invalid instruction\n") : 0;
    for (int m = 0; m != op_tab[i].nbr_args; m += 1) {
        if (!((mem = type(str[n + m + 1])) & op_tab[i].type[m]) || mem == -1)
            my_puterr("Invalid instruction\n");
        (mem == T_DIR) ? mem = DIR_SIZE : (mem == T_IND) ? mem = IND_SIZE : 0;
        (mem == DIR_SIZE && !m && (op_tab[i].code == 9 || op_tab[i].code == 10
            || op_tab[i].code == 12)) ? mem = IND_SIZE : 0;
        (mem == DIR_SIZE && m == 1 &&
            (op_tab[i].code == 11 || op_tab[i].code == 10))?mem = IND_SIZE:0;
        (mem == DIR_SIZE && m == 2 && op_tab[i].code == 11) ?
            dest += 2 : (dest += mem);
    }
    return (dest);
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

    for (i = 0; op_tab[i].mnemonique != NULL &&
            my_strcmp(op_tab[i].mnemonique, str[n]); i += 1);
    if (op_tab[i].mnemonique == NULL) {
        if (str[n][my_strlen(str[n]) - 1] != LABEL_CHAR || n ||
            (mem[1] == NULL && my_strcmp(str[n], mem[n])))
            my_puterr("Invalid syntax\n");
        if (my_strlen(str[n]) == 1)
            my_puterr("Invalid label\n");
        if (str[1] == NULL)
            return (operator(my_str_to_word_tab(file[pars_label(*j, file)]),
                0, file, j));
        return (operator(str, 1, file, j));
    }
    if (my_strcmp(str[n], mem[n]))
        *j = pars_label(*j, file);
    return (instruction(str, n, i));
}
