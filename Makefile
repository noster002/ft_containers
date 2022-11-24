CC			= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98 -pedantic-errors
RM			= rm -f
NAME		= test
SRC			= main.cpp RedBlackTree.cpp
OBJ			= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) -o $@

%.o:		%.cpp
			$(CC) -c $^ $(CFLAGS) -o $@

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
