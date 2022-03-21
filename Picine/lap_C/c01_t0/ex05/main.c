#include <stdio.h>
void	ft_putstr(char *str);
int	main(void)
{
	char *str = "Hello World";
	char *str2 = "";

	ft_putstr(str);
	printf("\n");
	ft_putstr(str2);
	printf("\n");
}
