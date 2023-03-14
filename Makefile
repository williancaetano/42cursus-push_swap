
SRCS=operations.c push_swap.c stack.c radix.c sort.c validations.c utils.c
NAME=push_swap
CC=cc
CFLAGS=-Wall -Werror -Wextra
LIBFT_PATH=libft
LIBFT=$(LIBFT_PATH)/libft.a


$(NAME): $(LIBFT)  $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

$(LIBFT): 
	@make -C $(LIBFT_PATH)
	@make -C $(LIBFT_PATH) bonus

all: $(NAME)

clean:
	make -C $(LIBFT_PATH) clean

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY:
	libft re clean fclean
