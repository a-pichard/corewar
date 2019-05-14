/*
** EPITECH PROJECT, 2019
** push
** File description:
** push
*/

#include "vec.h"
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"

void push(vec_t *vec, void *data)
{
    void **temp;
    size_t i = 0;

    if (vec->element + 1 < vec->size) {
        (vec->content)[vec->element] = data;
        vec->element = vec->element + 1;
        vec->content[vec->element] = NULL;
    } else {
        temp = xmalloc(sizeof(void *) * (vec->size + DELTA_ALLOC));
        while (i < vec->size) {
            temp[i] = (vec->content)[i];
            i++;
        }
        free(vec->content);
        vec->content = temp;
        vec->size += DELTA_ALLOC;
        push(vec, data);
    }
}
