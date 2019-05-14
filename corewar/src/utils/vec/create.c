/*
** EPITECH PROJECT, 2019
** create
** File description:
** create
*/

#include "vec.h"
#include "corewar.h"
#include <stddef.h>
#include <stdlib.h>

vec_t *create_vec(void)
{
    vec_t *v = xmalloc(sizeof(vec_t));

    v->content = xmalloc(DELTA_ALLOC * sizeof(void *));
    v->content[0] = NULL;
    v->element = 0;
    v->size = DELTA_ALLOC;
    return (v);
}
