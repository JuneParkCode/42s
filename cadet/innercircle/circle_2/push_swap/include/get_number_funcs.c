/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:10:50 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/29 22:45:09 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/push_swap.h"

t_item	*convert_inputs_to_numbers(int argc, char *argv[], int *size)
{
	t_item	**result;
	char	**strs;
	int		idx;

	idx = 1;
	*size = 0;
	result = malloc(sizeof(t_item *) * (argc + 1));
	while (idx <= argc)
	{
		strs = ft_split(argv[idx], ' ');

		while (*strs)
			free(*(strs++));
		free(strs);
	}
	numbers[argc] = NULL;
}
