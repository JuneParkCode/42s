#include <stdio.h>

int	ft_ultimate_range(int **ptr, int min, int max);
int	main(void)
{
	int	*ptr_1;
	int	**ptr1 = &ptr_1;
	int	*ptr_2;
	int	**ptr2 = &ptr_2;
	int	*ptr_3;
	int	**ptr3 = &ptr_3;
	int	res1 = ft_ultimate_range(ptr1, 1, 10);
	int	res2 = ft_ultimate_range(ptr2, -10, 10);
	int	res3 = ft_ultimate_range(ptr3, -10, 0);
	
	printf("ptr : %p  %p \n", ptr1, ptr2);
	for (int i = 0; i < res1; ++i, ++(*ptr1))
	{
		printf("%d ", **ptr1);
	}
	printf("res : %d\n", res1);

	for (int i = 0; i < res2; ++i, ++(*ptr2))
	{
		printf("%d ", **ptr2);
	}
	printf("res : %d\n", res2);

	for (int i = 0; i < res3; ++i, ++(*ptr3))
	{
		printf("%d ", **ptr3);
	}
	printf("res : %d\n", res3);

	return (0);
}
