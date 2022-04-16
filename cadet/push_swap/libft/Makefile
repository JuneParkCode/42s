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

NAME = libft.a

INC_DIR = ./include/

SRC_DIR = ./src/

LIB_DIR = ../library/

SRC_FILES = $(SRC_DIR)ft_atoi.c\
			$(SRC_DIR)ft_bzero.c\
			$(SRC_DIR)ft_calloc.c\
			$(SRC_DIR)ft_isalnum.c\
			$(SRC_DIR)ft_isalpha.c\
			$(SRC_DIR)ft_isascii.c\
			$(SRC_DIR)ft_isdigit.c\
			$(SRC_DIR)ft_isprint.c\
			$(SRC_DIR)ft_itoa.c\
			$(SRC_DIR)ft_memchr.c\
			$(SRC_DIR)ft_memcmp.c\
			$(SRC_DIR)ft_memcpy.c\
			$(SRC_DIR)ft_memmove.c\
			$(SRC_DIR)ft_memset.c\
			$(SRC_DIR)ft_putchar_fd.c\
			$(SRC_DIR)ft_putendl_fd.c\
			$(SRC_DIR)ft_putnbr_fd.c\
			$(SRC_DIR)ft_putstr_fd.c\
			$(SRC_DIR)ft_split.c\
			$(SRC_DIR)ft_strchr.c\
			$(SRC_DIR)ft_strdup.c\
			$(SRC_DIR)ft_striteri.c\
			$(SRC_DIR)ft_strjoin.c\
			$(SRC_DIR)ft_strlcpy.c\
			$(SRC_DIR)ft_strlen.c\
			$(SRC_DIR)ft_strlcat.c\
			$(SRC_DIR)ft_strncmp.c\
			$(SRC_DIR)ft_strnstr.c\
			$(SRC_DIR)ft_strmapi.c\
			$(SRC_DIR)ft_strrchr.c\
			$(SRC_DIR)ft_strtrim.c\
			$(SRC_DIR)ft_substr.c\
			$(SRC_DIR)ft_tolower.c\
			$(SRC_DIR)ft_toupper.c\
			$(SRC_DIR)ft_isinset.c\
			$(SRC_DIR)ft_isspace.c\
			$(SRC_DIR)ft_strcspn.c\
			$(SRC_DIR)ft_strpbrk.c\
			$(SRC_DIR)ft_get_next_line.c\
			$(SRC_DIR)ft_printf.c\
			$(SRC_DIR)ft_putaddr_fd.c\
			$(SRC_DIR)ft_puthex_fd.c\
			$(SRC_DIR)ft_set_print_color.c
			

SRC_BONUS = $(SRC_DIR)ft_lstnew.c\
			$(SRC_DIR)ft_lstadd_front.c\
			$(SRC_DIR)ft_lstsize.c\
			$(SRC_DIR)ft_lstlast.c\
			$(SRC_DIR)ft_lstadd_back.c\
			$(SRC_DIR)ft_lstclear.c\
			$(SRC_DIR)ft_lstdelone.c\
			$(SRC_DIR)ft_lstiter.c\
			$(SRC_DIR)ft_lstmap.c

OBJS = ${SRC_FILES:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

ifdef WITH_BONUS
    OBJ = $(OBJ_BONUS)
else
    OBJ = $(OBJS)
endif

all 	: $(NAME)

$(NAME)	: $(OBJ)
	ar rcs $(LIB_DIR)/$(NAME) $(OBJ)

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
