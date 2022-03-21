#include <stdio.h>

int ft_iterative_power(int nb, int power);

int main(void)
{
	for (int i = 0; i < 10; ++i)
		printf("%d\n", ft_iterative_power(0, i));
	return (0);
}
