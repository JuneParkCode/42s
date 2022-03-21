#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char	*s1 = "42 SEOUL!";
	char	*s2 = "";
	const int	S1 = 30;
	char	dest[S1] = "OKOK";
	char	dest_[S1] = "OKOK";
	const int	S2 = 20;
	char	dest2[S2] = "012345678";
	char	dest2_[S2] = "012345678";
	char	dest3[S2];
	char	dest3_[S2];
	for (int i = 0; i < S2; ++i)
	{
		printf("%d : %d | %d\n",i ,dest3[i], dest3_[i]);
	}
	ft_strncat(dest, s1, 9);
	strncat(dest_, s1, 9);
	ft_strncat(dest2, s1, 9);
	strncat(dest2_, s1, 9);
	ft_strncat(dest3, s2, 10);
	strncat(dest3_, s2, 10);
	printf("%s + %s\nf:%s\ns:%s\n","OKOK",s1,dest, dest_);
	printf("%s + %s\nf:%s\ns:%s\n","012345678",s1,dest2, dest2_);
	printf("%s + %s\nf:%s\ns:%s\n","",s2,dest3, dest3_);
	for (int i = 0; i < S2; ++i)
	{
		printf("%d : %d | %d\n",i, dest3[i], dest3_[i]);
	}
	return (0);
}
