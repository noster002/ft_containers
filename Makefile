CXX				= c++
CXXFLAGS		= -Wall -Werror -Wextra -std=c++98 -pedantic-errors
RM				= rm -f

FTEXE			= ftexe
STDEXE			= stdexe

FTODIR			= ftobj
STDODIR			= stdobj

FTSRC			= main.cpp
STDSRC			= main.cpp
FTOBJ			= $(FTSRC:%.cpp=$(FTODIR)/%.o)
STDOBJ			= $(STDSRC:%.cpp=$(STDODIR)/%.o)

OBJ				= $(FTOBJ) $(STDOBJ)

NAME			= diff.txt

DIFF			= diff -u -I 'execution time: '

FTTXT			= ft.txt
STDTXT			= std.txt

ARG				= 42

TIME			= tail -n 3

all:			exe diff

exe:			$(FTEXE) $(STDEXE)

$(FTEXE):		CXXFLAGS += -DSWITCH=0
$(FTEXE):		$(FTOBJ)
				$(CXX) -o $@ $^ $(CXXFLAGS)

$(STDEXE):		CXXFLAGS += -DSWITCH=1
$(STDEXE):		$(STDOBJ)
				$(CXX) -o $@ $^ $(CXXFLAGS)

diff:			$(NAME)

$(NAME):		$(FTTXT) $(STDTXT)
				$(DIFF) $(FTTXT) $(STDTXT) > $@

$(FTTXT):		$(FTEXE)
				./$^ $(ARG) > $@

$(STDTXT):		$(STDEXE)
				./$^ $(ARG) > $@

$(FTODIR)/%.o:	%.cpp
				$(CXX) -o $@ -c $^ $(CXXFLAGS)

$(STDODIR)/%.o:	%.cpp
				$(CXX) -o $@ -c $^ $(CXXFLAGS)

time:			$(FTTXT) $(STDTXT)
				$(TIME) $(FTTXT) $(STDTXT)

clean:
				$(RM) $(OBJ)

execlean:		clean
				$(RM) $(FTEXE) $(STDEXE)

diffclean:
				$(RM) $(NAME) $(FTTXT) $(STDTXT)

fclean:			clean execlean diffclean

exere:			execlean exe

diffre:			diffclean diff

re:				fclean all

.PHONY:			all clean fclean re
