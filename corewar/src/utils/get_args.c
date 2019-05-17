/*
** EPITECH PROJECT, 2019
** get arg
** File description:
** get args of instrcution
*/

#include "corewar.h"

int get_number_adress(mem_t *memory, int nbr_case, int *k, int pc)
{
    int number = 0;
    int actual = 0;
    int power = nbr_case - 1;

    for (power; power != 0; power--, (*k)++) {
        actual = memory[(pc + (*k + 1)) % MEM_SIZE];
        number += actual * power_bytes(256, power);
    }
    return (number);
}

int *get_parameter_args(mem_t *memory, int pc, int *args, int nbr_arg)
{
    int i = 1;
    int j = 0;
    int k = 2;
    char type[2];
    char *types = conv_i_str(dec_to_bin(args[0]));

    for (i; i < nbr_arg; i++) {
        type[0] = types[j];
        type[1] = types[j + 1];
        if (type[0] == '0' && type[1] == '1')
            args[i] = memory[(pc + k++) % MEM_SIZE];
        if (type[0] == '1' && type[1] == '1')
            args[i] = get_number_adresse(memory, 2, &k, pc);
        if (type[0] == '1' && type[1] == '0')
            args[i] = get_number_adresse(memory, 4, &k, pc);
        j += 2;
    }
    free(types);
    return (args);
}

int *get_args(mem_t *memory, int pc, int nbr_arg, int special)
{
    int *args = xmalloc(sizeof(int) * (nbr_arg + 1));

    args[0] = memory[(pc + 1) % MEM_SIZE];
    if (nbr_arg == 1) {
        if (special == 1) {
            args[0] = 11;
            args = get_parameter_args(memory, pc, args, nbr_arg + 1);
            args[0] = args[1];
        } else
            return (args);
    } else
        args = get_parameter_args(memory, pc, args, nbr_arg);
    return (args);
}