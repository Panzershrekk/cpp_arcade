CXX	=	g++

RM	=	rm -f

NAME	=	../../lib/lib_menu_SFML.so

OBJ	=	$(SRC:.cpp=.o)

SRC	=	./mainMenu.cpp

CXXFLAGS	=	-fPIC			\
		-shared			\
		-Wall			\
		-Werror			\
		-Wextra			\
		-std=c++11		\
		-I ./include		\
		-I ../../interface	\
		-lsfml-graphics -lsfml-window -lsfml-system


all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
