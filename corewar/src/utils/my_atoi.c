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

int my_pow(int n, int p)
{
    int dest = n;

    if (p == 0)
        return (1);
    for (int i = 1; i < p; i += 1)
        dest = dest * n;
    return (dest);
}
