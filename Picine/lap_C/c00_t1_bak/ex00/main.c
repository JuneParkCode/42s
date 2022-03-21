#include <unistd.h>

void	ft_putchar(char c);

int	main(void)
{
	int		i;
	char	c;
	char	nl;

	i = -128;
	nl = '\n';
	while (i < 128)
	{
		c = (char) i;
		ft_putchar(c);
		write(1, &nl, 1);
		++i;
	}
	return (0);
}
