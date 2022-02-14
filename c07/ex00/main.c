#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*src = "hello World";
	char	*src2 = "123123";

	printf("%s\n", ft_strdup(src));
	printf("%s\n", ft_strdup(src2));
	return (0);
}
