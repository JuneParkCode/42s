/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:46:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/09 16:46:30 by sungjpar         ###   ########.fr       */
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

int	ft_is_number(const char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	while (ft_isspace(*str))
		++str;
	sign = ft_get_sign(&str);
	while (ft_is_number(*str))
	{
		result *= 10;
		result += *str - '0';
		++str;
	}
	if (sign)
		return (-result);
	return (result);
}
