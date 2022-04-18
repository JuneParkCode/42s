# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 00:54:23 by sungjpar          #+#    #+#              #
#    Updated: 2022/04/15 14:59:48 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libstack_arrlst.a

INC_DIR = ./include/

SRC_DIR = ./src/

LIB_DIR = ./library/

SRC_FILES = $(SRC_DIR)stack_make_stack.c\

OBJS = ${SRC_FILES:.c=.o}

all 	: $(NAME)

$(NAME)	: $(OBJS)
	ar rcs $(LIB_DIR)$(NAME) $(OBJS)

%.o 	: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(LIB_DIR)$(NAME)

re		: fclean all

.PHONY	: clean fclean re all
