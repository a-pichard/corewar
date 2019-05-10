/*
** EPITECH PROJECT, 2019
** split.c
** File description:
** str to word tab
*/

#include "asm.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

int separator(char c, int *quotes)
{
    if (quotes != NULL && *quotes)
        return (0);
    if (c == ' ' || c == '\t' || c == SEPARATOR_CHAR)
        return (1);
    return (0);
}

char **putstr_array(char **table, char *buf)
{
    int m;
    int n = 0;
    char *str;
    int q = 0;

    for (int k = 0; buf[k] != '\0'; k += 1) {
        (str = malloc(sizeof(char) * (1 + my_strlen(buf)))) == NULL?exit(84):0;
        m = 0;
        while (buf[k] != '\0' && buf[k] != '\n' && !separator(buf[k], &q)) {
            (q && buf[k] == '"') ? q = 0 : 0;
            (!q && !m && buf[k] == '"') ? q = 1 : 0;
            str[m++] = buf[k++];
        }
        m?str[m] = '\0':(free(str));
        m?table[n++] = str:0;
        if (buf[k] == '\0')
            break;
    }
    table[n] = NULL;
    return (table);
}

char **my_str_to_word_tab(char *str)
{
    int j = 0;
    char **table;

    for (int i = 0; str[i] != '\0'; i += 1)
        (!i && !separator(str[i], NULL)) || (i && separator(str[i - 1], NULL) &&
        !separator(str[i], NULL)) ? j += 1 : 0;
    (table = malloc(sizeof(char *) * (j + 1))) == NULL ? exit(84) : 0;
    return (putstr_array(table, str));
}

char *my_revstr(char *str, int size)
{
    int i = 0;
    int j = 0;
    char memo[2] = {0};

    while (i != size)
        i += 1;
    while (j < i / 2) {
        memo[0] = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = memo[0];
        j += 1;
    }
    return (str);
}

int octet_size(int n, int j)
{
    for (int i = 0; i < j; i += 1) {
        n = n / 256;
    }
    return (n % 256);
}
