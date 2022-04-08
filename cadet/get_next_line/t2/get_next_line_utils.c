
#include <stdlib.h>
#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	const size_t	len_src = ft_strlen(src);
	size_t			idx_byte;

	idx_byte = 0;
	if (dst_size == 0)
		return (len_src);
	while (idx_byte + 1 < dst_size && src[idx_byte])
	{
		dst[idx_byte] = src[idx_byte];
		++idx_byte;
	}
	dst[idx_byte] = 0;
	return (len_src);
}

char	*ft_strdup(const char *s1)
{
	const size_t	len_str = ft_strlen(s1);
	char			*res;

	res = malloc((len_str + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len_str + 1);
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);
	char			*res;

	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len_s1 + 1);
	ft_strlcpy(res + len_s1, s2, len_s2 + 1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	idx_str;

	idx_str = 0;
	while (s[idx_str] && (char) c != (char) s[idx_str])
		++idx_str;
	if (s[idx_str] || c == 0)
		return ((char *)(s + idx_str));
	else
		return (NULL);
}
