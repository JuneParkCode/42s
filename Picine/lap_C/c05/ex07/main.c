#include <stdio.h>

int	ft_find_next_prime(int nb);
int	main(void)
{
	for (int i = -10; i < 100; i++)
		printf("%d -> %d\n",i, ft_find_next_prime(i));
	return (0);
}
