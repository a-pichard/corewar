/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** helper
*/

#include "asm.h"
#include <stdlib.h>

void helper(char *prg_name, int exit_status)
{
    my_putstr("USAGE:\n\t\t");
    my_putstr(prg_name);
    my_putstr(" file_name[.s]\n\n");
    my_putstr("DESCRIPTION\n\t\t");
    my_putstr("file_name\tfile in assembly language to be converted into file");
    my_putstr("_name.cor, an\n\t\t\t\texecutable in the Virtual Machine.\n");
    exit(exit_status);
}
