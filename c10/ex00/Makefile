CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=ft_display_file
FILES=ft_display_file.c

$(TARGET)	:	$(FILES)
	$(CC) $(CFLAGS) $< -o $(TARGET)

all	:	$(TARGET)

clean	:	$(FILES)
	rm -f ft_display_file.o

fclean	:	clean
	rm -f $(TARGET)

.PHONY	:	clean fclean
