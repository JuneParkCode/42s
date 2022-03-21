# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:11:09 by sungjpar          #+#    #+#              #
#    Updated: 2022/02/21 16:11:10 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=ft_display_file
FILES=ft_display_file.c
OBJS=$(FILES:.c=.o)

$(TARGET)	:	ALL

%.o	: %.c
	$(CC) $(CFLAGS) -c  $< -o $<

all	:	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:	$(FILES)
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all
