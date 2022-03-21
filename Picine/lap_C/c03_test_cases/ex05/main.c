#include <string.h>
#include <stdio.h>

int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	const int S1     = 30;
	const int S2     = 30;
	char	*src1 = "HELELEL";
	char	*src2 = "FJDSJLKFHLJKDSHFLJKDSHLFKJ";
	char	*src3 = "";
	char	dest[S1] = "OKOK";
	char	dest_[S1] = "OKOK";
	char	dest2[S2] = "OKOK";
	char	dest2_[S2] = "OKOK";
	char	dest3[S2] = "";
	char	dest3_[S2] = "";
	char	dest4[S2] = "OKOK";
	char	dest4_[S2] = "OKOK";
	char	dest5[S2] = "OKOK";
	char	dest5_[S2] = "OKOK";

	int	r1 = ft_strlcat(dest, src1, S1);
	int	r1_ = strlcat(dest_, src1, S1);
	int	r2 = ft_strlcat(dest2, src2, S1);
	int	r2_ = strlcat(dest2_, src2, S1);
	int	r3 = ft_strlcat(dest3, src1, S1);
	int	r3_ = strlcat(dest3_, src1, S1);
	int	r4 = strlcat(dest4, src3, S1);
	int	r4_ = strlcat(dest4_, src3, S1);
	int	r5 = strlcat(dest5_, src3, S1);
	int	r5_ = strlcat(dest5_, src3, S1);
	printf("%s + %s?\nf:%s\ns:%s\nreturn number\nf:%d\ns:%d\n", "OKOK", src1, dest, dest_, r1, r1_); 
	printf("%s + %s?\nf:%s\ns:%s\nreturn number\nf:%d\ns:%d\n", "OKOK", src1, dest2, dest2_, r2, r2_); 
	printf("%s + %s?\nf:%s\ns:%s\nreturn number\nf:%d\ns:%d\n", "OKOK", src1, dest3, dest3_, r3, r3_); 
	printf("%s + %s?\nf:%s\ns:%s\nreturn number\nf:%d\ns:%d\n", "OKOK", src1, dest4, dest4_, r4, r4_); 
	printf("%s + %s?\nf:%s\ns:%s\nreturn number\nf:%d\ns:%d\n", "OKOK", src1, dest5, dest5_, r5, r5_); 
	return (0);
}
