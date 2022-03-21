#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	char *str = "1312312adfsdab";
	char *str2 = "abcdef";
	char *str3 = "";

	printf("%s : %d\n", str, ft_str_is_alpha(str));
	printf("%s : %d\n", str2, ft_str_is_alpha(str2));
	printf("%s : %d\n", str3, ft_str_is_alpha(str3));
	
	return (0);
}
