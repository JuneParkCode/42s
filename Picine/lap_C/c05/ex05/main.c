#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb);
int	main(void)
{
	for (int i = -3; i < 100; ++i)
	{
		printf("%d : %d\n",i, ft_sqrt(i));
	}
	printf("%d : %d\n", INT_MAX, ft_sqrt(INT_MAX));
	return (0);
}
