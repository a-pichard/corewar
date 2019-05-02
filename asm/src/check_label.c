/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** check_label
*/

#include "asm.h"
#include <stdlib.h>

static char **check_lab(char *arg, char **list, int *j)
{
    if (is_lab(arg) == 1) {
        list = realloc(list, sizeof(char *) * ((*j) + 1));
        list[(*j)] = my_strdup(arg);
        (*j)++;
    }
    return (list);
}

static char **get_labels(char **file, int i)
{
    char **tmp = NULL;
    char **list = NULL;
    int j = 0;

    while (file[i] != NULL) {
        tmp = my_str_to_word_tab(file[i]);
        if (tmp == NULL || tmp[0] == NULL) {
            destroy_tab(tmp);
            i++;
            continue;
        }
        list = check_lab(tmp[0], list, &j);
        destroy_tab(tmp);
        tmp = NULL;
        i++;
    }
    if (list != NULL) {
        list = realloc(list, sizeof(char *) * (j + 1));
        list[j] = NULL;
    }
    return (list);
}

static int checker(char **file, int i, int j)
{
    if (i == j)
        return (0);
    if (!my_strcmp(file[i], file[j]))
        return (1);
    return (0);
}

static int extreme_checker_exe(char **labels)
{
    int i = 0;
    int j = 0;
    int ret = 0;

    while (labels[i] != NULL) {
        j = 0;
        while (labels[j] != NULL) {
            ret += checker(labels, i, j);
            j++;
        }
        i++;
    }
    if (!ret)
        return (0);
    return (1);
}

void check_label(char **file, int i)
{
    char **labels = get_labels(file, i);
    int ret = extreme_checker_exe(labels);

    destroy_tab(labels);
    if (ret)
        my_puterr("Labels must be unique.\n");
}