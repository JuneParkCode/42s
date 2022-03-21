#include <stdio.h>

void	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char *s1 = "Hello World";
	char s2[100];

	ft_strcpy(s2, s1);
	printf("%s", s2);
	return (0);
}
