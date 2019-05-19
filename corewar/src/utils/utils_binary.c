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

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char memo[2] = {0};

    while (str[i] != '\0')
        i += 1;
    while (j < i / 2) {
        memo[0] = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = memo[0];
        j += 1;
    }
    return (str);
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
    result = my_revstr(result);
    if (my_strlen(result) <= 7)
        result = my_realloc("0", result);
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
