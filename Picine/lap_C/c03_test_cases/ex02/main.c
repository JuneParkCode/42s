#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

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
	ft_strcat(dest, s1);
	strcat(dest_, s1);
	ft_strcat(dest2, s1);
	strcat(dest2_, s1);
	ft_strcat(dest3, s2);
	strcat(dest3_, s2);
	printf("%s + %s\nf:%s\ns:%s\n","OKOK",s1,dest, dest_);
	printf("%s + %s\nf:%s\ns:%s\n","012345678",s1,dest2, dest2_);
	printf("%s + %s\nf:%s\ns:%s\n","",s1,dest3, dest3_);
	for (int i = 0; i < S2; ++i)
	{
		printf("%d : %d | %d\n",i, dest3[i], dest3_[i]);
	}
	return (0);
}
