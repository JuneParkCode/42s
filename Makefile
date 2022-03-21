# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 14:22:24 by sungjpar          #+#    #+#              #
#    Updated: 2022/03/21 14:34:00 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_DIR = ./src/

INC_DIR = ./include/

SRC_FILES = $(SRC_DIR)ft_printf.c

OBJS = ${SRC_FILES:.c=.o}

all		: $(NAME)
$(NAME)	: $(OBJS)
	ar rcs $(NAME) $(OBJS)

%o		: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all
