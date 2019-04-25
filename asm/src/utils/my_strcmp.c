/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp
*/

#include "asm.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int a;
    int b;

    while (s1[i] != '\0' && s2[i] != '\0') {
        a = s1[i];
        b = s2[i];
        if (a < b)
            return (-1);
        if (a > b)
            return (1);
        i += 1;
    }
    if (!i || s1[i] != '\0' || s2[i] != '\0')
        return (2);
    return (0);
}
