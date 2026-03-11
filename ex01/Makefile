CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -f
SRCS = 	main.cpp\
			Contact.cpp\
			phonebook.cpp\
			search_contact.cpp

OBJFILES = $(SRCS:.cpp=.o)

NAME = phonebook

all: $(NAME)

$(NAME):$(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re