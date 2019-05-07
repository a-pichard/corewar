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

int pars_reg(char *str, int fd)
{
    char dest;

    str++;
    dest = (char) my_atoi(str);
    write(fd, &dest, 1);
    return (fd);
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
        for (int i = 0; i  < T_DIR; i += 1)
            write(cor->fd, &dest[T_DIR - 1 - i], 1);
    } else
        write(cor->fd, dest, T_IND);
    return (cor);
}

file_t *pars_ind(char *str, file_t *cor)
{
    char *dest = NULL;
    int n = 0;

    if (*str == LABEL_CHAR) {
        str++;
        cor->label = str;
        (cor->label[0] == '\0') ? my_puterr("Undefined label\n") : 0;
        n = get_lab(cor, T_DIR);
    } else
        n = my_atoi_t(str);
    dest = (char *) &n;
    for (int i = 0; i  < T_DIR; i += 1)
        write(cor->fd, &dest[T_DIR - 1 - i], 1);
    return (cor);
}
