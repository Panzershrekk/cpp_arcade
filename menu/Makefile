CC	=	g++

RM	=	rm -f

NAME	=	test

SRC	=	./main.cpp		\
		./mainMenu.cpp

CFLAGS	=	-Wall			\
		-Werror			\
		-Wextra			\
		-std=c++11		\
		-I./include		\
		-lncurses		\
		-ldl

all:		$(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
