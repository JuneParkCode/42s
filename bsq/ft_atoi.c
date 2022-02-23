int	is_number(char c)
{
	return ('0' <= c && c <= '9');
}

int ft_atoi(char *str, int len)
{
	int	idx;
	int	res;

	idx = 0;
	res = 0;
	while (idx < len)
	{
		if (!is_number(str[idx]))
			return (0);
		res = res * 10 + str[idx] - '0';
		++idx;
	}
	return (res);
}