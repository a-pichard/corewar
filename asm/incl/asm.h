/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

int my_strlen(char const *);
void my_puterr(char const *str);
void my_putstr(char const *str);
void my_putchar(char c);
char **get_file(int ac, char **av);
char *my_strdup(char *str);
void destroy_tab(char **tab);
void print_tab(char **tab);

#endif