NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c show_stack.c error_handling.c lst_utils.c	\
	   pre_sort.c reverse_rotate.c rotate_stack.c swap_stack.c	\
	    medium_algo.c check_stack.c simple_algo.c push_stack.c build_stack.c	\
	   complex_algo.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./push_swap_utils
	$(CC) $(CFLAGS) $(OBJS) ./push_swap_utils/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./push_swap_utils clean

fclean: clean
	rm -f $(NAME)
	make -C ./push_swap_utils fclean

re: fclean all

.PHONY: all clean fclean re
