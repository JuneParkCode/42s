/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:07:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 01:07:04 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	isspace(const char c)
{
	const char *whitespaces = "\t\n\v\f\r ";
	
	while (*whitespaces)
	{
		if (*whitespaces == c)
			return (1);
		++whitespaces;
	}
	return (!c);
}

static int	issign(const char c)
{
	return (c == '-' || c == '+');
}

static int	get_sign(const char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

static int	isdigit(const char c)
{
	return ('0' <= c && c <= '9');
}

/* Function		:	ft_atoi
 * Description	:	 convert the initial portion of the string pointed
 * 					to by str to int respresntation
 * Param		
 * 			str	:	string to convert
 * Return Value	:	!0 	: converted number
 * 					0 	: can not convert or number is zero
 */
int	ft_atoi(const char *str)
{
	size_t	idx_str;
	size_t	res;
	int		sign;

	idx_str = 0;
	res = 0;
	while (isspace(str[idx_str]))
		++idx_str;
	if (issign(str[idx_str]))
		sign = get_sign(str[idx_str++]);
	while (isdigit(str[idx_str]))
	{
		res = res * 10 + (str[idx_str] - '0');
		++idx_str;
	}
	return (sign * res);
}
