/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:55:21 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 17:17:32 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	isspace(const char c)
{
	const char	*spaces = "\t\n\r\v\f ";

	while (*spaces)
	{
		if (c == *spaces)
			return (1);
		++spaces;
	}
	return (0);
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

static char	char_to_int(const char c)
{
	return (c - '0');
}

long long	ft_atoll(const char *str)
{
	unsigned int	idx_str;
	long long		res;
	long long		prev;
	int				sign;

	idx_str = 0;
	res = 0;
	while (isspace(str[idx_str]))
		++idx_str;
	sign = get_sign(str[idx_str]);
	while (issign(str[idx_str]))
			++idx_str;
	while (ft_isdigit(str[idx_str]))
	{
		prev = res;
		res = res * 10 + sign * char_to_int(str[idx_str]);
		++idx_str;
	}
	return (res);
}
