CC	=	gcc

RM	=	rm -f

NAME	=	../lib/lib_pacman.so

NAME4	=	../lib/lib_snake.so

SRC	=	./pacman/entity/Blinky.cpp		\
		./pacman/entity/Pinky.cpp		\
		./pacman/entity/Clyde.cpp		\
		./pacman/entity/Inky.cpp		\
		./pacman/entity/Pacman.cpp		\
		./pacman/game/gameMapNcurses.cpp	\
		./pacman/pacman_ncurses.cpp		\
		./pacman/pacman_sfml.cpp		\
		./pacman/game/gameMapSfml.cpp


SRC4	=	./snake/game/Snake.cpp			\
		./snake/game/gameMapNcursesSnake.cpp	\
		./snake/snake_ncurses.cpp		\
		./snake/game/gameMapSfmlSnake.cpp	\
		./snake/snake_sfml.cpp

CFLAGS	=	-fPIC			\
		-shared			\
		-Wall			\
		-Werror			\
		-Wextra			\
		-std=c++11		\
		-I ./pacman/include	\
		-I ../interface		\
		-lncurses		\
		-lsfml-graphics -lsfml-window -lsfml-system

CFLAGS4	=	-fPIC			\
		-shared			\
		-Wall			\
		-Werror			\
		-Wextra			\
		-std=c++11		\
		-I./snake/include	\
		-I../interface		\
		-lncurses		\
		-lsfml-graphics -lsfml-window -lsfml-system

all:		$(NAME) $(NAME2) $(NAME4)

$(NAME):
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(NAME4):
				$(CC) $(CFLAGS4) $(SRC4) -o $(NAME4)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME) $(NAME4)

re:		fclean all
