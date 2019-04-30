/*
** EPITECH PROJECT, 2019
** my_atoi.c
** File description:
** my_atoi
*/

#include "asm.h"

long my_strtol(char *str, char **end)
{
    char *current = str;
    long n = 0;
    long signe = 0;

    if (*current == '-') {
        signe = 1;
        current = current + 1;
    }
    while (*current >= '0' && *current <= '9') {
        n = n * 10 + (*current - '0');
        current = current + 1;
    }
    *end = current;
    if (signe) {
        n = -n;
    }
    return (n);
}

int my_atoi(char *str)
{
    char *end;
    long a = my_strtol(str, &end);

    if (*end != '\0' || a <= 0)
        my_puterr("Invalid instruction\n");
    return ((int) a);
}
