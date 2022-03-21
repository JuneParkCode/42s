#include <stdio.h>
int ft_recursive_factorial(int nb);
int	main(void)
{
	for (int i = 0; i < 9; ++i)
		printf("%d\n", ft_recursive_factorial(i));
	return (0);
}
