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

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

t_rules	*get_rule(char *rule_str)
{
	int		size;
	int		len_str;
	t_rules	*my_rule;

	my_rule = malloc(sizeof(my_rule));
	if (!my_rule)
		return ;
	len_str = ft_strlen(rule_str);
	my_rule -> size = ft_atoi(rule_str, len_str - 3);
	my_rule -> empty = rule_str[len_str - 3];
	my_rule -> obstacle = rule_str[len_str - 2];
	my_rule -> full = rule_str[len_str - 1];
	if (my_rule -> empty == my_rule -> obstacle || 
			my_rule -> empty == my_rule -> full ||
			my_rule -> full == my_rule -> obstacle)
		return (0);
	my_rule -> result = 0;
	return (my_rule);
}

int	is_valid_char(char c, t_rules my_rule)
{
	return (c == my_rule.empty || c == my_rule.obstacle || c == my_rule.full);
}

int	is_line_valid(char *str, t_rules my_rule)
{
	long long	idx_str;

	idx_str = 0;
	while (str[idx_str])
		if (!is_valid_char(str[idx_str++], my_rule))
			return (0);
	return (my_rule.size == ft_strlen(str));
}

int	is_valid_input(char **strs)
{
	long long	idx_strs;
	t_rules		*rules;

	idx_strs = 1;
	if (strs[0] == 0)
		return (0);
	rules = get_rule(strs[0]);
	if (!rules)
		return (0);
	while (strs[idx_strs])
	{
		if (!is_line_valid(strs[idx_strs++], *rules))
		{
			free(rules);
			return (0);
		}
	}
	free(rules);
	return (1);
}
