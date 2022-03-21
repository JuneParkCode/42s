# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 17:35:58 by sungjpar          #+#    #+#              #
#    Updated: 2022/02/22 17:36:20 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
AR = ar rc

SRC_DIR=srcs
INC_DIR=includes

COMP_FILES=$(SRC_DIR)/ft_putchar.c\
		   $(SRC_DIR)/ft_swap.c\
		   $(SRC_DIR)/ft_putstr.c\
		   $(SRC_DIR)/ft_strlen.c\
		   $(SRC_DIR)/ft_strcmp.c
OBJ_FILES=$(COMP_FILES:.c=.o)

HEADER=$(INC_DIR)/ft.h

NAME=libft.a

all	:	$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $<

$(NAME)	: $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)

clean	:
	rm -f $(OBJ_FILES)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY : clean fclean all re

