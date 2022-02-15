#include "ft_boolean.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool	ft_is_even(int nbr)
{
	return (EVEN(nbr) ? TRUE : FALSE);
}

int	main(void)
{
	if (ft_is_even(21))
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (0);
}