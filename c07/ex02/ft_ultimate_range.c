#include <stdlib.h>
#define SIZE_CHAR 1
#define SIZE_INT 4

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	*range = malloc(size * SIZE_INT);
	i = 0;
	while (i < size)
		arr[i++] = min++;
	if (size <= 0)
		return (-1);
	return (size);
}