CC	=	gcc

RM	=	rm -f

NAME	=	../lib_pacman.so

SRC	=	./pacman/entity/Blinky.cpp		\
			./pacman/entity/Pinky.cpp		\
			./pacman/entity/Pacman.cpp		\
			./pacman/game/gameMapNcurses.cpp

CFLAGS	=	-fPIC			\
		-shared			\
		-Wall			\
		-Werror			\
		-Wextra			\
		-std=c++11		\
		-I./pacman/include \
		-I../lib

all:		$(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
