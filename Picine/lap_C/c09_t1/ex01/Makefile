CC=gcc
CFLAGS=-Wall -Wextra -Werror -c

AR=ar rc

SRC_DIR=./srcs
INC_DIR=./includes

COMP_FILES=$(SRC_DIR)/ft_putchar.c\
		   $(SRC_DIR)/ft_swap.c\
		   $(SRC_DIR)/ft_putstr.c\
		   $(SRC_DIR)/ft_strlen.c\
		   $(SRC_DIR)/ft_strcmp.c
OBJ_FILES=$(COMP_FILES:.c=.o)

HEADER=$(INC_DIR)/ft.h

TARGET=libft.a

$(TARGET)	: $(OBJ_FILES) AR

$(OBJ_FILES)	: $(COMP_FILES)
	$(CC) $(CFLAGS) -I $(HEADER) ${@:.o=.c} -o $@

all : $(TARGET)

AR : $(OBJ_FILE)
	$(AR) $(TARGET) $(OBJ_FILES)

clean	:
	rm -f $(OBJ_FILES)

fclean	:	clean
	rm -f $(TARGET)

re	:	fclean all

.PHONY : clean fclean all re

