int	ft_char_is_numeric(const char c)
{
	return (c >= '0' && c <= '9');
}
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_numeric(str[i]))
			return (0);
		++i;
	}
	return (1);
}
