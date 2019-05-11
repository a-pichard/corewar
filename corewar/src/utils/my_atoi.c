/*
** EPITECH PROJECT, 2019
** matchstick.c
** File description:
** my_atoi
*/

int my_atoi(char const *str)
{
    int result = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + str[i] - 48;
        i = i + 1;
    }
    return (result);
}