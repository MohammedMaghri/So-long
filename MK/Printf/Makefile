# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 12:38:28 by mmaghri           #+#    #+#              #
#    Updated: 2023/11/17 10:39:40 by mmaghri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libftprintf.a
SRCS	= turn.c callhex.c uuuss.c lencount.c  putnum.c putstring.c paste.c ft_printf.c

OBJS	= ${SRCS:%.c=%.o}
CC 		= CC
CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS) ft_printf.h
		 ar rcs $(NAME) $(OBJS)
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
