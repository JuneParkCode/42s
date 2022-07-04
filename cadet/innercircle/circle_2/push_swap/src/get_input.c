/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:57:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 17:05:06 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static void	free_splited_string(char **strs)
{
	int	idx;

	idx = 0;
	while (strs != NULL && strs[idx] != NULL)
		free(strs[idx++]);
	if (strs != NULL)
		free(strs);
}

t_status	get_input(const int argc, char **argv, t_deque *dq)
{
	char	**strs;
	int		arg;

	arg = 1;
	while (arg < argc)
	{
		if (ft_strlen(argv[arg]) == 0)
			return (FAILED);
		strs = ft_split(argv[arg], ' ');
		if (is_valid_string(strs) == TRUE)
		{
			push_strings_to_deque(strs, dq);
			free_splited_string(strs);
		}
		else
			return (FAILED);
		++arg;
	}
	return (SUCCESS);
}
