NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c show_stack.c error_handling.c lst_utils.c	\
	   pre_sort.c reverse_rotate.c rotate_stack.c swap_stack.c	\
	   check_stack.c simple_algo.c push_stack.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./push_swap_utils
	cp ./push_swap_utils/libftprintf.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./push_swap_utils clean

fclean: clean
	rm -f $(NAME)
	make -C ./push_swap_utils fclean

.PHONY: all clean fclean
