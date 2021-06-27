# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 20:40:24 by sungkim           #+#    #+#              #
#    Updated: 2021/05/06 19:52:41 by sungkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strchr.c ./ft_strdup.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_toupper.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	ar -rc $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
