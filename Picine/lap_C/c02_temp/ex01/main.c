#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	dest[30];
	char	dest2[30];
	char	*src = "Hello World";

	for (int i = 0; i < 30; ++i)
	{
		dest[i] = 9;
		dest2[i] = 9;
	}
	strncpy(dest2, src, 20);
	printf("strncpy :%s\n", dest2);
	ft_strncpy(dest, src, 20);
	printf("mine : %s\n", dest);
	for (int i = 0; i < 30; ++i)
	{
		printf("%d ", dest2[i]);
	}
	printf("\nmine\n");
	for (int i = 0; i < 30; ++i)
	{
		printf("%d ", dest[i]);
	}
	return (0);
}
