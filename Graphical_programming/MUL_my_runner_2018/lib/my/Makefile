##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	$(wildcard *.c)
OBJ		=	$(SRC:.c=.o)
NAME	=	libmy.a
HEAD	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all