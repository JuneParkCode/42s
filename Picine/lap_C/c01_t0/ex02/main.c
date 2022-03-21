#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a = 10;
	int	b = 11;

	ft_swap(&a, &b);
	printf("a: %d  b: %d", a, b);
	return (0);
}
