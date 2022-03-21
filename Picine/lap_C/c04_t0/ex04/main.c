#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
void	ft_putnbr_base(int nb, char *base);
int		abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
int	main(void)
{
	char	*b1 = "01";
	char	*ten_base = "0123456789";
	int		test_cases[] = {INT_MIN, -1243, -4325, -1, 0, 1, 12543, 3451, INT_MAX};
	for (int i = 0; i < 9; i += 1)
	{
		ft_putnbr_base(test_cases[i], ten_base);
		write(1,"n :", 1);
		ft_putnbr_base(test_cases[i], b1);
		write(1, "\n", 1);
	}
	return (0);
}

