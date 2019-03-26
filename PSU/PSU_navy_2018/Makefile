##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =	src/navy.c				\
		src/error_gestion.c		\
		src/init_map.c			\
		src/modif_map.c			\
		src/fill_empty_map.c	\
		src/play_navy.c			\
		src/modif_map_ig.c		\
		src/manage_attack.c		\
		src/manage_signal.c		\
		src/call_signal.c		\
		src/modif_map_ig_t2.c	\
		src/main.c

OBJ = $(SRC:.c=.o)

NAME = navy

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
		rm -f src/*.o
		rm -f navy

fclean:	clean
		rm -f $(NAME)

rclean: re clean

debug: CFLAGS += -g3
debug: fclean all

re: fclean all
