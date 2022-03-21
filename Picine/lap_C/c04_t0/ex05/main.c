#include <stdio.h>
#include <limits.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char	*t1 = "31";
	char	*t2 = "\r\n\t\v\f -+-+--123400123";
	char	*t3 = "-++-a123";
	char	*t4 = "\r\n\t-+-\r1234a341";
	char	*b1 = "0123456";
	char	*b2 = "-1234";
	char	*b3 = "12334";
	char	*b4 = "1";
	char	*b5 = "";
	printf("%s -> %d\n", t1, ft_atoi_base(t1, b1)); // 22
	printf("%s -> %d\n", t1, ft_atoi_base(t2, b1)); // 7832128
	printf("%s -> %d\n", t1, ft_atoi_base(t2, b2)); // 0
	printf("%s -> %d\n", t2, ft_atoi_base(t2, b3)); // 0
	printf("%s -> %d\n", t2, ft_atoi_base(t2, b4)); // 0
	printf("%s -> %d\n", t2, ft_atoi_base(t2, b5)); // 0
	printf("%s -> %d\n", t3, ft_atoi_base(t3, b1)); // 0
	printf("%s -> %d\n", t4, ft_atoi_base(t4, b1)); // 0
	return (0);
}
