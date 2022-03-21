#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	*s1 = "Coucou\ntu vas bien ?";
	
	ft_putstr_non_printable(s1);
	return (0);
}
