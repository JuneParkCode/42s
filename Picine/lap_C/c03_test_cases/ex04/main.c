#include <stdio.h>
#include <string.h>

char	*ft_strstr(char	*str, char *to_find);

int	main(void)
{
	char	*s1 = "Hello World~42picine";
	char	*s2 = "or";
	char	*s3 = "";
	char	*s4 =  "Hello World~42picined";
	char	*s5 = "ol";
	printf("origin :%s\nfind:%s\nf:%s\ns:%s\n",s1,s2,ft_strstr(s1,s2), strstr(s1,s2));
	printf("origin :%s\nfind:%s\nf:%s\ns:%s\n",s2,s1,ft_strstr(s2,s1), strstr(s2,s1));
	printf("origin :%s\nfind:%s\nf:%s\ns:%s\n",s1,s3,ft_strstr(s1,s3), strstr(s1,s3));
	printf("origin :%s\nfind:%s\nf:%s\ns:%s\n",s1,s4,ft_strstr(s1,s4), strstr(s1,s4));
	printf("origin :%s\nfind:%s\nf:%s\ns:%s\n",s1,s5,ft_strstr(s1,s5), strstr(s1,s5));
	return (0);
}
