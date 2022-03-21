#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	dest[30];
	char	*src = "Hello World";
	
	ft_strncpy(dest, src, 5);
	printf("%s", dest);
	return (0);
}
