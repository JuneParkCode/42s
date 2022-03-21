int	ft_char_is_alpha(const char c)
{
	return ((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z'));
}

int	ft_str_is_alpha(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_alpha(str[i++]))
			return (0);
	}
	return (1);
}
