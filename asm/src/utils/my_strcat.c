/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** my_strcat
*/

#include "asm.h"
#include <stdlib.h>

char *my_strcat_bis(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int i = 0;
    int j = 0;
    char *newstr = malloc(sizeof(char) * (len1 + len2 + 1));

    if (newstr == NULL)
        my_puterr("malloc error.\n");
    while (s1[i] != '\0') {
        newstr[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0') {
        newstr[i] = s2[j];
        i++;
        j++;
    }
    newstr[i] = '\0';
    free(s1);
    return (newstr);
}