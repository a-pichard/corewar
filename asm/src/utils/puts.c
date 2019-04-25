/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** puts
*/

#include "asm.h"
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void my_puterr(char const *str)
{
    write(2, str, my_strlen(str));
    exit(84);
}