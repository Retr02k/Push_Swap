NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes
DEBUG_FLAGS = -fsanitize=address -g

SRCS = algorithms/bubble_sort/bubble_sort.c \
	algorithms/radix/radix_utils.c \
	algorithms/radix/radix.c \
	algorithms/radix/shift_node_to_array.c \
	src/moves/push_to_stack.c \
	src/moves/ra.c \
	src/moves/rb.c \
	src/moves/rr.c \
	src/moves/rra.c \
	src/moves/rrb.c \
	src/moves/rrr.c \
	src/moves/sa.c \
	src/moves/sb.c \
	src/moves/ss.c \
	src/stack/stack.c \
	src/utils/add_to_stack.c \
	src/utils/create_node.c \
	src/utils/is_dup.c \
	src/utils/ps_atoi.c \
	src/utils/sort_small_helpers.c \
	src/utils/sort_small.c \
	src/push_swap.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

ARGS ?=

run: $(NAME)
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re debug run