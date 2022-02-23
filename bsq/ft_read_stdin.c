#include <unistd.h>
#include <stdio.h>
#include "ft_bsq.h"

#define BUFFER_SIZE 200000

char **get_stdin()
{
	int		read_size;
	int		buf_size;
	char	buf[BUFFER_SIZE];

	buf_size = 0;
	while (1)
	{
		read_size = read(STDIN_FILENO, &buf[buf_size], BUFFER_SIZE);
		buf_size += read_size;
		if (read_size == 0)
			break;
	}
	return (get_lines(buf, get_line_num(buf, buf_size)));
}