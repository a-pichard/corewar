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
    int index;
    int live;
    int nb;
    int addr;
    int p_addr;
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

int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
void my_puterr(char const *str);
void *xmalloc(int size);
int lit_to_big_endian(int x);
int my_strcmp(char *s1, char *s2);
int is_nb_pos(char *str);
int my_atoi(char const *str);
char *my_strdup(char *str);
void destroy_tab(char **tab);
int get_tab_len(char **tab);

void live(corewar_t *cor, vec_t *proc);
void ld(corewar_t *cor, vec_t *proc);
void st(corewar_t *cor, vec_t *proc);
void add(corewar_t *cor, vec_t *proc);
void sub(corewar_t *cor, vec_t *proc);
void and(corewar_t *cor, vec_t *proc);
void or(corewar_t *cor, vec_t *proc);
void xor(corewar_t *cor, vec_t *proc);
void zjmp(corewar_t *cor, vec_t *proc);
void ldi(corewar_t *cor, vec_t *proc);
void sti(corewar_t *cor, vec_t *proc);
void f_fork(corewar_t *cor, vec_t *proc);
void lld(corewar_t *cor, vec_t *proc);
void lldi(corewar_t *cor, vec_t *proc);
void f_lfork(corewar_t *cor, vec_t *proc);
void aff(corewar_t *cor, vec_t *proc);
#endif
