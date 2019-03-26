##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	my_runner.c		\
			main.c			\
			parallax.c		\
			sprites.c		\
			rect.c			\
			events.c
NAME	=	my_runner
OBJ		=	$(SRC:.c=.o)
MAKE	=	make

all:	$(NAME)

$(NAME):		$(OBJ)
		$(MAKE) -C lib/my
		gcc -o $(NAME) $(SRC) -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

clean:
		rm -f lib/my/*.o
		rm -f *.o
		rm -f my_runner
		rm -f lib/my/libmy.a

fclean:	clean
		rm -f $(NAME)

re: fclean all