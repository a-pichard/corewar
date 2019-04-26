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
        if (str[i] != ' ' && str[i] != '\n' && str[i] == '\t')
            return (0);
    }
    return (1);
}

int name_file(char **file, int fd, int *i)
{
    char **line = my_str_to_word_tab(file[*i]);
    int n = 0x;

    if (my_strcmp(line[0], ".name"))
        my_puterr("need the name first\n");
    if (line[1] == NULL || line[2] != NULL)
        my_puterr("syntax error\n");
    write(fd, line[1], my_strlen(line[1]));
    for (int i = 0; i < PROG_NAME_LENGHT - my_strlen(line[1]); i += 1)
        write(fd, &n, sizeof(n);
}

int parser_file(char **file, char *fn)
{
    int i;
    int fd;

    fn = my_strcat_bis(fn, ".cor");
    file = getcomment(file);
    write(fd, COREWAR_EXEC_MAGIC, sizeof(COREWAR_EXEC_MAGIC));
    for (i = 0; file[i] != NULL && empty_line(file[i]); i += 1);
    if (file[i] == NULL)
        my_puterr("empty_file\n");
    fd = name_file(file, fd, &i);
    return (fd);
}
