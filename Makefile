# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 14:04:45 by jcharloi          #+#    #+#              #
#    Updated: 2017/04/10 16:43:56 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c \
	check_after.c \
	print_param.c \
	print_param2.c \
	print_precision.c \
	print_csp.c \
	print_dio.c \
	print_oux.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ)
	make -C libft/
	libtool -static -o $@ $^ libft/libft.a

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: clean fclean all

test:
	$(CC) -o printf_exec main.c $(NAME)
	./printf_exec

.PHONY: clean fclean re