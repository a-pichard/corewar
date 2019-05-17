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
#include <stdlib.h>

buf_t *add_char_buf(buf_t *buf, int c, int fr)
{
    int *dest = malloc(sizeof(int) * (buf->size + 2));
    int i;

    for (i = 0; buf->buf[i] != -1; i += 1)
        dest[i] = buf->buf[i];
    dest[i] = c;
    dest[i + 1] = -1;
    buf->size += 1;
    (fr) ? free(buf->buf) : 0;
    buf->buf = dest;
    return (buf);
}

int len_bin(char **file, int i, int end)
{
    int dest = 0;

    if (file[i] == NULL)
        return (0);
    (file[i] != NULL && empty_line(file[i])) ? i += 1 : 0;
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

buf_t *add_size_buf(buf_t *buf, char *src, int fr, int size)
{
    int *dest = malloc(sizeof(int) * (buf->size + size + 1));
    int i;
    int j;
    int k = 0;

    for (i = 0; buf->buf[i] != -1; i += 1) {
        dest[i] = buf->buf[i];
    }
    for (j = i; j - i < size; j += 1) {
        dest[j] = src[k];
        k += 1;
    }
    dest[j] = -1;
    buf->size += size;
    (fr) ? free(buf->buf) : 0;
    buf->buf = dest;
    return (buf);
}

buf_t *destroy_array_buf(char **tab, buf_t *buf)
{
    if (tab == NULL)
        return (buf);
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
    return (buf);
}
