NAME = get_next_line

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	get_next_line.c \
		get_next_line_utils.c \
		main.c 

OBJS = $(SRCS:.c=.o)

HEADER = get_next_line.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
