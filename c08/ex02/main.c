#include "ft_abs.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("%ld %d %d\n", ABS(-2147483648), ABS(INT_MAX), ABS(0));
}