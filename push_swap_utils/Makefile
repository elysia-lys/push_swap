NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c hex_conversion.c num_conversion.c \
		string_conversion.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

.PHONY: all clean fclean