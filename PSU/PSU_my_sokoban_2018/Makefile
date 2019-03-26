##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	movement.c		\
			my_sokoban.c	\
			map_checking.c	\
			map_checking_player.c
NAME	=	my_sokoban
OBJ		=	$(SRC:.c=.o)
MAKE	=	make

all:	$(NAME)

$(NAME):		$(OBJ)
		$(MAKE) -C lib/my
		gcc -o $(NAME) $(SRC) -L./lib/my -lmy -lncurses
		
clean:
		rm -f lib/my/*.o
		rm -f lib/my/libmy.a
		rm -f *.o
		rm -f my_sokoban

fclean:	clean
		rm -f $(NAME)

re: fclean all
