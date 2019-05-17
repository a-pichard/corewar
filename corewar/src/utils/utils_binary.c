/*
** EPITECH PROJECT, 2019
** hex_to_binary
** File description:
** hex_to_binary
*/

#include "corewar.h"
#include <stdlib.h>

int power_bytes(int nbr, int expo)
{
    int number = nbr;

    if (expo == 0)
        return (1);
    for (int i = 0; i < expo - 1; i++) {
        if (i == 0)
            number *= nbr;
        else
            number = nbr * number;
    }
    return (number);
}

char *conv_i_str(int nbr)
{
    char *result = malloc(sizeof(char) * (11 + 1));
    int i = 0;

    if (nbr > 0) {
        while (nbr != 0) {
            result[i++] = nbr % 10 + '0';
            nbr /= 10;
        }
    } else
        result[i++] = '0';
    result[i] = '\0';
    return (result);
}

int dec_to_bin(int nub)
{
    int index[] = {512, 256, 128, 64, 32, 16, 8, 4, 2, 1, 0};
    int number = 0;
    int pass = 0;

    for (int i = 0; index[i] != 0; i++) {
        if (nub >= index[i]) {
            pass = 1;
            nub = nub - index[i];
        }
        number = number * 10 + pass;
        pass = 0;
    }
    return (number);
}
