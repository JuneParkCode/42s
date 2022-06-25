# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 14:22:24 by sungjpar          #+#    #+#              #
#    Updated: 2022/03/24 12:26:29 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_DIR = ./src/

INC_DIR = ./include/

SRC_FILES = $(SRC_DIR)ft_printf.c\
			$(SRC_DIR)ft_putaddr.c\
			$(SRC_DIR)ft_puthex.c\
			$(SRC_DIR)ft_putnbr.c\
			$(SRC_DIR)ft_putstr.c\
			$(SRC_DIR)ft_putchar.c\
			$(SRC_DIR)ft_strlen.c
			
OBJS = ${SRC_FILES:.c=.o}

all		: $(NAME)

$(NAME)	: $(OBJS)
	ar rcs $(NAME) $(OBJS)

%o		: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean	:
	rm -f $(OBJS)
.PHONY	: clean

fclean	: clean
	rm -f $(NAME)
.PHONY	: fclean

re		: fclean all
.PHONY	: re
