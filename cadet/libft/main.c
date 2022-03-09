#include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);


void	do_test_char(int c, int (*f) (int))
{
	printf("%d : %c-> %d\n", c, c, f(c));
}

int	main(void)
{
	printf("isalpha Test'\n");
	for (int i = 0; i < 300; ++i)
	{
		do_test_char(i, ft_isalpha);
	}

	printf("isdigit test\n");
	for (int i = 0; i < 300; ++i)
	{
		do_test_char(i, ft_isdigit);
	}
	
	printf("isalnum test\n");
	for (int i = 0; i < 300; ++i)
	{
		do_test_char(i, ft_isalnum);
	}

	printf("isascii test\n");
	for (int i = 0; i < 300; ++i)
	{
		do_test_char(i, ft_isascii);
	}
}
