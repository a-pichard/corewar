/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_data
*/

#include "asm.h"
#include "op.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void check_args(char *bin_name, char *fn)
{
    int len_str;

    len_str = my_strlen(fn) - 1;
    if (len_str < 2)
        helper(bin_name, 84);
    if (fn[len_str] != 's' || fn[len_str - 1] != '.')
        helper(bin_name, 84);
    if (get_pathlen(fn) < 1)
        helper(bin_name, 84);
}

static char **my_read(FILE *file)
{
    char *temp = NULL;
    char **data = NULL;
    size_t n = 0;
    int i = 0;

    while (getline(&temp, &n, file) != -1) {
        data = realloc(data, sizeof(char *) * (i + 1));
        if (data == NULL)
            my_puterr("malloc error.\n");
        data[i] = my_strdup(temp);
        i++;
    }
    data = realloc(data, sizeof(char *) * (i + 1));
    if (data == NULL)
        my_puterr("malloc error.\n");
    data[i] = NULL;
    free(temp);
    return (data);
}

char **get_file(char *bin_name, char *fn)
{
    char **data = NULL;
    FILE *file;

    check_args(bin_name, fn);
    if ((file = fopen(fn, "r")) == NULL)
        my_puterr("file doesn't exists.\n");
    data = my_read(file);
    fclose(file);
    return (data);
}

void write_file(char *fn, buf_t *buf)
{
    int fd = open(fn, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    int n = lit_to_big_endian(COREWAR_EXEC_MAGIC);

    if (fd == -1)
        my_puterr("no open\n");
    write(fd, &n, sizeof(n));
    for (int i = 0; i < buf->size; i += 1)
        write(fd, &buf->buf[i], 1);
    free(fn);
    close(fd);
    free(buf->buf);
    free(buf);
}
