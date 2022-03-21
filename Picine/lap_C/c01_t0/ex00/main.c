#include <unistd.h>

void	ft_ft(int *nbr);
void	ft_putnbr(int nb);

int	main(void)
{
	int	i;
	int	j;
	
	i = 100;
	j = -234141;
	ft_ft(&i);
	ft_ft(&j);
	ft_putnbr(i);
	write(1, "\n", 1);
	ft_putnbr(j);
	return (0);
}
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
