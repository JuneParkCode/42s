#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	*arr1;
	int *arr2;

	arr1 = ft_range(1,6);
	for (int i = 0; i < 5; ++i)
		printf("%d ", arr1[i]);
	printf("\n");
	arr2 = ft_range(11,21);
	for (int i = 0; i < 10; ++i)
		printf("%d ", arr2[i]);
	printf("\n");
	return (0);
}
