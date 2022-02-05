#include <stdio.h>
#include <string.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	s1[1000];
	
	strcpy(s1, "salut, comment tu VAS ? 42mots quarante-deux; cinquante+et+un");
	ft_strcapitalize(s1);
	printf("%s",s1);
	return (0);
}
