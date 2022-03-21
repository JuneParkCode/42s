int	ft_char_is_printable(const char c)
{
	return (32 <= c && c < 127);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_printable(str[i]))
			return (0);
		++i;
	}
	return (1);
}
