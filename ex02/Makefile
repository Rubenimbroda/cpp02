NAME = fixed02

SRCS = 	Fixed.cpp \
		main.cpp 

C++ = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(C++) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled ✅"

%.o: %.cpp
	@$(C++) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "clean done 🧹"

fclean: clean
	@rm -rf $(NAME)
	@echo "fclean done 🗑️"

re: fclean all

.PHONY: all clean fclean re