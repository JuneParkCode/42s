/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:57:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/29 22:13:47 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/push_swap.h"

static t_bool	is_all_digit(const char *str)
{
	int	idx;

	idx = (str[0] == '+' || str[0] == '-');
	while (str + idx)
	{
		if (ft_isdigit(str[idx]) == FALSE)
			return (FALSE);
		++idx;
	}
	return (TRUE);
}

static t_bool	is_valid_number(const char *str)
{
	int		atoi_res;
	t_bool	result;
	char	*itoa_res;

	if (ft_strlen(str) == 0 || is_all_digit(str) == FALSE)
		return (FALSE);
	atoi_res = ft_atoi(str);
	itoa_res = ft_itoa(atoi_res);
	result = (ft_atoi(itoa_res) == atoi_res);
	free(itoa_res);
	return (result);
}

static t_bool	is_valid_string(char **strs)
{
	int	idx;

	if (strs == NULL)
		return (FALSE);
	idx = 0;
	while (strs + idx)
	{
		if (is_valid_number(strs[idx]) == FALSE)
			return (FALSE);
	}
	return (FALSE);
}

t_bool	is_valid_input(const int argc, char **argv)
{
	char	**strs;
	int		arg;
	t_bool	result;

	arg = 1;
	result = TRUE;
	if (argc <= 1)
		return (FALSE);
	while (arg <= argc && result)
	{
		strs = ft_split(argv[arg], ' ');
		result = is_valid_string(strs);
		while (strs != NULL && *strs)
			free(*(strs++));
		if (strs != NULL)
			free(strs);
		++arg;
	}
	return (result);
}
