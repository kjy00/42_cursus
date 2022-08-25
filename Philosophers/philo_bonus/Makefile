# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 17:52:26 by jiyokim           #+#    #+#              #
#    Updated: 2022/08/08 17:52:27 by jiyokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c \
	   parsing.c \
	   initialize.c \
	   simulation.c \
	   dining.c \
	   utils.c

INC = philo_bonus.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -I ./$(INC) $(OBJS) -o $@
	@echo "🍝 MAKE philo_bonus"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)
	@echo "🍝 clean philo_bonus"

fclean : clean
	@rm -rf $(NAME)
	@echo "🍝 fclaen philo_bonus"

re : fclean all

.PHONY: all clean fclean re
