/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR

# define PROG_NAME_LENGTH 128
# define COMMENT_LENGTH 2048

typedef struct {
    int  magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int  prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct {
    int nb;
    int addr;
    header_t *hd;
    unsigned char *prg;
} prg_t;

typedef struct {
    int dump;
    int nb_prg;
    prg_t **prgs;
} champs_t;

void helper(char *bin_name, int exit_status);

champs_t *get_prgs(int ac, char **av);
prg_t *get_prg(char *path, int nb, int adrr);
void get_input(champs_t *prgs, int ac, char **av);
int get_dump(int ac, char **av);
void destroy_struct(champs_t *prgs);
int is_contain_cor(char *str);

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

#endif