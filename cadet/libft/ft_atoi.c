/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:07:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 19:38:36 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(const char c)
{
	return (c < 32 || c == 127);
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
	unsigned int	idx_str;
	unsigned int	res;
	int		sign;

	idx_str = 0;
	res = 0;
	while (isspace(str[idx_str]))
		++idx_str;
	if (issign(str[idx_str]))
		sign = get_sign(str[idx_str++]);
	while (ft_isdigit(str[idx_str]))
	{
		res = res * 10 + (str[idx_str] - '0');
		++idx_str;
	}
	return (sign * res);
}

