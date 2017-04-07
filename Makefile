# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 14:04:45 by jcharloi          #+#    #+#              #
#    Updated: 2017/04/06 16:04:16 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c \
	check_after.c \
	print_param.c \
	print_param2.c \
	print_type.c \
	print_type2.c \
	print_type3.c

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