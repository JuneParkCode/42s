/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:41:39 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/29 19:44:28 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	convert_char_to_int(const char c)
{
	return (c - '0');
}

long long	atoll(const char *str)
{
	long long	result;
	int			idx;

	idx = 0;
	result = 0;
	while (str + idx)
	{
		result *= 10;
		result += convert_char_to_int(str[idx]);
		++idx;
	}
	return (result);
}
