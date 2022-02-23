/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:07:43 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 19:49:53 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#include <stdio.h>

int	is_valid_char(char c, t_rules my_rule)
{
	return (c == my_rule.empty || c == my_rule.obstacle);
}

int	is_line_valid(char *str, t_rules my_rule, int len)
{
	long long	idx_str;

	idx_str = 0;
	while (str[idx_str])
		if (!is_valid_char(str[idx_str++], my_rule))
			return (0);
	return (ft_strlen(str) == len);
}

int	is_valid_input(char **strs)
{
	long long	idx_strs;
	t_rules		*rules;
	int			len;

	idx_strs = 1;
	if (strs[0] == 0)
		return (0);
	rules = get_rule(strs[0]);
	if (!rules)
		return (0);
	len = ft_strlen(strs[1]);
	while (strs[idx_strs])
	{
		if (!is_line_valid(strs[idx_strs++], *rules, len))
		{
			free(rules);
			return (0);
		}
	}
	free(rules);
	return (1);
}
