# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 00:54:23 by sungjpar          #+#    #+#              #
#    Updated: 2022/04/15 15:15:06 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

INC_DIR = ./include/

SRC_DIR = ./src/

SRC_FILES = $(SRC_DIR)main.c

OBJS = ${SRC_FILES:.c=.o}

all 	: $(NAME)

$(NAME)	: $(OBJ)
	@make -C ./libft
	ar rcs $(NAME) $(OBJ)

%.o 	: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean	:
	rm -f $(OBJS) $(OBJ_BONUS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY	: clean fclean re all
