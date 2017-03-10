# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 14:04:45 by jcharloi          #+#    #+#              #
#    Updated: 2017/03/10 16:33:08 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c \
	print_type.c \
	print_type2.c \
	print_type3.c \
	create_tab.c

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
	$(CC) -o printf_exec main.c $(NAME) $(CFLAGS)
	./printf_exec

.PHONY: clean fclean re