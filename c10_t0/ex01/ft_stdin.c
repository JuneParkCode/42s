#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 30000

void	ft_put(char *str, unsigned int size);
int		ft_strcmp(char *s1, char *s2);

int	ft_putstdin(void)
{
	int		read_size;
	char	buffer[BUFFER_SIZE];

	read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		ft_put(buffer, read_size);
		read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (!read_size)
			return (1);
	}
	return (0);
}
