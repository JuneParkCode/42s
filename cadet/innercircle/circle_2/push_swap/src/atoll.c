/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:55:21 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/02 13:57:20 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

long long	atoll(const char *str)
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
		res = res * 10 + sign * (str[idx_str] - '0');
		++idx_str;
	}
	return (res);
}
