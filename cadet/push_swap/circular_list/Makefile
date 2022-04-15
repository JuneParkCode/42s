# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 00:54:23 by sungjpar          #+#    #+#              #
#    Updated: 2022/04/15 18:10:49 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libclist.a

INC_DIR = ./include/

SRC_DIR = ./src/

SRC_FILES = $(SRC_DIR)clst_addback.c\
			$(SRC_DIR)clst_get_length.c\
			$(SRC_DIR)clst_get_new_node.c\
			$(SRC_DIR)clst_is_empty.c\
			$(SRC_DIR)clst_last.c\
			$(SRC_DIR)clst_print_list.c\
			$(SRC_DIR)clst_swap_node.c

OBJS = ${SRC_FILES:.c=.o}

all 	: $(NAME)

$(NAME)	: $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o 	: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean	:
	rm -f $(OBJS) $(OBJ_BONUS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

bonus	:
	@make WITH_BONUS=1 all

.PHONY	: clean fclean re all
