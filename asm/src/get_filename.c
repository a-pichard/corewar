/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_filename
*/

#include "asm.h"
#include <stdlib.h>

int get_pathlen(char *path)
{
    int len = my_strlen(path);
    int i = 0;

    while (len > 0 && path[len] != '/') {
        len--;
        i++;
    }
    if (path[len] == '/') {
        i--;
    }
    return (i - 2);
}

static int get_index(char *path)
{
    int pathlen = get_pathlen(path) + 2;
    int len = my_strlen(path);

    return (len - pathlen);
}

char *get_filename(char *path)
{
    int index = get_index(path);
    int len = get_pathlen(path);
    char *filename = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (filename == NULL)
        my_puterr("malloc error.\n");
    while (i != len) {
        filename[i] = path[index];
        i++;
        index++;
    }
    filename[i] = '\0';
    return (filename);
}