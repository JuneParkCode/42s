#include <stdio.h>
#include "ft_rev_int_tab.c"

int	main(void)
{
	int	t1[10] = {0,1,2,3,4,5,6,7,8,9};
	int *t2;
	int t3[1] = {1};
	int t4[2] = {1,2};
	
	ft_rev_int_tab(t1, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", t1[i]);
	}
	printf("TEST 1 FIN\n");
	ft_rev_int_tab(t2,0);
	printf("TEST 2 FIN\n");
	ft_rev_int_tab(t1,-1);
	printf("TEST 3 FIN\n");
	ft_rev_int_tab(t3,1);
	for (int i = 0; i < 1; ++i)
	{
		printf("%d ", t3[i]);
	}
	printf("TEST 4 FIN\n");
	ft_rev_int_tab(t4,2);
	for (int i = 0; i < 2; ++i)
	{
		printf("%d ", t4[i]);
	}
	printf("TEST 5 FIN\n");
	printf("\n");
	printf("\n");
}
