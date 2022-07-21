# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 00:54:23 by sungjpar          #+#    #+#              #
#    Updated: 2022/07/21 14:36:46 by sungjpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = pipex

INC_DIR = ./include/

SRC_DIR = ./src/

BONUS_DIR = ./bonus/

LFT_DIR = ./library/libft

LIB_FLAG = -L $(LFT_DIR) -lft\

INC_FLAG = -I$(INC_DIR)\
		   -I$(LFT_DIR)/include\

SRC_FILES = $(addprefix $(SRC_DIR),\
			argument_parsing_functions.c\
			check_argument_functions.c\
			error_control_functions.c\
			execute_command_functions.c\
			free_functions.c\
			ft_split_quote_case.c\
			inlet_argument_function.c\
			main.c\
			parallel_pipe_line_functions.c\
			set_fd_functions.c\
)

BONUS_FILES = $(addprefix $(BONUS_DIR),\
			argument_parsing_functions_bonus.c\
			check_argument_functions_bonus.c\
			error_control_functions_bonus.c\
			execute_command_functions_bonus.c\
			free_functions_bonus.c\
			ft_split_quote_case_bonus.c\
			heredoc_mode_bonus.c\
			inlet_argument_function_bonus.c\
			main_bonus.c\
			parallel_pipe_line_functions_bonus.c\
			set_fd_functions_bonus.c\
)

OBJS = ${SRC_FILES:.c=.o}

OBJ_BONUS = ${BONUS_FILES:.c=.o}

ifdef WITH_BONUS
    OBJ = $(OBJ_BONUS)
else
    OBJ = $(OBJS)
endif

all 	: $(NAME)

subsystem :
	$(MAKE) -C $(LFT_DIR)

$(NAME)	: subsystem $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAG) -o $(NAME) $(INC_FLAG)

%.o 	: %.c
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

clean	:
	rm -f $(OBJS)
	rm -f $(OBJ_BONUS)
	$(MAKE) -C $(LFT_DIR) clean

fclean	:
	rm -f $(NAME)
	$(MAKE) clean
	$(MAKE) -C $(LFT_DIR) fclean

re		:
	$(MAKE) fclean
	$(MAKE) all

bonus_re: fclean
	$(MAKE) bonus

bonus	:
	$(MAKE) fclean
	@make WITH_BONUS=1 all

.PHONY	: clean fclean re all bonus
