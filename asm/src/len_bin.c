/*
** EPITECH PROJECT, 2019
** len_bin.c
** File description:
** len bin
*/

#include "asm.h"
#include "op.h"
#include <stddef.h>
#include <stdio.h>

int len_bin(char **file, int i, int end)
{
    int dest = 0;

    i += 1;
    while (file[i] != NULL && end != i) {
        while (file[i] != NULL && end != i && empty_line(file[i]))
            i += 1;
        if (file[i] != NULL && end != i) {
            dest += operator(my_str_to_word_tab(file[i]), 0, file, &i);
            i += 1;
        }
    }
    return (dest);
}
