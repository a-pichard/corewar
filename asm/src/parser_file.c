/*
** EPITECH PROJECT, 2019
** parser_file.C
** File description:
** parser file
*/

#include "op.h"
#include "asm.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

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

int name_file(char **file, int fd, int *i)
{
    char **line = my_str_to_word_tab(file[*i]);
    int n = 0;

    if (my_strcmp(line[0], ".name"))
        my_puterr("need the name first\n");
    if (line[1] == NULL || line[2] != NULL ||
       line[1][0] != '"' || line[1][my_strlen(line[1] - 1)] != '"')
        my_puterr("syntax error\n");
    write(fd, get_quotes(line[1]), my_strlen(line[1]) - 2);
    for (int i = 0; i < (PROG_NAME_LENGTH / 4) - my_strlen(line[1]); i += 1)
        write(fd, &n, sizeof(n));
    *i += 1;
    while (file[*i] != NULL && empty_line(file[*i]))
        *i += 1;
    if (file[*i] == NULL)
        my_puterr("empty file, only name\n");
    return (fd);
}

int comment_file(char **file, int fd, int *i)
{
    char **line = my_str_to_word_tab(file[*i]);
    int n = 0;

    if (my_strcmp(line[0], ".comment"))
        my_puterr("need comment\n");
    if (line[1] == NULL || line[2] != NULL ||
       line[1][0] != '"' || line[1][my_strlen(line[1] - 1)] != '"')
        my_puterr("syntax error\n");
    write(fd, get_quotes(line[1]), my_strlen(line[1]) - 2);
    for (int i = 0; i < (COMMENT_LENGTH / 4) - my_strlen(line[1]); i += 1)
        write(fd, &n, sizeof(n));
    *i += 1;
    while (file[*i] != NULL && empty_line(file[*i]))
        *i += 1;
    if (file[*i] == NULL)
        my_puterr("no program\n");
    return (fd);
}

void parser_file(char **file, char *fn)
{
    int i;
    int fd;
    int n = COREWAR_EXEC_MAGIC;

    fn = my_strcat_bis(fn, ".cor");
    fd = open(fn, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    file = getcomment(file);
    write(fd, &n, sizeof(n));
    for (i = 0; file[i] != NULL && empty_line(file[i]); i += 1);
    if (file[i] == NULL)
        my_puterr("empty file\n");
    fd = name_file(file, fd, &i);
    fd = comment_file(file, fd, &i);
    free(fn);
    close(fd);
}
