/*
** EPITECH PROJECT, 2019
** get
** File description:
** get
*/

#include "vec.h"
#include <stddef.h>
#include <stdlib.h>

void *get(vec_t *vec, size_t i)
{
    if (i > vec->element) {
        return (NULL);
    } else {
        return ((vec->content)[i]);
    }
}