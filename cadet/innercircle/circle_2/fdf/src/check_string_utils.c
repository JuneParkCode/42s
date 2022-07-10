/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:36:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 18:13:42 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static t_bool	is_valid_number(const char *str)
{
	long long	atoll_res;

	atoll_res = ft_atoll(str);
	if (atoll_res < INT_MIN || atoll_res > INT_MAX)
		return (FALSE);
	return (TRUE);
}

static t_bool	is_valid_string(char **strs)
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

t_bool	is_valid_map_data(char **string_map_data)
{
	int		idx;
	char	**splited_strings;
	char	*trimmed_string;

	if (string_map_data == NULL)
		return (FALSE);
	idx = 0;
	while (string_map_data[idx] != NULL)
	{
		trimmed_string = ft_strtrim(string_map_data[idx], "\n ");
		splited_strings = ft_split(trimmed_string, ' ');
		if (is_valid_string(splited_strings) == FALSE)
		{
			free_splited_string(splited_strings);
			free(trimmed_string);
			return (FALSE);
		}
		free_splited_string(splited_strings);
		free(trimmed_string);
		++idx;
	}
	return (TRUE);
}
