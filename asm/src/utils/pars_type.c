/*
** EPITECH PROJECT, 2019
** pars_type.c
** File description:
** pars type
*/

#include "asm.h"
#include "op.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

buf_t *pars_reg(char *str, buf_t *buf)
{
    char dest;

    str++;
    dest = (char) my_atoi(str);
    buf = add_char_buf(buf, dest, 1);
    return (buf);
}

file_t *pars_dir(char *str, file_t *cor, int index)
{
    char *dest = NULL;
    int n = 0;

    str++;
    if (*str == LABEL_CHAR) {
        str++;
        cor->label = str;
        (cor->label[0] == '\0') ? my_puterr("Undefined label\n") : 0;
        n = (index)?get_lab(cor, T_DIR):lit_to_big_endian(get_lab(cor, T_IND));
    } else
        n = (index) ? my_atoi_t(str) : lit_to_big_endian(my_atoi_t(str));
    dest = (char *) &n;
    if (index) {
        for (int i = 0; i < T_DIR; i += 1)
            cor->buf = add_char_buf(cor->buf, octet_size(n, T_DIR - 1 - i), 1);
    } else
        cor->buf = add_size_buf(cor->buf, dest, 1, 4);
    return (cor);
}

file_t *pars_ind(char *str, file_t *cor)
{
    int n = 0;

    if (*str == LABEL_CHAR) {
        str++;
        cor->label = str;
        (cor->label[0] == '\0') ? my_puterr("Undefined label\n") : 0;
        n = get_lab(cor, T_DIR);
    } else
        n = my_atoi_t(str);
    for (int i = 0; i < T_DIR; i += 1)
        cor->buf = add_char_buf(cor->buf, octet_size(n, T_DIR - 1 - i), 1);
    return (cor);
}
