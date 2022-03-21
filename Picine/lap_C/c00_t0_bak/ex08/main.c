#include <unistd.h>

void	ft_print_combn(int n);

int	main(void)
{
	int		i;
	char	c;

	i = 1;
	while (i < 10)
	{
		c = i + '0';
		write(1, &c, 1);
		write(1, "-----\n", 6);
		ft_print_combn(i++);
		write(1, "\n", 1);
	}
	return (0);
}
