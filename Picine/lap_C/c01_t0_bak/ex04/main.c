#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_ultimate_div_mod(int *a, int *b);

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

int	main(void)
{
	int	i;
	int	j;

	i = 42;
	j = 30;
	ft_ultimate_div_mod(&i, &j);
	ft_putnbr(i);
	write(1, ",", 1);
	ft_putnbr(j);
}
