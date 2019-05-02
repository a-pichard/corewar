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

int pars_dir(char *str, int fd, int index)
{
    char *dest = malloc(sizeof(char) * ((index) ? 3 : 5));
    int n = 0;   //temp

    (dest == NULL) ? my_puterr("malloc err\n") : 0;
    str++;
    if (*str != LABEL_CHAR)
        n = (index) ? my_atoi_t(str) : lit_to_big_endian(my_atoi_t(str));
    dest = (char *) &n;    //pars_label
    if (index) {
        write(fd, &dest[1], 1);
        write(fd, &dest[0], 1);
    } else
        write(fd, dest, 4);
    return (fd);
}

int pars_ind(char *str, int fd)
{
    char *dest = malloc(sizeof(char) * 3);
    int n = 0;    //temp

    (dest == NULL) ? my_puterr("malloc err\n") : 0;
    if (*str != LABEL_CHAR)
        n = my_atoi_t(str);
    dest = (char *) &n;    //pars_label
    write(fd, &dest[1], 1);
    write(fd, &dest[0], 1);
    return (fd);
}
