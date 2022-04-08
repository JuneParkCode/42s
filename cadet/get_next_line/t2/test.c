#include "./get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int 	fd = open("./files/multiple_nlx5", O_RDONLY);
	char	*s;
	int 	i = 0;
	while (s = get_next_line(fd))
	{
		printf("%d : %s", ++i, s);
		if (s)
			free(s);
	}
	return (0);
}
