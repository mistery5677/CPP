NAME = Amateria

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS = main.cpp src/AMateria.cpp src/Cure.cpp src/Ice.cpp src/Character.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re