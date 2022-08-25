# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 15:22:28 by jiyokim           #+#    #+#              #
#    Updated: 2022/07/28 15:23:04 by jiyokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra 
SRCS = main.c \
	   parsing.c \
	   initialize.c \
	   simulation.c \
	   utils.c

INC = philosophers.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
			@$(CC) $(CFLAGS) -I ./$(INC) $(OBJS) -o $@
			@echo "🍝 MAKE philo"

%.o :%.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean :
		@rm -rf $(OBJS)
		@echo "🍝 clean philo's objs"

fclean : clean
		@rm -rf $(NAME)
		@echo "🍝 fclean philo"

re : fclean all

.PHONY: all clean fclean re
