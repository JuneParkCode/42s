#include <stdio.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char	s1[] = {'a','b','D','1',';','s',0};
	char	s2[] = {0};
	
	ft_strupcase(s1);
	ft_strupcase(s2);
	printf("%s\n", s1);
	printf("%s\n", s2);
	return (0);
}
