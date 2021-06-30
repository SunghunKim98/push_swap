CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./get_next_line_utils.c ./get_next_line.c ./main.c ./utils_1.c ./utils_2.c ./utils_3.c
OBJS = $(SRCS:.c=.o)

NAME = checker
LIBFT = ../libft_evaluation
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
