#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*s1 = "Hello World";
	char	*s2 = "Hello World";
	char	*s3 = "HelloWorld";
	char	*s4 = "";
	char	*s5 = "Hello Wolrd 42 Seoul";

	printf("strcmp : %d\nft_strcmp : %d\n",strcmp(s1,s2), ft_strcmp(s1,s2));
	printf("strcmp : %d\nft_strcmp : %d\n",strcmp(s1,s3), ft_strcmp(s1,s3));
	printf("strcmp : %d\nft_strcmp : %d\n",strcmp(s1,s4), ft_strcmp(s1,s4));
	printf("strcmp : %d\nft_strcmp : %d\n",strcmp(s1,s5), ft_strcmp(s1,s5));
	printf("strcmp : %d\nft_strcmp : %d\n",strcmp(s4,s1), ft_strcmp(s4,s1));
	
	return (0);
}

