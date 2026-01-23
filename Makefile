NAME = push_swap

CC = cc
FLAGS = -Wall -Werror -Wextra

SRCS = src/push_swap.c \
		algorithms/sort_radix.c \
		algorithms/sort_small.c \
		algorithms/sort_turkish.c \
		parsing/parse.c \
		parsing/validate.c \
		stack/operations.c \
		stack/stack.c \
		utils/math.c \
		utils/memory.c \
		utils/print.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C imports/libft
	$(MAKE) -C imports/printf
	$(CC) $(FLAGS) $(OBJS) imports/libft/libft.a imports/printf/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I./includes -I imports/libft -I imports/printf -c -o $@ $<

clean:
	$(MAKE) -C imports/libft clean
	$(MAKE) -C imports/printf clean
	rm -fr $(OBJS)


fclean: clean
	$(MAKE) -C imports/libft fclean
	$(MAKE) -C imports/printf fclean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re