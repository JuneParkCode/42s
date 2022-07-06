/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:57:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/06 09:38:32 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static void	free_splited_string(char **splited_string)
{
	int	idx;

	idx = 0;
	while (splited_string != NULL && splited_string[idx] != NULL)
		free(splited_string[idx++]);
	if (splited_string != NULL)
		free(splited_string);
}

t_status	get_input(const int argc, char **argv, t_deque *dq)
{
	char	**splited_string;
	int		arg;

	arg = 1;
	while (arg < argc)
	{
		if (ft_strlen(argv[arg]) == 0)
			return (FAILED);
		splited_string = ft_split(argv[arg], ' ');
		if (is_valid_string(splited_string) == TRUE)
		{
			push_strings_to_deque(splited_string, dq);
			free_splited_string(splited_string);
		}
		else
		{
			free_splited_string(splited_string);
			return (FAILED);
		}
		++arg;
	}
	return (SUCCESS);
}
