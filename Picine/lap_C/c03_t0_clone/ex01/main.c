#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	*s1 = "Hello World";
	char	*s2 = "Hello World";
	char	*s3 = "HelloWorld";
	char	*s4 = "";
	char	*s5 = "Hello Wolrd 42 Seoul";
	// S1 - S2 == 0
	printf("strncmp : %d\nft_strncmp : %d\n\n",strncmp(s1,s2, 3), ft_strncmp(s1,s2, 3));
	// S1 - S3 == 0 (5byte, "Hello" == "Hello") case : s1,s2 length > byte
	printf("strncmp : %d\nft_strncmp : %d\n\n",strncmp(s1,s3, 5), ft_strncmp(s1,s3, 5));
	// S1 - S4 > 0  ('H' > 0) case : empty s1
	printf("strncmp : %d\nft_strncmp : %d\n\n",strncmp(s1,s4, 3), ft_strncmp(s1,s4, 3));
	// S5 - S1 < 0  ( 0  < ' ') case : s1 length < byte 
	printf("strncmp : %d\nft_strncmp : %d\n\n",strncmp(s5,s1, 12), ft_strncmp(s5,s1, 12));
	// S4 - S1 < 0 ( 0 < 'H') case : empty s2
	printf("strncmp : %d\nft_strncmp : %d\n\n",strncmp(s4,s1, 3), ft_strncmp(s4,s1, 3));
	// S2 - S3 == 0 (n == 0) case : s1, s2 length > byte & s2 != s1
	printf("strncmp : %d\nft_strncmp : %d\n\n",strncmp(s2,s3, 0), ft_strncmp(s2,s3, 0));
	
	return (0);
}

