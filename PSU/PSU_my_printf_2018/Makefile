##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	my_printf.c	\
			main.c
NAME	=	my_printf
OBJ		=	$(SRC:.c=.o)
MAKE	=	make

all:	$(NAME)

$(NAME):		$(OBJ)
		$(MAKE) -C lib/my
		gcc -o $(NAME) $(SRC) -L./lib/my -lmy

clean:
		rm -f lib/my/*.o
		rm -f *.o
		rm -f my_printf
		rm -f lib/my/libmy.a

fclean:	clean
		rm -f $(NAME)

re: fclean all