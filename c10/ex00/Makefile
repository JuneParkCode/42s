$(CC)=gcc
$(CFLAGS)=-Wall -Wextra -Werror
$(TARGET)=ft_display_file
$(FILES)=ft_display_file.c

$(TARGET)	:	$(FILES)
	$(CC) $(CFLAG) -o $(TARGET) $@ $<

all	:	$(TARGET)

clean	:	$(FILES)
	rm -f $(FILES)

fclean	:	clean
	rm -f $(TARGET)

.PHONY	:	clean fclean
