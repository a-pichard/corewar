##
## EPITECH PROJECT, 2019
## CPE_corewar_2018
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/utils/my_strcmp.c \
		src/helper.c	\
		src/utils/lit_to_big_endian.c \
		src/utils/my_atoi.c \
		src/utils/operator.c \
		src/utils/split.c \
		src/len_bin.c \
		src/utils/type.c \
		src/get_file.c	\
		src/comment.c \
		src/get_filename.c	\
		src/parser_file.c	\
		src/utils/my_strlen.c	\
		src/utils/puts.c	\
		src/utils/my_strdup.c	\
		src/utils/tab_utils.c	\
		src/utils/my_strcat.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iincl -W -Wall -Wextra

NAME	=	asm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
