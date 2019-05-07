/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** helper
*/

#include "corewar.h"
#include <stdlib.h>

void helper(char *bin_name, int exit_status)
{
    my_putstr("USAGE\n\t");
    my_putstr(bin_name);
    my_putstr(" [-dump nbr_cycle] [[-n prog_number] ");
    my_putstr("[-a load_address] prog_name] ...\n\nDESCRIPTION\n");
    my_putstr("\t-dump nbr_cycle dumps the memory after the nbr_cycle");
    my_putstr("execution (if the round isn’t\n");
    my_putstr("\t\t\talready over) with the following format: 32 bytes/");
    my_putstr("line in\n\t\t\thexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("\t-n prog_number\tsets the next program’s number. By default, ");
    my_putstr("the first free number\n\t\t\tin the parameter order\n");
    my_putstr("\t-a load_address\tsets the next program’s loading address.");
    my_putstr(" When no address is\n\t\t\tspecified, optimize the addresses ");
    my_putstr("so that the processes are as far\n\t\t\t");
    my_putstr("away from each other as possible. The addresses are ");
    my_putstr("MEM_SIZE modulo\n");
    exit(exit_status);
}