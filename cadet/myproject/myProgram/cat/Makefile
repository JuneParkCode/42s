# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:11:25 by sungjpar          #+#    #+#              #
#    Updated: 2022/05/07 14:27:54 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=ft_cat

SRC_DIR=./src/

INC_DIR=./include/

SRC_FILES=$(SRC_DIR)ft_display_file.c\
	 	$(SRC_DIR)ft_main.c\
	  	$(SRC_DIR)ft_stdin.c\
	  	$(SRC_DIR)ft_str_funcs.c

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
