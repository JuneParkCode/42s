#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_sort_int_tab(int *tab, int size);

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
	int t1[] = {54,2,214,4,5,-34143,7,8,9,10};
	int t2[] = {5,6,7};
	int	i;

	ft_sort_int_tab(&t1[0], 10);
	ft_sort_int_tab(&t2[0], 3);

	i = 0;
	while (i < 10)
	{
		ft_putnbr(t1[i++]);
		write(1, ",", 1);
	}
	write(1, "\n==\n", 3);
	i = 0;
	while (i < 3)
	{
		ft_putnbr(t2[i++]);
		write(1, ",", 1);
	}
	return (0);
}
