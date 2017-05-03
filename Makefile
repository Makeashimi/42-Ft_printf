# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 14:04:45 by jcharloi          #+#    #+#              #
#    Updated: 2017/05/03 13:21:20 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c \
	check_after.c \
	check_param.c \
	print_flags.c \
	print_width.c \
	print_precision.c \
	print_params.c \
	print_c.c \
	print_s.c \
	print_di.c \
	print_ou.c \
	print_p.c \
	print_x.c

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