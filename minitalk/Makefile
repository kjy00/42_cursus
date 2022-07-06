CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = minitalk
SERVER = server
CLIENT = client

OBJ_DIR = ./obj

SERVER_BONUS_SRCS = server_bonus.c \
			minitalk_utils_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c \
			minitalk_utils_bonus.c
SERVER_SRCS = server.c \
			minitalk_utils.c
CLIENT_SRCS = client.c \
			minitalk_utils.c

ifdef IS_BONUS
	SERVER_INCS = minitalk_bonus.h
	SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_BONUS_SRCS:.c=.o))
	CLIENT_INCS = minitalk_bonus.h
	CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_BONUS_SRCS:.c=.o))
else
	SERVER_INCS = minitalk.h
	SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_SRCS:.c=.o))
	CLIENT_INCS = minitalk.h
	CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_SRCS:.c=.o))
endif

LIBFT_DIR = ./libft
#LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(NAME)

bonus :
	@make IS_BONUS=1 all

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(LIBFT) $(SERVER_OBJS) $(SERVER_INCS)
	@$(CC) $(CFLAGS) -I ./ $(SERVER_OBJS) -L $(LIBFT_DIR) -lft -o $@
	@printf "🌷 Make $(SERVER) Done\n"

$(CLIENT) : $(LIBFT) $(CLIENT_OBJS) $(CLIENT_INCS)
	@$(CC) $(CFLAGS) -I ./ $(CLIENT_OBJS) -L $(LIBFT_DIR) -lft -o $@
	@printf "🌷 Make $(CLIENT) Done\n"

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@ -g

clean :
	@$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "🥀 Remove $(NAME)'s OBJs Done"

fclean : clean
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)
	@make -C $(LIBFT_DIR) fclean
	@echo "🥀 Remove $(NAME) Done"

re : fclean all

.PHONY : all clean fclean re bonus

$(LIBFT) :
	@make -C $(LIBFT_DIR)
