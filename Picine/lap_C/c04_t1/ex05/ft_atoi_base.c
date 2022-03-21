/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:46:44 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/10 13:06:28 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	char	*s;

	s = "\t\n\v\f\r ";
	while (*s)
		if (c == *s++)
			return (1);
	return (0);
}

int	ft_get_sign(char **str)
{
	int	count;

	count = 0;
	while (**str == '+' || **str == '-')
	{	
		count += (**str == '-');
		(*str)++;
	}
	return (count % 2 == 1);
}

int	ft_valid_base(const char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (str[i] == '-' || str[i] == '+')
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			++j;
		}
		++i;
	}
	return (i > 1);
}

int	ft_get_base_idx(const char c, const char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (base[idx] == c)
			return (idx);
		++idx;
	}
	return (idx);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	n;
	int	len_base;
	int	sign;

	len_base = 0;
	result = 0;
	if (!ft_valid_base(base))
		return (0);
	while (ft_isspace(*str))
		++str;
	while (base[len_base])
		++len_base;
	sign = ft_get_sign(&str);
	while (*str)
	{
		n = ft_get_base_idx(*str++, base);
		if (n == len_base)
			break ;
		result = result * len_base + n % len_base;
	}
	if (sign)
		return (-result);
	return (result);
}
