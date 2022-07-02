/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:57:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/02 20:22:41 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/push_swap.h"

#define INT_MIN -2147483648
#define INT_MAX 2147483647

static t_bool	is_all_digit(const char *str)
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

static t_bool	is_valid_number(const char *str)
{
	long long	atoll_res;

	if (ft_strlen(str) == 0
		|| ft_strlen(str) >= 15
		|| is_all_digit(str) == FALSE)
		return (FALSE);
	atoll_res = atoll(str);
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

static void	push_strings_to_deque(char **strs, t_deque *dq)
{
	int	idx;

	idx = 0;
	while (strs[idx] != NULL)
	{
		dq->push_front(dq, ft_atoi(strs[idx]));
		++idx;
	}
}

t_bool	get_input(const int argc, char **argv, t_deque *dq)
{
	char	**strs;
	int		arg;
	t_bool	result;
	int		idx;

	arg = 1;
	result = TRUE;
	while (arg < argc && result)
	{
		if (ft_strlen(argv[arg]) == 0)
			return (FALSE);
		strs = ft_split(argv[arg], ' ');
		result = is_valid_string(strs);
		if (result == TRUE)
			push_strings_to_deque(strs, dq);
		idx = 0;
		while (strs != NULL && *(strs + idx) != NULL)
			free(*(strs + (idx++)));
		if (strs != NULL)
			free(strs);
		++arg;
	}
	return (result);
}
