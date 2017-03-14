CXX		=	g++

NAME		=	arcade

RM		=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-Werror -Wall -Wextra
CXXFLAGS	+=	-Igames/pacman/include
CXXFLAGS	+=	-Ilib
CXXFLAGS	+=	-Iexception/include

SRCS		=	main.cpp \
					games/pacman/Blinky.cpp \
					exception/ArcadeException.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
					$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:		fclean all
