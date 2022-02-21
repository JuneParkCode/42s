# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:11:25 by sungjpar          #+#    #+#              #
#    Updated: 2022/02/21 16:49:44 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=ft_hexdump

SRC_FILES=ft_hexdump.c\
	  ft_hexdump2.c\
	  ft_main.c\
	  ft_print_line.c\
	  ft_print_memory.c\
	  ft_str_funcs.c

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
