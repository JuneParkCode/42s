#include <stdlib.h>
#define SIZE_CHAR 1
#define SIZE_INT 4

int	*ft_range(int min, int max)
{
	int	size;
	int	*arr;
	int	i;

	size = max - min;
	arr = malloc(size * SIZE_INT);
	i = 0;
	while (i < size)
		arr[i++] = min++;
	return (arr);
}
