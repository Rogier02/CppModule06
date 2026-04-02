NAME		= conveter
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++17

SRCS		= main.cpp \
				ScalarConvert.cpp

OBJS		= $(SRCS:.cpp=.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

%.o			: %.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean		:
			$(RM) $(NAME)

fclean		:clean
			$(RM) $(NAME)

re			: fclean all

.PHONY		:all clean fclean re