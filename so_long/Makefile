CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs
RM = rm -rf
NAME = so_long
MLX_DIR = ./mlx

SRCS = ./gnl/get_next_line.c \
	   ./gnl/get_next_line_utils.c \
	   so_long.c \
	   so_long_utils.c \
	   so_long_utils2.c \
	   move.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -I ./ $(OBJS) -L ./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "☺️  make so____long!"
clean :
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS)
	@echo "🧹 clean~~"

fclean : clean
	@$(RM) $(NAME)
	@echo "🔥 fclean~~~"

re : fclean all

.PHONY : all clean fclean re
