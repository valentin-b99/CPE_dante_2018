##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 of CPool Day10
##

SRC		=		main.c			\
				get_map.c

OBJ		=		$(SRC:.c=.o)

NAME	=		solver

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
