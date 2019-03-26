##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	my_ls.c		\
			l_flag.c	\
			main.c
NAME	=	my_ls
OBJ		=	$(SRC:.c=.o)
MAKE	=	make

all:	$(NAME)

$(NAME):		$(OBJ)
		$(MAKE) -C lib/my
		gcc -o $(NAME) $(SRC) -L./lib/my -lmy -g3
		
clean:
		rm -f lib/my/*.o
		rm -f lib/my/libmy.a
		rm -f *.o
		rm -f my_ls

fclean:	clean
		rm -f $(NAME)

re: fclean all
