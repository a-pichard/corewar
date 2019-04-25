##
## EPITECH PROJECT, 2019
## CPE_corewar_2018
## File description:
## Makefile
##

all:
	make -C ./asm/
	make -C ./corewar/

clean:
	make -C ./asm/ clean
	make -C ./corewar/ clean

fclean:
	make -C ./asm/ fclean
	make -C ./corewar/ fclean

re:
	make -C ./asm/ re
	make -C ./corewar re