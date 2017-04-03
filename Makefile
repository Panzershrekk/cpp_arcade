CXX		=	g++

NAME		=	arcade

RM		=	rm -f

CXXFLAGS	+=	-std=c++11 -g
CXXFLAGS	+=	-Werror -Wall -Wextra
CXXFLAGS 	+=	-lncurses
CXXFLAGS	+=	-Igames/pacman/include
CXXFLAGS	+=	-Ilib
CXXFLAGS	+=	-Iexception/include
CXXFLAGS	+=	-lsfml-graphics -lsfml-window -lsfml-system

SRCS		=	main.cpp \
					games/pacman/entity/Blinky.cpp \
					games/pacman/entity/Pinky.cpp \
					games/pacman/entity/Inky.cpp \
					games/pacman/entity/Clyde.cpp \
					games/pacman/entity/Pacman.cpp \
					games/pacman/game/gameMapSfml.cpp \
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
