int	ft_char_is_lowercase(const char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_lowercase(str[i]))
			return (0);
		++i;
	}
	return (1);
}
