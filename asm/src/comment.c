/*
** EPITECH PROJECT, 2019
** comment.c
** File description:
** get comment
*/

#include "op.h"
#include "asm.h"
#include <stdlib.h>
#include <unistd.h>

char **my_comment(char *str, int i, char **file, int k)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 2));
    int j;

    for (j = 0; j < i; j += 1)
        dest[j] = str[j];
    while (j && dest[j - 1] == ' ')
        j -= 1;
    (str[my_strlen(str) - 1] == '\n') ? dest[j] = '\n' : 0;
    (str[my_strlen(str) - 1] == '\n') ? j += 1 : 0;
    for (int k = j; str[k - 1] != '\0'; k += 1)
        dest[k] = '\0';
    file[k] = dest;
    return (file);
}

char **getcomment(char **file)
{
    int k;

    for (k = 0; file[k] != NULL; k += 1);
    for (int i = k - 1; i > -1; i -= 1) {
        for (int j = 0; file[i][j]; j += 1)
            (file[i][j] == COMMENT_CHAR) ?
            file = my_comment(file[i], j, file, i) : 0;
    }
    return (file);
}

int empty_line(char *str)
{
    for (int i = 0; str[i]; i += 1) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
            return (0);
    }
    return (1);
}

char *get_quotes(char *str)
{
    char *dest = malloc(sizeof(char) * my_strlen(str));
    int k = 0;

    for (int i = 1; str[i + 1]; i += 1) {
        dest[k] = str[i];
        k += 1;
    }
    dest[k] = '\0';
    return (dest);
}
