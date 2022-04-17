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

NAME = libarraylist.a

INC_DIR = ./include/

SRC_DIR = ./src/

LIB_DIR = ./library/

SRC_FILES = $(SRC_DIR)arrlst_clear.c\
			$(SRC_DIR)arrlst_copy_list.c\
			$(SRC_DIR)arrlst_find_item.c\
			$(SRC_DIR)arrlst_get_size.c\
			$(SRC_DIR)arrlst_is_empty.c\
			$(SRC_DIR)arrlst_is_full.c\
			$(SRC_DIR)arrlst_new_list.c\
			$(SRC_DIR)arrlst_pop_back.c\
			$(SRC_DIR)arrlst_pop_front.c\
			$(SRC_DIR)arrlst_push_back.c\
			$(SRC_DIR)arrlst_push_front.c\
			$(SRC_DIR)arrlst_resize.c\
			$(SRC_DIR)arrlst_swap.c

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
