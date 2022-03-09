# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:11:25 by sungjpar          #+#    #+#              #
#    Updated: 2022/02/22 11:23:54 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=ft_tail

SRC_FILES=ft_atoi.c\
	  ft_file.c\
	  ft_main.c\
	  ft_put_tail.c\
	  ft_tail.c\
	  ft_stdin.c\
	  ft_str_funcs.c\
	  ft_str_funcs2.c\
	  ft_buffer.c

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
