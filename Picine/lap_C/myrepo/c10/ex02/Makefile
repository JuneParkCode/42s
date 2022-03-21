# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:09:54 by sungjpar          #+#    #+#              #
#    Updated: 2022/02/21 16:14:15 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=ft_tail
FILES=ft_atoi.c\
	  ft_file.c\
	  ft_main.c\
	  ft_put_tail.c\
	  ft_stdin.c\
	  ft_str_funcs.c\
	  ft_str_funcs2.c\
	  ft_tail.c\
OBJS=$(FILES:.c=.o)

$(TARGET)	:	ALL

%.o	: %.c
	$(CC) $(CFLAGS) -c  $< -o $@

all	:	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all
