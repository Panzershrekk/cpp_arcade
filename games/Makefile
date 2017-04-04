CC	=	gcc

RM	=	rm -f

NAME	=	../lib_pacman_ncurses.so

NAME2	=	../lib_pacman_sfml.so

NAME4	=	../lib_snake_ncurses.so

SRC	=	./pacman/entity/Blinky.cpp		\
			./pacman/entity/Pinky.cpp		\
			./pacman/entity/Pacman.cpp		\
			./pacman/game/gameMapNcurses.cpp

SRC2	=	./pacman/entity/Blinky.cpp		\
				./pacman/entity/Pinky.cpp		\
				./pacman/entity/Pacman.cpp		\
				./pacman/game/gameMapSfml.cpp


SRC4	=	./snake/game/Snake.cpp

CFLAGS	=	-fPIC			\
		-shared			\
		-Wall			\
		-Werror			\
		-Wextra			\
		-std=c++11		\
		-I./pacman/include \
		-I../lib

CFLAGS2	=	-fPIC			\
				-shared			\
				-Wall			\
				-Werror			\
				-Wextra			\
				-std=c++11		\
				-I./pacman/include \
				-I../lib \
				-lsfml-graphics -lsfml-window -lsfml-system

CFLAGS4	=	-fPIC			\
						-shared			\
						-Wall			\
						-Werror			\
						-Wextra			\
						-std=c++11		\
						-I./snake/include \
						-I../lib

all:		$(NAME) $(NAME2) $(NAME4)

$(NAME):
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(NAME2):
				$(CC) $(CFLAGS2) $(SRC2) -o $(NAME2)

$(NAME4):
				$(CC) $(CFLAGS4) $(SRC4) -o $(NAME4)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME) $(NAME2) $(NAME4)

re:		fclean all
