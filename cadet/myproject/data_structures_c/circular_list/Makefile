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

LIB_DIR = ./library/

SRC_FILES = $(SRC_DIR)clst_add_back.c\
			$(SRC_DIR)clst_add_front.c\
			$(SRC_DIR)clst_check_alone.c\
			$(SRC_DIR)clst_clear.c\
			$(SRC_DIR)clst_cmp_funcs.c\
			$(SRC_DIR)clst_del_node.c\
			$(SRC_DIR)clst_find_node.c\
			$(SRC_DIR)clst_get_length.c\
			$(SRC_DIR)clst_get_new_node.c\
			$(SRC_DIR)clst_is_empty.c\
			$(SRC_DIR)clst_last.c\
			$(SRC_DIR)clst_pop_back.c\
			$(SRC_DIR)clst_pop_front.c\
			$(SRC_DIR)clst_print_list.c\
			$(SRC_DIR)clst_swap_node.c
			

OBJS = ${SRC_FILES:.c=.o}

all 	: $(NAME)

$(NAME)	: $(OBJS)
	ar rcs $(LIB_DIR)$(NAME) $(OBJS) $(LIB_DIR)libft.a

%.o 	: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean	:
	rm -f $(OBJS) $(OBJ_BONUS)

fclean	: clean
	rm -f $(LIB_DIR)$(NAME)

re		: fclean all

bonus	:
	@make WITH_BONUS=1 all

.PHONY	: clean fclean re all
