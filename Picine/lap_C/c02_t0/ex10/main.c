#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int main(void)
{
	const int	size = 20;
	char		dest[20];
	char		*s1 = "Hello World";
	char		*s2 = "The strlcpy() and strlcat() functions copy and concatenate strings respectively. ";
	unsigned int	n;

	n = strlcpy(dest, s1, size);
	printf("%s : %d\n", dest, n);
	n = ft_strlcpy(dest, s1, size);
	printf("%s : %d\n", dest, n);

	n = strlcpy(dest, s2, size);
	printf("%s : %d\n", dest, n);
	n = ft_strlcpy(dest, s2, size);
	printf("%s : %d\n", dest, n);
	
	return (0);
}
