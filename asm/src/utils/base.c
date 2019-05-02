/*
** EPITECH PROJECT, 2019
** base.c
** File description:
** my_base
*/

#include "asm.h"

long deci_to_base(long i, int base)
{
    long dest = 0;
    int j = 1;

    while (i != 0) {
        dest += (i % base) * j;
        i = i / base;
        j = j * 10;
    }
    return (dest);
}


int bin_to_dec(long n, int oct)
{
    int dest = 0;
    long temp = (oct) ? deci_to_base(n, 8) : n;
    int base = 1;
    int last_digit;

    while (temp) {
        last_digit = temp % 10;
        temp = temp / 10;
        dest += last_digit * base;
        base = base * 2;
    }
    return (dest);
}
