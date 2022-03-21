#include <stdio.h>

int	ft_str_is_lowercase(char *str);
int	main(void)
{
	char	*s1 = "abcdeFd";
	char	*s2 = "FDFSDFDS";
	char	*s3 = "";
	char	*s4 = "fadsfasd";

	printf("%s : %d\n", s1, ft_str_is_lowercase(s1));
	printf("%s : %d\n", s2, ft_str_is_lowercase(s2));
	printf("%s : %d\n", s3, ft_str_is_lowercase(s3));
	printf("%s : %d\n", s4, ft_str_is_lowercase(s4));


	return (0);
}
