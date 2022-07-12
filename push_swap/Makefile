NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c \
	   push_swap_utils.c \
	   parsing.c \
	   dq_utils.c \
	   sorting.c \
	   sorting2.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
			@make -C libft
			@$(CC) $(CFLAGS) -L ./libft -lft $(OBJS) -o $@
			@echo "✏️  make push_swap!!"
%.o :%.c
		@$(CC) $(CFLAGS) -c $< -o $@
clean :
	@make -C libft clean
	@rm -rf $(OBJS)
	@echo "🧹 clean push_swap"

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "🫧  fclean push_swap"

re : fclean all

.PHONY: all clean fclean re
