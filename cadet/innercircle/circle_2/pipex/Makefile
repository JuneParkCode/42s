# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 00:54:23 by sungjpar          #+#    #+#              #
#    Updated: 2022/07/19 15:27:45 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = pipex

INC_DIR = ./include/

SRC_DIR = ./src/

LFT_DIR = ./library/libft

LIB_FLAG = -L $(LFT_DIR) -lft\

INC_FLAG = -I$(INC_DIR)\
		   -I$(LFT_DIR)/include\

SRC_FILES = $(addprefix $(SRC_DIR),\
			argument_parsing_functions.c\
			build_pipe_functions.c\
			check_argument_functions.c\
			do_command_functions.c\
			do_command_from_infile.c\
			error_control_functions.c\
			execute_command_functions.c\
			free_functions.c\
			ft_split_quote_case.c\
			main.c\
			run_pipex.c\
)

OBJS = ${SRC_FILES:.c=.o}

all 	: $(NAME)

subsystem :
	$(MAKE) -C $(LFT_DIR)

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
