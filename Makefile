# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 13:32:31 by sungkim           #+#    #+#              #
#    Updated: 2021/06/27 14:03:35 by sungkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./basic_utils.c ./main_utils.c ./push_swap.c ./set_utils.c ./trash.c ./utils.c ./main.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap
LIBFT = libft_evaluation
LIBFT_LIB = libft.a

all: $(NAME)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)/$(LIBFT_LIB)

clean:
	rm -f $(OBJS)
	rm -f ./$(LIBFT)/$(LIBFT_LIB)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
