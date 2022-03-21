#include <stdio.h>

int ft_iterative_factorial(int nb);
int	main(void)
{
	printf("%d : %d\n", 9*8*7*6*5*4*3*2*1,ft_iterative_factorial(9));
	printf("%d : %d\n", 8*7*6*5*4*3*2*1,ft_iterative_factorial(8));
	printf("%d : %d\n", 7*6*5*4*3*2*1,ft_iterative_factorial(7));
	printf("%d : %d", 1,ft_iterative_factorial(1));
	printf("%d : %d", 1,ft_iterative_factorial(0));
	return (0);
}
