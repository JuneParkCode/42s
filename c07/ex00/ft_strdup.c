#include <stdlib.h>
#define SIZE_CHAR 1
#define SIZE_INT 4

unsigned int	ft_strlen(char *str)
{
	unsigned int	length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *) malloc((ft_strlen(src) + 1) * SIZE_CHAR);
	while (src[i])
	{
		res[i] = src[i];
		++i;
	}
	res[i] = 0;
	return (res);
}
