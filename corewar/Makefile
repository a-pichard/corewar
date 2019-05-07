##
## EPITECH PROJECT, 2019
## CPE_corewar_2018
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/helper.c	\
		src/utils/my_strlen.c	\
		src/utils/puts.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iincl -W -Wall -Wextra

NAME	=	corewar

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
