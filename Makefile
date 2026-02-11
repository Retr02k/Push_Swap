NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = src/push_swap.c \
	src/algorithms/sort_radix.c \
	src/algorithms/sort_small.c \
	src/algorithms/sort_turkish.c \
	src/parsing/parse.c \
	src/parsing/validate.c \
	src/stack/operations.c \
	src/stack/stack.c \
	src/utils/add_to_stack.c \
	src/utils/create_node.c \
	src/utils/is_dup.c \
	src/utils/ps_atoi.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

ARGS ?=

.PHONY: all clean fclean re run test

run: $(NAME)
	./$(NAME) $(ARGS)