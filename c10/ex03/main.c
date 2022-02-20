#include <string.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	const int SIZE = 300;
	char	*s = "hello worlds, Good Bye!, Hello!";
	char	test[SIZE];
	int	i;
	int	length;
	int	j;

	i = 0;
	length = strlen(s);
	while (i < length && s[i] != '\0')
	{
		test[i] = s[i];
		++i;
	}
	j = -128;
	while (i < SIZE)
	{
		test[i] = j++;
		++i;
	}
	ft_print_memory(test, SIZE);
	return (0);
}
