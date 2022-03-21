CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC_DIR=./src
INC_DIR=./includes
OBJ_FILES=$(SRC_DIR)/ft_putchar.o $(SRC_DIR)/ft_swap.o $(SRC_DIR)/ft_putstr.o $(SRC_DIR)/ft_strlen.o $(SRC_DIR)/ft_strcmp.o
INC_OBJ_FILES=$(INC_DIR)/ft.o
TARGET=LIB_FILE
LIB_FILE=libft.a

$(LIB_FILE) : $(OBJ_FILES) $(INC_OBJ_FILES) LIB

all : $(LIB_FILE)

$(SRC_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) -c -Iinc -o $@ $< $(CFLAGS)

LIB : $(OBJ_FILES)
	ar rc $(LIB_FILE) $(OBJ_FILES) $(INC_OBJ_FILES)

LIB_FILE	:	all

$(INC_DIR)/ft.o: $(INC_DIR)/ft.h
	$(CC) $(CFLAGS) -c -Iinc -o $@ $<

clean	:
	rm -f $(OBJ_FILES) $(INC_OBJ_FILES)

fclean	:	clean
	rm -f $(LIB_FILE)

re	:	fclean all
