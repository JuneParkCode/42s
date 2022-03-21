#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char	*s1 = "fjklafds";
	char	*s2 = "";
	char	s3[] = {1,2,5,'a','b','c','\0'};

	printf("%s : %d\n", s1, ft_str_is_printable(s1));
	printf("%s : %d\n", s2, ft_str_is_printable(s2));
	printf("%s : %d\n", s3, ft_str_is_printable(s3));
	
	return (0);
}
