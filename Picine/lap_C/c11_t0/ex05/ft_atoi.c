/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:28:11 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 15:16:29 by sungjpar         ###   ########.fr       */
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

int	ft_get_sign(char *str, int *i)
{
	int	count;

	count = 0;
	while (str[*i] == '+' || str[*i] == '-')
	{	
		count += (str[*i] == '-');
		*i += 1;
	}
	if (count % 2 == 1)
		return (-1);
	return (1);
}

int	ft_is_number(const char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		++i;
	sign = ft_get_sign(str, &i);
	while (ft_is_number(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (sign * result);
}
