# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 20:42:24 by anakrash          #+#    #+#              #
#    Updated: 2024/11/16 16:45:58 by anakrash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c  ft_putchar.c  ft_puthex.c  ft_putnbr.c  ft_putpoint.c  ft_putstr.c  ft_putunnbr.c  ft_strlen.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -fPIC

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
