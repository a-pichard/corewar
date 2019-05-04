/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

typedef struct file_s
{
    int fd;
    char **file;
    int start;
    int pos;
    char *label;
} file_t;

int my_strcmp_lab(char const *s1, char const *s2);
file_t *pars_ind(char *str, file_t *cor);
file_t *pars_dir(char *str, file_t *cor, int index);
int pars_reg(char *str, int fd);
int is_lab(char *str);
int is_reg(char *str);
int is_dir(char *str);
int is_ind(char *str);
int type(char *str);
int my_atoi(char *str);
int my_strlen(char const *);
void my_puterr(char const *str);
void my_putstr(char const *str);
void my_putchar(char c);
char *my_strdup(char *str);
char *my_strcat_bis(char *s1, char *s2);
void destroy_tab(char **tab);
void print_tab(char **tab);
int my_strcmp(char const *s1, char const *s2);
int lit_to_big_endian(int x);
int operator(char **str, int n, char **file, int *j);
int bin_to_dec(long n, int oct);
int pars_label(int i, char **file);
int my_atoi_t(char *str);
int destroy_array(char **tab, int ret);
int *destroy_array_t(char **tab, int *ret);

void helper(char *prg_name, int exit_status);

int char_instr(char *str, char c);
char **getcomment(char **file);
char **get_file(char *bin_name, char *fn);
char *get_filename(char *path);
char **my_str_to_word_tab(char *str);
int get_pathlen(char *path);
char **parser_file(char **file, char *fn);
char *get_quotes(char *str, int n);
int empty_line(char *str);
char **getcomment(char **file);
int len_bin(char **file, int i, int end);
int prog(char **file, int i, int fd);
long get_lab(file_t *cor, int n);
void check_label(char **file, int i);

#endif
