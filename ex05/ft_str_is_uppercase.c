int	ft_char_is_uppercase(const char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_str_is_uppercase(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_uppercase(str[i]))
			return (0);
		++i;
	}
	return (1);
}
