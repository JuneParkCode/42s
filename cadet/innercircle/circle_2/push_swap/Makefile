# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 00:54:23 by sungjpar          #+#    #+#              #
#    Updated: 2022/07/04 18:33:23 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

INC_DIR = ./include/

SRC_DIR = ./src/

LFT_DIR = ./library/libft

LIB_FLAG = -L $(LFT_DIR) -lft

INC_FLAG = -I$(INC_DIR) -I$(LFT_DIR)/include

SRC_FILES = $(addprefix $(SRC_DIR), deque_get_funcs.c\
			deque_idx_funcs.c\
			deque_pop_funcs.c\
			deque_push_funcs.c\
			deque_utils.c\
			command_push.c\
			command_rotation.c\
			command_rotation_reverse.c\
			command_swap.c\
			radix_sort.c\
			get_input.c\
			get_input_utils.c\
			simplify_numbers.c\
			has_duplicate_number.c\
			push_swap.c\
			sort.c\
			utils.c\
			sort_under_five.c\
			atoll.c\
			sort_three.c\
			main.c\
	)

OBJS = ${SRC_FILES:.c=.o}

all 	: $(NAME)

subsystem :
	$(MAKE) -C $(LFT_DIR) all

$(NAME)	: subsystem $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAG) -o $(NAME) $(INC_FLAG)

%.o 	: %.c
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

clean	:
	rm -f $(OBJS)
	$(MAKE) -C $(LFT_DIR) clean

fclean	: clean
	rm -f $(NAME)
	$(MAKE) -C $(LFT_DIR) fclean

re		: fclean
	$(MAKE) all

.PHONY	: clean fclean re all
