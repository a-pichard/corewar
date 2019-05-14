/*
** EPITECH PROJECT, 2019
** apply
** File description:
** apply
*/

#include "vec.h"
#include <stddef.h>
#include <stdlib.h>

void apply_on_vec(vec_t *vec, void(function(void *)))
{
    size_t i = 0;

    while (i < vec->element) {
        function(vec->content[i]);
        i++;
    }
}
