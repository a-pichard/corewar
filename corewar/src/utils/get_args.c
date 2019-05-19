/*
** EPITECH PROJECT, 2019
** get arg
** File description:
** get args of instrcution
*/

#include "corewar.h"
#include "stdlib.h"
#include <stdio.h>

int get_number_adress(mem_t *memory, int nbr_case, int *k, int *dest)
{
    int number = 0;

    for (int i = 0; i < nbr_case; i += 1)
        number += memory[(*k + i) % MEM_SIZE] *
            my_pow(256, nbr_case - 1 - i);
    *k += nbr_case;
    *dest += nbr_case;
    return (number);
}

int *get_parameter_args(mem_t *memory, int *utils, int *args, int special)
{
    int i = 1;
    int dest = 1;
    int k = utils[0] + 2;
    char *types = conv_i_str(dec_to_bin(args[0]));

    if (my_strlen(types) != 8)
        return (NULL);
    for (i; i <= utils[1]; i++) {
        if (types[(i - 1) * 2] == '0' && types[(i - 1) * 2 + 1] == '1') {
            args[i] = memory[k++ % MEM_SIZE];
            dest += 1;
        }
        if (types[(i - 1) * 2] == '1' && types[(i - 1) * 2 + 1] == '1')
            args[i] = get_number_adress(memory, IND_SIZE, &k, &dest);
        if (types[(i - 1) * 2] == '1' && types[(i - 1) * 2 + 1] == '0')
            args[i] = (special)?get_number_adress(memory, IND_SIZE, &k, &dest):
                get_number_adress(memory, REG_SIZE, &k, &dest);
    }
    args[i] = dest;
    free(types);
    return (args);
}

int *spe_args(mem_t *memory, int *utils, int *args, int special)
{
    int dest = 0;
    int k = utils[0] + 2;
    char *types = conv_i_str(dec_to_bin(args[0]));

    if (types[0] == '0' && types[1] == '1')
        args[1] = memory[k % MEM_SIZE];
    if (types[0] == '1' && types[1] == '1')
        args[1] = get_number_adress(memory, IND_SIZE, &k, &dest);
    if (types[0] == '1' && types[1] == '0')
        args[1] = (special)?get_number_adress(memory, IND_SIZE, &k, &dest):
            get_number_adress(memory, REG_SIZE, &k, &dest);
    free(types);
    return (args);
}

int *get_args(mem_t *memory, int pc, int nbr_arg, int special)
{
    int *args = xmalloc(sizeof(int) * (nbr_arg + 3));

    args[0] = memory[(pc + 1) % MEM_SIZE];
    if (nbr_arg == 1) {
        if (special == 1) {
            args[0] = 11;
            args = spe_args(memory, (int []) {pc, nbr_arg + 1}, args, special);
            args[0] = args[1];
        } else
            return (args);
    } else
        args = get_parameter_args(memory, (int []){pc, nbr_arg}, args, special);
    return (args);
}
