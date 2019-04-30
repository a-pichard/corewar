/*
** EPITECH PROJECT, 2019
** type.c
** File description:
** type
*/

#include "asm.h"
#include "op.h"

int is_lab(char *str)
{
    int i;

    for (i = 0; str[i] && str[i] != LABEL_CHAR; i += 1) {
        if (!char_instr(LABEL_CHARS, str[i]))
            return (0);
    }
    if (str[i] == '\0')
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
