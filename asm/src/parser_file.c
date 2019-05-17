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

buf_t *add_buf(buf_t *buf, char *str, int fr)
{
    (!fr) ? buf->buf = NULL : 0;
    buf->buf = my_realloc(buf->buf, str, fr);
    buf->size += my_strlen(str);
    return (buf);
}

void name_file(char **file, buf_t **buf, int *i)
{
    char **line = my_str_to_word_tab(file[*i]);
    char n = 0;

    if (my_strcmp(line[0], NAME_CMD_STRING))
        my_puterr("need the name first\n");
    if (line[1] == NULL || line[2] != NULL ||
        line[1][0] != '"' || line[1][my_strlen(line[1]) - 1] != '"')
        my_puterr("syntax error\n");
    *buf = add_buf(*buf, get_quotes(line[1], PROG_NAME_LENGTH), 0);
    for (int i = 0; i < PROG_NAME_LENGTH - my_strlen(line[1]) + 4; i += 1)
        *buf = add_char_buf(*buf, n, 1);
    *i += 1;
    while (file[*i] != NULL && empty_line(file[*i]))
        *i += 1;
    destroy_tab(line);
}

buf_t *no_comment(char **line, buf_t *buf, int *i, char **file)
{
    char n = 0;
    int mem;
    char *nb = NULL;

    mem = lit_to_big_endian(len_bin(file, *i, -1));
    nb = (char *) &mem;
    buf = add_size_buf(buf, nb, 1, 4);
    if (line != NULL)
        buf = add_buf(buf, get_quotes(line[1], COMMENT_LENGTH), 1);
    for (int i = 0; i < COMMENT_LENGTH + 4; i += 1)
        buf = add_char_buf(buf, n, 1);
    return (destroy_array_buf(line, buf));
}

buf_t *comment_file(char **file, buf_t *buf, int *i)
{
    char **line = my_str_to_word_tab(file[*i]);
    char n = 0;
    char *nb = NULL;
    int mem;

    if (file[*i] == NULL || my_strcmp(line[0], COMMENT_CMD_STRING))
        return (no_comment(line, buf, i, file));
    if (line[1] == NULL || line[2] != NULL ||
        line[1][0] != '"' || line[1][my_strlen(line[1]) - 1] != '"')
        my_puterr("syntax error\n");
    *i += 1;
    mem = lit_to_big_endian(len_bin(file, *i, -1));
    nb = (char *) &mem;
    buf = add_size_buf(buf, nb, 1, 4);
    buf = add_buf(buf, get_quotes(line[1], COMMENT_LENGTH), 1);
    for (int i = 0; i < COMMENT_LENGTH + 4 - my_strlen(line[1]); i += 1)
        buf = add_char_buf(buf, n, 1);
    while (file[*i] != NULL && empty_line(file[*i]))
        *i += 1;
    return (destroy_array_buf(line, buf));
}

char **parser_file(char **file, char *fn)
{
    int i;
    buf_t *buf = malloc(sizeof(buf_t));
    file_t *cor;

    buf->size = 0;
    fn = my_strcat_bis(fn, ".cor");
    file = getcomment(file);
    for (i = 0; file[i] != NULL && empty_line(file[i]); i += 1);
    if (file[i] == NULL)
        my_puterr("empty file\n");
    name_file(file, &buf, &i);
    buf = comment_file(file, buf, &i);
    (file[i] != NULL) ? check_label(file, i) : 0;
    if (file[i] != NULL) {
        cor = prog(file, i, buf);
        write_file(fn, cor->buf);
        free(cor);
    } else
        write_file(fn, buf);
    return (file);
}
