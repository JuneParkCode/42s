# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 00:54:23 by sungjpar          #+#    #+#              #
#    Updated: 2022/07/07 19:18:09 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = fdf

INC_DIR = ./include/

SRC_DIR = ./src/

LFT_DIR = ./library/libft

MLX_DIR = ./library/minilibx_macos

LIB_FLAG = -L $(LFT_DIR) -lft\
		   -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

INC_FLAG = -I$(INC_DIR)\
		   -I$(LFT_DIR)/include\
		   -I$(MLX_DIR)

SRC_FILES = $(addprefix $(SRC_DIR),\
			get_map_info.c\
			main.c\
			atoll.c\
			check_string_utils.c\
			convert_string_data_to_int_data.c\
			read_and_check_file.c\
)

OBJS = ${SRC_FILES:.c=.o}

all 	: $(NAME)

subsystem :
	$(MAKE) -C $(LFT_DIR)
	$(MAKE) -C $(MLX_DIR)

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
