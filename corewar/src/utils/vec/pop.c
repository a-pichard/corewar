/*
** EPITECH PROJECT, 2019
** pop
** File description:
** pop
*/

#include "vec.h"
#include <stddef.h>
#include <stdlib.h>

void pop(vec_t *vec, size_t i, void(destroye(void *)))
{
    size_t j = i;

    if (i > vec->element) {
        return;
    }
    if (destroye != NULL) {
        destroye((vec->content)[j]);
    }
    while (j < vec->element - 1) {
        vec->content[j] = vec->content[j + 1];
        j++;
    }
    vec->element = vec->element - 1;
    vec->content[vec->element] = NULL;
}
