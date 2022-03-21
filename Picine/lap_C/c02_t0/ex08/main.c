#include <stdio.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	s1[] = {'a','b','D','1',';','s',0};
	char	s2[] = {0};
	
	ft_strlowcase(s1);
	ft_strlowcase(s2);
	printf("%s\n", s1);
	printf("%s\n", s2);
	return (0);
}
