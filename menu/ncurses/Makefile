CXX	=	g++

RM	=	rm -f

NAME	=	./lib_menu_ncurses.so

OBJ	=	$(SRC:.cpp=.o)

SRC	=	./mainMenu.cpp

CXXFLAGS	=	-fPIC			\
		-shared			\
		-Wall			\
		-Werror			\
		-Wextra			\
		-std=c++11		\
		-I ./include		\
		-I ../include		\
		-lncurses

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
