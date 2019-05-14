/*
** EPITECH PROJECT, 2019
** set
** File description:
** set
*/

#include "vec.h"
#include <stddef.h>
#include <stdlib.h>

void set(vec_t *vec, size_t i, void *data)
{
    if (i > vec->element) {
        return;
    } else {
        (vec->content)[i] = data;
    }
}