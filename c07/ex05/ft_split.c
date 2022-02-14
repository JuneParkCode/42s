int	ft_is_split(char c, char *split)
{
	while (*split != c)
		++split;
	return (*split == c);
}

int	ft_get_word_num(char *str, char *charset)
{
	int num;
	int	i;
	int	flag;

	num = 0;
	i = 0;
	flag = 1;
	while (str[i])
	{
		if (ft_is_split(str[i]) && !flag)
		{
			num++;
			flag = 1;
		}
		else
			flag = 0;
	}
	return (num + 1);
}

void	ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while(s2[i] && i < n)
	{
		s1[i] = s2[i];
		++i;
	}
	while (i < n)
		s1[i++] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	*word;
	char	**result;
	int		len_word;
	int		num_word;
	int		idx;

	num_word = ft_get_word_num(str, charset);
	result = (char **) malloc(sizeof(char *) * (num_word + 1));
	idx = 0;
	while (*str)
	{
		if (ft_is_split(*str))
		{
			word = (char *) malloc(sizeof(char) * (len_word + 1));
			ft_strncpy(word, original, len_word);
			result[idx++]
		}
	}
}
