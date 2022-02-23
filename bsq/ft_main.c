/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:21:35 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 19:59:32 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	free_lines(char **strs)
{
	int	idx;

	idx = 0;
	while (strs[idx])
	{
		free(strs[idx]);
		idx++;
	}
	free(strs[idx]);
	free(strs);
}

int	do_program(char **input)
{
	t_rules	*rule;
	int		**map;

	if (!is_valid_input(input))
		return (1);
	rule = get_rule(input[0]);
	map = make_map(input, rule);
	find_largest_square(map, rule);
	make_result_map(input, map, rule);
	print_result(input);
	free_lines(input);
	free_map(map);
	free(rule);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**input;
	int		**map;
	t_rules	*rule;
	int		idx_arg;

	idx_arg = 1;
	if (argc == 1)
	{
		input = get_stdin();
		return (do_program(input));
	}
	else
	{
		while (idx_arg < argc)
		{
			input = read_file(argv[idx_arg++]);
			do_program(input);
		}
	}
	return (0);
}
