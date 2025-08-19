# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 16:37:55 by anakrash          #+#    #+#              #
#    Updated: 2024/11/22 16:10:08 by anakrash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c

OBJS	:= $(SRCS:%.c=%.o)

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all: server client

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -Iprintf -c $? -o $@

server:	server.o
		@make -C libft
		@make -C printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o server

client:	client.o
		@make -C libft
		@make -C printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o client

clean:
			make clean -C libft
			make clean -C printf
			${RM} ${OBJS}

fclean:		clean
			${RM} server client

re:			fclean all

.PHONY: all clean fclean re