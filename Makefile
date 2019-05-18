##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 of CPool Day10
##

all:	
		@echo -e "\x1B[1;33m" "Welcome to Dante Project !\n" "\x1B[1;0m"
		@echo -e "\x1B[1;34m" "Compiling my lib" "\x1B[1;0m"
		(cd ./lib/my/ && make -s)
		@echo -e "\x1B[1;34m" "\n Compiling generator" "\x1B[1;0m"
		(cd ./generator/ && make -s)
		@echo -e "\x1B[1;34m" "\n Compiling solver" "\x1B[1;0m"
		(cd ./solver/ && make -s)
		@echo -e "\x1B[1;32m" "\n Compilation terminated" "\x1B[1;0m"

wl:	
		@echo -e "\x1B[1;33m" "Welcome to Dante Project !\n" "\x1B[1;0m"
		@echo -e "\x1B[1;31m" "You choosed no lib compiling" "\x1B[1;0m"
		@echo -e "\x1B[1;34m" "\n Compiling generator" "\x1B[1;0m"
		(cd ./generator/ && make -s)
		@echo -e "\x1B[1;34m" "\n Compiling solver" "\x1B[1;0m"
		(cd ./solver/ && make -s)
		@echo -e "\x1B[1;32m" "\n Compilation terminated" "\x1B[1;0m"

fclean: 
		@echo -e "\x1B[1;31m" "Cleaning...\n" "\x1B[1;0m"
		rm -f lib/my/libmy.a
		(cd ./generator/ && make fclean)
		(cd ./solver/ && make fclean)

re:		fclean all

auteur:
		echo LuCas > Auteur
