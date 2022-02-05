char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	return (dest);
}
