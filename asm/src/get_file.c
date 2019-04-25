/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_data
*/

#include "asm.h"
#include <stdio.h>
#include <stdlib.h>

void check_args(int ac, char **av)
{
    int len_str;

    if (ac != 2)
        helper(av[0], 84);
    if (!my_strcmp(av[1], "-h"))
        helper(av[0], 0);
    len_str = my_strlen(av[1]) - 1;
    if (len_str < 2)
        helper(av[0], 84);
    if (av[1][len_str] != 's' || av[1][len_str - 1] != '.')
        helper(av[0], 84);
}

char **my_read(FILE *file)
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

char **get_file(int ac, char **av)
{
    char **data = NULL;
    FILE *file;

    check_args(ac, av);
    if ((file = fopen(av[1], "r")) == NULL)
        my_puterr("file doesn't exists.\n");
    data = my_read(file);
    fclose(file);
    return (data);
}
