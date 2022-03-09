# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:11:25 by sungjpar          #+#    #+#              #
#    Updated: 2022/02/21 16:18:23 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=ft_hexdump
FILES=ft_display_file.c\
	  ft_stdin.c\
	  ft_main.c\
	  ft_str_funcs.c
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
