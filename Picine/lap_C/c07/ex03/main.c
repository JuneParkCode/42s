#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char	*ft_strjoin(int size, char **strs, char *s);
int main(void)
{
	char	*strs[] = {
		"01234567",
		"hijklmnop",
		"qrstuwxyz",
		"",
		"abcde",
		"",
		"okok"
	};

	printf("\nTEST1 : %s\n", strs[0]);
	char	*sep = "| |";
	char	*res = ft_strjoin(6, strs, sep);

	printf("%s\n", res);
	printf("res : %lu\n", strlen(res));
	printf("string : %lu\n",strlen("abcdef"));
	free(res);
	return (0);
}
