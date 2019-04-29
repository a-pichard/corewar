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

char *name_file(char **file, int *fd, int *i)
{
    char **line = my_str_to_word_tab(file[*i]);
    char n = 0;
    int nb = lit_to_big_endian(42);

    if (my_strcmp(line[0], ".name"))
        my_puterr("need the name first\n");
    if (line[1] == NULL || line[2] != NULL ||
       line[1][0] != '"' || line[1][my_strlen(line[1] - 1)] != '"')
        my_puterr("syntax error\n");
    write(*fd, get_quotes(line[1]), my_strlen(line[1]) - 2);
    for (int i = 0; i < PROG_NAME_LENGTH; i += 1)
        write(*fd, &n, sizeof(n));
    *i += 1;
    write(*fd, &nb, sizeof(nb));
    while (file[*i] != NULL && empty_line(file[*i]))
        *i += 1;
    if (file[*i] == NULL)
        my_puterr("empty file, only name\n");
    return (get_quotes(line[1]));
}

int comment_file(char **file, int fd, int *i, char *name)
{
    char **line = my_str_to_word_tab(file[*i]);
    char n = 0;

    if (my_strcmp(line[0], ".comment"))
        my_puterr("need comment\n");
    if (line[1] == NULL || line[2] != NULL ||
       line[1][0] != '"' || line[1][my_strlen(line[1] - 1)] != '"')
        my_puterr("syntax error\n");
    write(fd, get_quotes(line[1]), my_strlen(line[1]) - 2);
    for (int i = 0; i < COMMENT_LENGTH - (8 + my_strlen(name) +
            my_strlen(line[1]) - 2) % 16; i += 1)
        write(fd, &n, sizeof(n));
    *i += 1;
    while (file[*i] != NULL && empty_line(file[*i]))
        *i += 1;
    return (fd);
}

void parser_file(char **file, char *fn)
{
    int i;
    int fd;
    int n = lit_to_big_endian(COREWAR_EXEC_MAGIC);

    fn = my_strcat_bis(fn, ".cor");
    fd = open(fn, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    file = getcomment(file);
    write(fd, &n, sizeof(n));
    for (i = 0; file[i] != NULL && empty_line(file[i]); i += 1);
    if (file[i] == NULL)
        my_puterr("empty file\n");
    fd = comment_file(file, fd, &i, name_file(file, &fd, &i));
    //if (file[*i] != NULL)
        //do
    free(fn);
    close(fd);
}
