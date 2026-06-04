NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	parsing.c \
	init_stack.c \
	stack_utils.c \
	stack_utils2.c \
	sa_sb_ss.c \
	pa_pb.c \
	ra_rb_rr.c \
	rra_rrb_rrr.c \
	small_sort.c \
	low_sort.c \
	simple_sort.c \
	medium_sort.c \
	radix_sort.c \
	sort.c \
	utils.c \
	free.c \
	split.c \
	option.c \
	disorder.c \
	bench.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
