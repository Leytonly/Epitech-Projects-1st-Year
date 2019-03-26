##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =	matchstick.c 		\
		print_firstmap.c	\
		player_turn.c		\
		error_gestion.c		\
		ai_turn.c			\
		main.c				\

OBJ = $(SRC:.c=.o)

NAME = matchstick

CFLAGS += -W -Wall -Wextra -pedantic -I./include

LFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME):		$(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)
		
clean:
		rm -f lib/my/*.o
		rm -f lib/my/libmy.a
		rm -f *.o
		rm -f matchstick

fclean:	clean
		rm -f $(NAME)

rclean: re clean

debug: CFLAGS += -g3
debug: all

re: fclean all
