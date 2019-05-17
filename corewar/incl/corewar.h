/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR

#include "op.h"
#include "vec.h"
#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048

#define FUNCTION_INS {live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, \
            f_fork, lld, lldi, f_lfork, aff, NULL};

typedef unsigned char mem_t;

typedef struct {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct {
    int live;
    int nb;
    int addr;
    int p_addr;
    int carry;
    header_t *hd;
    unsigned char *prg;
} champ_t;

typedef struct {
    int dump;
    int nb_prg;
    mem_t memory[MEM_SIZE + 1];
    champ_t **prgs;
} corewar_t;

typedef struct {
    int chmp;
    int pc;
    int sleep;
    mem_t reg[REG_NUMBER + 1];
} process_t;

void helper(char *bin_name, int exit_status);

corewar_t *get_prgs(int ac, char **av);
champ_t *get_prg(char *path, int nb, int adrr);
void get_input(corewar_t *prgs, int ac, char **av);
int get_dump(int ac, char **av);
void destroy_struct(corewar_t *prgs);
int is_contain_cor(char *str);
corewar_t *set_nb_prog(corewar_t *champ);
corewar_t *set_addr(corewar_t *prgs);

char *my_realloc(char *str, char *src);
int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
void my_puterr(char const *str);
void *xmalloc(int size);
int lit_to_big_endian(int x);
int my_strcmp(char *s1, char *s2);
int is_nb_pos(char *str);
int my_atoi(char const *str);
void my_putnbr(int n);
char *my_strdup(char *str);
void destroy_tab(char **tab);
int get_tab_len(char **tab);
int dec_to_bin(int nub);
char *conv_i_str(int nbr);
int power_bytes(int nbr, int expo);

int set_cor(corewar_t *cor);
vec_t *sort_process(vec_t *proc, corewar_t *cor);
int index_of_int(mem_t mem, int *ins);
int *get_args(mem_t *memory, int pc, int nbr_arg);
void is_end(corewar_t *cor);
void end_dump(corewar_t *cor);

void live(corewar_t *cor, vec_t *proc, int n);
void ld(corewar_t *cor, vec_t *proc, int n);
void st(corewar_t *cor, vec_t *proc, int n);
void add(corewar_t *cor, vec_t *proc, int n);
void sub(corewar_t *cor, vec_t *proc, int n);
void and(corewar_t *cor, vec_t *proc, int n);
void or(corewar_t *cor, vec_t *proc, int n);
void xor(corewar_t *cor, vec_t *proc, int n);
void zjmp(corewar_t *cor, vec_t *proc, int n);
void ldi(corewar_t *cor, vec_t *proc, int n);
void sti(corewar_t *cor, vec_t *proc, int n);
void f_fork(corewar_t *cor, vec_t *proc, int n);
void lld(corewar_t *cor, vec_t *proc, int n);
void lldi(corewar_t *cor, vec_t *proc, int n);
void f_lfork(corewar_t *cor, vec_t *proc, int n);
void aff(corewar_t *cor, vec_t *proc, int n);
#endif
