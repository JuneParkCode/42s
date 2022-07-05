/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:21:35 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/05 14:03:40 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void	test_read_function(t_map_info *map_info)
{
	ft_printf("TEST PRINTS\n");
	for (int r = 0; r < map_info->row; ++r)
	{
		for (int c = 0; c < map_info->col; ++c)
		{
			ft_printf("%d ", map_info->data[r][c]);
		}
		ft_printf("\n");
	}
}

t_status	run_fdf(const char *file_name)
{
	t_map_info	*map_info;

	if (read_and_check_file(file_name, &map_info) == FAILED)
		return (FAILED);
	test_read_function(map_info);
	return (SUCCESS);
}
