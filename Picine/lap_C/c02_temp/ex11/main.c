#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
//	char	*s1 = "Coucou\ntu vas bien ?";
	char	s2[1000];
	int		i = 0;
	int		j = -128;
	printf("\n %d \n", (unsigned char) j);
	while (i < 256)
	{
		if (j == 0)
		{
			s2[i++] = '-';
			++j;
			continue;
		}
		s2[i] = j;
		++j;
		++i;
	}
	s2[256] = 0;
//	ft_putstr_non_printable(s1);
	printf("\n===NEXT===\n");
	ft_putstr_non_printable(s2);
	return (0);
}
