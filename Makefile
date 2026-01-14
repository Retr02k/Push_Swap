NAME = push_swap

CC = cc
FLAGS = -Wall -Werror -Wextra
LIBFT = imports/libft/Makefile
PRINTF = imports/printf/Makefile

SRCS = push_swap.c \
		operations/push.c \
		operations/swap.c \
		operations/rotate.c \
		operations/reverse_rotate.c \
		algorithms/sort_small.c \
		algorithms/sort_large.c \
		utils/stack_utils.c \
		utils/input_validation.c \
		utils/error_handling.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C imports/libft
	$(MAKE) -C imports/printf
	$(CC) $(FLAGS) $(OBJS) imports/libft/libft.a imports/printf/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I imports/libft -I imports/printf -c -o $@ $<

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