
#include "libft.h"

void	f_print_nbr(void *content)
{
	int	*n;
	
	n = (int *) content;
	ft_putnbr_fd(*n, 1);
	ft_putchar_fd('\n', 1);
}

void	f_print_str(void *content)
{
	char	*str;

	str = (char *)content;
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}

void	f_print_chr(void *content)
{
	char	*c;
	
	c = (char *)content;
	ft_putchar_fd(*c, 1);
	ft_putchar_fd('\n', 1);
}