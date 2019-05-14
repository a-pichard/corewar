/*
** EPITECH PROJECT, 2019
** destroye
** File description:
** destroye
*/

#include "vec.h"
#include <stddef.h>
#include <stdlib.h>

void destroy_vec(vec_t *vec, void(destroye(void *)))
{
    size_t i = 0;

    if (vec == NULL)
        return;
    if (destroye != NULL) {
        while (i < vec->element) {
            destroye(vec->content[i]);
            i++;
        }
    }
    free(vec->content);
    free(vec);
}
