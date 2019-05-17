##
## EPITECH PROJECT, 2019
## CPE_corewar_2018
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/helper.c	\
		src/utils/my_strlen.c	\
		src/utils/puts.c	\
		src/utils/xmalloc.c	\
		src/utils/lit_to_big_endian.c	\
		src/utils/my_strcmp.c	\
		src/utils/is_nb_pos.c	\
		src/utils/my_atoi.c	\
		src/utils/utils_binary.c \
		src/utils/get_args.c \
		src/utils/my_strdup.c	\
		src/get_file/set_addr.c	\
		src/utils/tab_utils.c	\
		src/get_file/get_prg.c	\
		src/get_file/get_prgs.c	\
		src/get_file/get_dump.c	\
		src/get_file/get_input.c	\
		src/get_file/destroy_structs.c \
		src/get_file/set_nb.c	\
		src/mnemonic/add.c \
		src/mnemonic/aff.c \
		src/mnemonic/and.c \
		src/mnemonic/fork.c \
		src/mnemonic/ld.c \
		src/mnemonic/ldi.c \
		src/mnemonic/lfork.c \
		src/mnemonic/live.c \
		src/mnemonic/lld.c \
		src/mnemonic/lldi.c \
		src/mnemonic/or.c \
		src/mnemonic/st.c \
		src/mnemonic/sti.c \
		src/mnemonic/sub.c \
		src/mnemonic/xor.c	\
		src/mnemonic/zjmp.c	\
		src/utils/vec/apply.c	\
		src/utils/vec/create.c   \
		src/utils/vec/destroy.c	\
		src/cor/set_cor.c	\
		src/cor/index.c	\
		src/cor/end.c	\
		src/utils/vec/get.c	\
		src/utils/vec/pop.c	\
		src/utils/vec/push.c	\
		src/utils/vec/set.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iincl ##-W -Wall -Wextra

NAME	=	corewar

all:	$(NAME)

debug:	$(eval CFLAGS	+=	-g) re

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
