#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	unsigned int	n;
	char			c;

	if (nb < 0)
	{
		n = -nb;
		write(1, "-", 1);
	}
	else
		n = nb;
	c = n % 10 + '0';
	n /= 10;
	if (n > 0)
		ft_putnbr(n);
	write(1, &c, 1);
}
