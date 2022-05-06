# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 00:54:23 by sungjpar          #+#    #+#              #
#    Updated: 2022/05/06 19:48:37 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = echo

INC_DIR = ./include/

SRC_DIR = ./src/

LIB_DIR = ./library/

LIB_FILES = libft.a

SRC_FILES = $(SRC_DIR)echo.c\
			$(SRC_DIR)main.c

OBJS = ${SRC_FILES:.c=.o}

all 	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) $(LIB_DIR)$(LIB_FILES) -o $(NAME)
	
%.o 	: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(LIB_DIR)$(NAME)

re		: fclean all

.PHONY	: clean fclean re all
