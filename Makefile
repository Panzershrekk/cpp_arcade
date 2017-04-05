CXX		=	g++

NAME		=	arcade

RM		=	rm -f

CXXFLAGS	+=	-std=c++11 -g
CXXFLAGS	+=	-Werror -Wall -Wextra
CXXFLAGS	+=	-I games/pacman/include
CXXFLAGS	+=	-I interface
CXXFLAGS	+=	-I exception/include
CXXFLAGS	+=	-ldl

SRCS		=	main.cpp 

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C games/
		make -C menu/
		$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C games/
		make clean -C menu/

fclean:		clean
		$(RM) $(NAME)
		make fclean -C games/
		make fclean -C menu/

re:		fclean all
