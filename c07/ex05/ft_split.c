#include <stdlib.h>

int	ft_is_split(char c, char *split)
{
	while (*split != c && *split)
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
		if (ft_is_split(str[i], charset) && !flag)
		{
			num++;
			flag = 1;
		}
		else
			flag = 0;
		++i;
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
	s1[n] = 0;
}

char	*ft_get_word(char *str, char *charset, int *start)
{
	int		idx_str;
	char	*word;

	idx_str = 0;
	while (!ft_is_split(str[idx_str], charset))
		++(idx_str);
	if (idx_str == 0)
		return (0);
	word = (char *) malloc(sizeof(char) * (idx_str + 1));
	ft_strncpy(word ,str, idx_str);
	*start += idx_str;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		idx_str;
	int		idx_res;
	int		num_word;
	char	*word;
	char	**result;

	idx_str = 0;
	idx_res = 0;
	num_word = ft_get_word_num(str, charset);
	result = (char **) malloc(sizeof(char *) * (num_word + 1));
	while (str[idx_str])
	{
		word = ft_get_word(&str[idx_str], charset, &idx_str);
		if (word)
			result[idx_res++] = word;
		++idx_str;
	}
	result[idx_res] = 0;
	return (result);
}
