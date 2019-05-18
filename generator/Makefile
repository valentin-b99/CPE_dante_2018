##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 of CPool Day10
##

SRC		=		main.c				\
				errors_management.c	\
				init_map.c			\
				ways.c				\
				create_rand_ways.c

OBJ		=		$(SRC:.c=.o)

NAME	=		generator

all:	$(NAME) clean

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -g3 -L../lib/my/. -lmy

clean:
		@rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

auteur:
		echo LuCas > Auteur
