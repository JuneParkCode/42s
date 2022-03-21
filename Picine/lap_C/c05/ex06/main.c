#include <stdio.h>

int	ft_is_prime(int nb);
int	main(void)
{
	for (int i = -10; i < 120; ++i)
		printf("%d -> %d\n",i, ft_is_prime(i));
	return (0);
}
