/*
** EPITECH PROJECT, 2019
** label.c
** File description:
** label
*/

#include "asm.h"
#include "op.h"
#include <stddef.h>
#include <stdio.h>

int my_lab(char **str, file_t *cor)
{
    if (str[0] == NULL)
        return (0);
    if (is_lab(str[0]) && !my_strcmp_lab(str[0], cor->label))
        return (1);
    return (0);
}

long my_pow(long n, int y)
{
    long dest = n;

    for (int i = y; i > 0; i -= 1) {
        dest = dest * n;
    }
    return (dest);
}

long get_lab(file_t *cor, int n)
{
    int i;

    n = my_pow(256, n);
    for (i = cor->pos; i > cor->start; i -= 1) {
        while (i > cor->start && empty_line(cor->file[i]))
            i -= 1;
        if (my_lab(my_str_to_word_tab(cor->file[i]), cor))
            break;
    }
    if (i > cor->start)
        return (n - len_bin(cor->file, i - 1, cor->pos));
    for (i = cor->pos; cor->file[i] != NULL; i += 1) {
        while (cor->file[i] != NULL && empty_line(cor->file[i]))
            i += 1;
        if (my_lab(my_str_to_word_tab(cor->file[i]), cor))
            break;
    }
    if (cor->file[i] != NULL)
        return (len_bin(cor->file, cor->pos - 1, i));
    my_puterr("Label doesn't exist\n");
    return (0);
}
