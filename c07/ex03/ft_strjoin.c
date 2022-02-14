#include <stdlib.h>
#include <stdio.h>
#define SIZE_CHAR 1
#define SIZE_INT 4

unsigned int ft_strlen(const char *str)
{
	unsigned int length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

int ft_get_total_length(int total_length, int size, char **strs)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		++i;
	}
	return (total_length);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	idx_res;
	int	idx_strs;
	int	total_length;
	char	*result;
	char	*cur;

	if (!size)
	{
		result = malloc(1 * SIZE_CHAR);
		result[0] = 0;
		return (result);
	}
	total_length = (size - 1) * ft_strlen(sep);
	total_length = ft_get_total_length(total_length, size, strs) + 1;
	result = malloc((total_length) * SIZE_CHAR);
	cur = result;
	idx_strs = 0;
	idx_res = 0;
	while (idx_strs < size)
	{
		ft_strcpy(cur, strs[idx_strs]);
		cur += ft_strlen(strs[idx_strs]);
		if (cur == result + total_length - 1)
			break;
		ft_strcpy(cur, sep);
		cur += ft_strlen(sep);
		idx_strs++;
		idx_res++;
	}
	result[total_length - 1] = 0;
	return (result);
}

int main(void)
{
	char	*strs[] = {
		"01234567",
		"hijklmnop",
		"qrstuwxyz"
	};

	printf("\nTEST1 : %s\n", strs[0]);
	char	*sep = "| |";
	char	*res = ft_strjoin(3, strs, sep);

	printf("%s", res);
	free(res);
	printf("\nTEST2 : %s\n", strs[0]);
	printf("res : %d\n", ft_strlen(res));
	printf("string : %d\n",ft_strlen("abcdef"));
	return (0);
}