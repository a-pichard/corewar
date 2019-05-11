/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** lit_to_big_endian
*/

int lit_to_big_endian(int x)
{
    unsigned int n = 1;
    char *mem = (char *) &n;

    if (mem[0] != 1)
        return (x);
    return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff00) |
            ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));
}
