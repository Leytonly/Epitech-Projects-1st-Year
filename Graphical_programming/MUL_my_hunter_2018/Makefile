##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	my_hunter.c				\
			manage_gameobjects.c	\
			main.c
NAME	=	my_hunter
OBJ		=	$(SRC:.c=.o)
MAKE	=	make

all:	$(NAME)

$(NAME):		$(OBJ)
		$(MAKE) -C lib/my
		gcc -o $(NAME) $(SRC) -L./lib/my -lmy -lcsfml-window -lcsfml-graphics -lcsfml-system

clean:
		rm -f lib/my/*.o
		rm -f *.o
		rm -f my_hunter
		rm -f lib/my/libmy.a

fclean:	clean
		rm -f $(NAME)

re: fclean all