
SRCS=operations.c push_swap.c sort.c stack.c
NAME=push_swap
CC=cc
CFLAGS=-g
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
