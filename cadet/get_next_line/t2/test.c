#include "./get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int fd = open("./files/empty", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
