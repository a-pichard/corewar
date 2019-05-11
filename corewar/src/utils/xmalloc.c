/*
** EPITECH PROJECT, 2019
** test
** File description:
** xmalloc
*/

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

void *xmalloc(int size)
{
    void *ptr = malloc(size);
    char err_msg[] = "xmalloc failed !\n";

    if (ptr == NULL) {
        write(2, err_msg, my_strlen(err_msg));
        exit(84);
    }
    return (ptr);
}