unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;
	
	i = 0;
	while (src[i] != '\0' && i <(size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
