##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for compile my_defender
##

CFLAGS += -I./include

SRC		=		src/my_runner.c\
				src/event.c\
				src/use_func.c\
				src/sprite_move.c\
				src/text.c\
				src/main.c\
				src/display_game.c\
				src/music.c\
				src/men_tower.c\
				src/destroy.c\
				src/init_sprites.c\
				src/pos_text.c\
				src/pos_text2.c\
				src/follow_rode.c\
				src/follow_road.c\
				src/hitbox_buttons.c\
				src/init_button.c\
				src/pos_text3.c\
				src/manage_shop.c\
				src/init_shop.c\
				src/set_towers.c\
				src/init_towers.c\
				src/display_sprite.c

OBJ		=		$(SRC:.c=.o)

NAME	=		my_defender

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
		rm -f src/*.o

fclean:	clean
		rm -f $(NAME)

re:		fclean all