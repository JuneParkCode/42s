/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sunjpar@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:06:04 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/05 19:06:06 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alphanumeric(const char c)
{
	return ((
			('a' <= c && c <= 'z')
			|| ('A' <= c && c <= 'Z')
			|| ('0' <= c && c <= '9')
		));
}

int	ft_str_is_alphanumeric(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_alphanumeric(str[i]))
			return (i);
		++i;
	}
	return (i);
}

void	ft_transform(char *str, int length)
{
	int		i;
	char	c;

	if ('a' <= str[0] && str[0] <= 'z')
		str[0] += 'A' - 'a';
	i = 1;
	while (i < length)
	{
		c = str[i];
		if ('A' <= c && c <= 'Z')
			str[i] += 'a' - 'A';
		++i;
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*search;
	int		w_start;
	int		w_end;
	int		i;

	search = str;
	i = 0;
	while (str[i] != '\0')
	{
		search = &str[i];
		w_start = i;
		w_end = w_start + ft_str_is_alphanumeric(search);
		ft_transform(search, w_end - w_start + 1);
		i = w_end + 1;
		if (str[w_end] == '\0')
			break ;
	}
	return (str);
}
