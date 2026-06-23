NAME = ex02

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

SRCS =	srcs/main.cpp \
		srcs/Base.cpp\
		srcs/A.cpp\
		srcs/B.cpp\
		srcs/C.cpp

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