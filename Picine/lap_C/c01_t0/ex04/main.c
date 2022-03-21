#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int a = 100;
	int b = 13;
	printf("%d, %d",a, b);
	ft_ultimate_div_mod(&a,&b);
	printf("div: %d, mod :%d",a,b);
}
