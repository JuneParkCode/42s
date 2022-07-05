/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:36:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/05 11:37:45 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_bool	is_all_digit(const char *str)
{
	int	idx;

	idx = (str[0] == '+' || str[0] == '-');
	while (str[idx])
	{
		if (ft_isdigit(str[idx]) == FALSE)
			return (FALSE);
		++idx;
	}
	return (TRUE);
}

t_bool	is_valid_number(const char *str)
{
	const int	int_word_length_max = 12;
	long long	atoll_res;

	if (ft_strlen(str) == 0
		|| ft_strlen(str) >= int_word_length_max
		|| is_all_digit(str) == FALSE)
		return (FALSE);
	atoll_res = ft_atoll(str);
	if (atoll_res < INT_MIN || atoll_res > INT_MAX)
		return (FALSE);
	return (TRUE);
}

t_bool	is_valid_string(char **strs)
{
	int	idx;

	if (strs == NULL)
		return (FALSE);
	idx = 0;
	while (strs[idx] != NULL)
	{
		if (is_valid_number(strs[idx]) == FALSE)
			return (FALSE);
		++idx;
	}
	return (TRUE);
}


