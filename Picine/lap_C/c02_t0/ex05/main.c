#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char	*s1 = "34214dD";
	char	*s2 = "dfjkla";
	char	*s3 = "DKFJSD";
	char	*s4 = "";

	printf("%s : %d\n", s1, ft_str_is_uppercase(s1));	
	printf("%s : %d\n", s2, ft_str_is_uppercase(s2));	
	printf("%s : %d\n", s3, ft_str_is_uppercase(s3));	
	printf("%s : %d\n", s4, ft_str_is_uppercase(s4));
	return (0);
}
