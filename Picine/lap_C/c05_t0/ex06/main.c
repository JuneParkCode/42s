#include <stdio.h>
#include <limits.h>

int	ft_is_prime(int nb);
int	main(void)
{
	for (int i = -10; i < 120; ++i)
		printf("%d -> %d\n",i, ft_is_prime(i));
	printf("%d -> %d\n", INT_MAX, ft_is_prime(INT_MAX));
	return (0);
}
