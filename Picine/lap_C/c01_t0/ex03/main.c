#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	a = 100;
	int	b = 13;
	int	div;
	int	mod;
	ft_div_mod(a,b,&div,&mod);
	printf("%d, %d : %d, %d",a,b,div, mod );
	return 0;
}
