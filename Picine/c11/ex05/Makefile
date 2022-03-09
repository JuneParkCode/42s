# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:11:25 by sungjpar          #+#    #+#              #
#    Updated: 2022/02/22 00:13:13 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=do-op

SRC_FILES=ft_main.c\
		  ft_calculation.c\
		  ft_str_funcs.c\
		  ft_atoi.c

OBJS=${SRC_FILES:.c=.o}

all	: $(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS) -c  $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all out
