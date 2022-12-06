CXX				= c++
CXXFLAGS		= -Wall -Werror -Wextra -std=c++98 -pedantic-errors
RM				= rm -f

NAME			= compare
FTEXE			= ftexe
STDEXE			= stdexe

FTODIR			= ftobj
STDODIR			= stdobj

FTSRC			= main.cpp RedBlackTree.cpp
STDSRC			= main.cpp
FTOBJ			= $(FTSRC:%.cpp=$(FTODIR)/%.o)
STDOBJ			= $(STDSRC:%.cpp=$(STDODIR)/%.o)

OBJ				= $(FTOBJ) $(STDOBJ)

all:			ftexe stdexe $(NAME)

$(FTEXE):		CXXFLAGS += -DSWITCH=0
$(FTEXE):		$(FTOBJ)
				$(CXX) -o $@ $^ $(CXXFLAGS)

$(STDEXE):		CXXFLAGS += -DSWITCH=1
$(STDEXE):		$(STDOBJ)
				$(CXX) -o $@ $^ $(CXXFLAGS)

$(NAME):

$(FTODIR)/%.o:	%.cpp
				$(CXX) -o $@ -c $^ $(CXXFLAGS)

$(STDODIR)/%.o:	%.cpp
				$(CXX) -o $@ -c $^ $(CXXFLAGS)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME) $(FTEXE) $(STDEXE)

re:				fclean all

.PHONY:			all clean fclean re
