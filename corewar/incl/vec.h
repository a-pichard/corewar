/*
** EPITECH PROJECT, 2019
** vec
** File description:
** vec
*/

#ifndef VEC_H_
#define VEC_H_
#define DELTA_ALLOC 2
#include <stddef.h>

typedef struct vec_s
{
    size_t size;
    size_t element;
    void **content;
} vec_t;

void push(vec_t *vec, void *data);
void pop(vec_t *vec, size_t i, void(destroye(void *)));
void *get(vec_t *vec, size_t i);
void destroy_vec(vec_t *vec, void(destroye(void *)));
void apply_on_vec(vec_t *vec, void(function(void *)));
vec_t *create_vec(void);

#endif /* !VEC_H_ */
