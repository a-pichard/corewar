/*
** EPITECH PROJECT, 2019
** comment.c
** File description:
** get comment
*/

#include "asm.h"
#include <stddef.h>
#include <stdlib.h>

static char first_char(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return (str[i]);
        i++;
    }
    return (0);
}

static int get_nb_lines(char **file)
{
    int i = 0;
    int count = 0;

    while (file[i] != NULL) {
        if (first_char(file[i]) != '#')
            count++;
        i++;
    }
    return (count);
}

static int get_len(char *line)
{
    int i = 0;

    while (line[i] != '\0' && line[i] != '#') {
        i++;
    }
    return (i);
}

static char *dupstr(char *line)
{
    int i = 0;
    int len = get_len(line);
    char *newline = malloc(sizeof(char) * (len + 1));

    if (newline == NULL)
        my_puterr("malloc erorr.\n");
    while (i < len) {
        newline[i] = line[i];
        i++;
    }
    newline[i] = '\0';
    return (newline);
}

char **getcomment(char **file)
{
    int nb_lines = get_nb_lines(file);
    char **newfile = malloc(sizeof(char *) * (nb_lines + 1));
    int i = 0;
    int j = 0;

    if (newfile == NULL) {
        my_puterr("malloc error.\n");
    }
    while (i < nb_lines) {
        if (first_char(file[j]) != '#') {
            newfile[i] = dupstr(file[j]);
            i++;
            j++;
        } else {
            j++;
        }
    }
    newfile[i] = NULL;
    destroy_tab(file);
    return (newfile);
}