NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
INCLUDES = -I ./includes -I imports/printf -I imports/libft

SRCS = src/push_swap.c \
	src/algorithms/sort_radix.c \
	src/algorithms/sort_small.c \
	src/algorithms/sort_turkish.c \
	src/parsing/parse.c \
	src/parsing/validate.c \
	src/stack/operations.c \
	src/stack/stack.c \
	src/utils/math.c \
	src/utils/memory.c \
	src/utils/print.c \
	src/utils/ps_atoi.c \
	src/utils/is_dup.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C imports/libft
	$(MAKE) -C imports/printf
	$(CC) $(CFLAGS) $(OBJS) imports/libft/libft.a imports/printf/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C imports/libft clean
	$(MAKE) -C imports/printf clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C imports/libft fclean
	$(MAKE) -C imports/printf fclean
	rm -f $(NAME)

re: fclean all

ARGS ?=

.PHONY: all clean fclean re run test

run: $(NAME)
	./$(NAME) $(ARGS)