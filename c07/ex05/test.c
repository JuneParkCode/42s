#include <stdio.h>

int	main(void)
{
	char	*str = "abcd";
	char	*str2 = str;

	str2++;
	printf("%d", (str2 - str));
	return (0);
}
