#include <stdio.h>
int ft_recursive_power(int nb, int power);
int	main(void)
{
	for (int i=-1; i<9; i++)
	{
		for(int j = -1; j < 9; j++)
		{
			printf("%d^%d = %d\n",i,j,ft_recursive_power(i,j));
		}
	}
	return (0);
}
