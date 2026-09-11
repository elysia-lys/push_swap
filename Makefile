NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c show_stack.c error_handling.c lst_utils.c	\
	pre_sort.c reverse_rotate.c rotate_stack.c swap_stack.c	\
	medium_algo.c check_stack.c simple_algo.c push_stack.c build_stack.c	\
	complex_algo.c custom_algo.c flag_parsing.c benchmark.c \
	reverse_rotate_np.c rotate_stack_np.c swap_stack_np.c push_stack_np.c

OBJS = $(SRCS:.c=.o)

B_NAME = checker
B_SRCS = checker.c  error_handling.c lst_utils.c \
		pre_sort.c reverse_rotate_np.c rotate_stack_np.c swap_stack_np.c \
		check_stack.c push_stack_np.c build_stack.c

B_OBJS = $(B_SRCS:.c=.o)


all: $(NAME) $(B_NAME)

$(NAME): $(OBJS)
	make -C ./push_swap_utils
	$(CC) $(CFLAGS) $(OBJS) ./push_swap_utils/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(B_OBJS)
	make -C ./push_swap_utils clean

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)
	make -C ./push_swap_utils fclean

re: fclean all

bonus: $(B_NAME)

$(B_NAME): $(B_OBJS)
	make -C ./push_swap_utils
	$(CC) $(CFLAGS) $(B_OBJS) ./push_swap_utils/libftprintf.a -o $(B_NAME)

.PHONY: all clean fclean re
