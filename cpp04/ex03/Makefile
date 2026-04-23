NAME = bonus

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

SRCS =	src/Cure.cpp \
		src/AMateria.cpp \
		src/Ice.cpp \
		src/main.cpp \
		src/Character.cpp \
		src/MateriaSource.cpp
		
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