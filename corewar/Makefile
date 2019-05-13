##
## EPITECH PROJECT, 2019
## CPE_corewar_2018
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/helper.c	\
		src/utils/my_strlen.c	\
		src/set_nb.c	\
		src/utils/puts.c	\
		src/utils/xmalloc.c	\
		src/utils/lit_to_big_endian.c	\
		src/utils/my_strcmp.c	\
		src/utils/is_nb_pos.c	\
		src/utils/my_atoi.c	\
		src/utils/my_strdup.c	\
		src/utils/tab_utils.c	\
		src/get_file/get_prg.c	\
		src/get_file/get_prgs.c	\
		src/get_file/get_dump.c	\
		src/get_file/get_input.c	\
		src/get_file/destroy_structs.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iincl -W -Wall -Wextra

NAME	=	corewar

all:	$(NAME)

val:	debug $(NAME)

debug:
	$(eval CFLAGS	+=	-g)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
