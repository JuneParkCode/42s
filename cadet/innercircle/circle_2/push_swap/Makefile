# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 00:54:23 by sungjpar          #+#    #+#              #
#    Updated: 2022/07/02 11:42:29 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

INC_DIR = ./include/

SRC_DIR = ./src/

SRC_FILES = $(SRC_DIR)deque_get_funcs.c\
			$(SRC_DIR)deque_idx_funcs.c\
			$(SRC_DIR)deque_pop_funcs.c\
			$(SRC_DIR)deque_push_funcs.c\
			$(SRC_DIR)deque_utils.c\
			$(SRC_DIR)command_push.c\
			$(SRC_DIR)command_rotation.c\
			$(SRC_DIR)command_rotation_reverse.c\
			$(SRC_DIR)command_swap.c\
			$(SRC_DIR)radix_sort.c\
			$(SRC_DIR)get_input.c\
			$(SRC_DIR)simplify_numbers.c\
			$(SRC_DIR)has_duplicate_number.c\
			$(SRC_DIR)push_swap.c\
			$(SRC_DIR)main.c

OBJS = ${SRC_FILES:.c=.o}

all 	: $(NAME)

$(NAME)	: $(OBJS)
	@make -C ./library/libft
	$(CC) $(CFLAGS) $(OBJS) -L ./library/libft -lft -o $(NAME) -I $(INC_DIR)

%.o 	: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ 

clean	:
	rm -f $(OBJS)
	@make -C ./library/libft clean

fclean	: clean
	rm -f $(NAME)
	@make -C ./library/libft fclean

re		: fclean
	@make all

.PHONY	: clean fclean re all
