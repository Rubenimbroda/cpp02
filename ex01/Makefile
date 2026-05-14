NAME = fixed01

SRCS = 	Fixed.cpp \
		main.cpp 

CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled ✅"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "clean done 🧹"

fclean: clean
	@rm -rf $(NAME)
	@echo "fclean done 🗑️"

re: fclean all

.PHONY: all clean fclean re
