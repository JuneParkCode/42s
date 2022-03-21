#include <string.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	const int SIZE = 123;
	char	*s = "hello worlds, Good Bye!, Hello!";
	char	test[SIZE];
	int	i;
	int	length;

	i = 0;
	length = strlen(s);
	ft_print_memory(s, strlen(s));
	while (i < length && s[i] != '\0')
	{
		test[i] = s[i];
		++i;
	}
	while (i < SIZE)
	{
		test[i] = i;
		++i;
	}
	ft_print_memory(test, SIZE);
	return (0);
}
