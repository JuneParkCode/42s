int	ft_char_is_upcase(const char c)
{
	return ('A' <= c && c <= 'Z');
}
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_upcase(str[i]))
			str[i] += 'a' - 'A';
		++i;
	}
	return (str);
}
