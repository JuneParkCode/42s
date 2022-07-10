/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:51:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 17:51:34 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_screen(t_vars *vars)
{
	const t_screen_data	screen_datas = vars->screen_data;
	t_pixel				*pixel;
	int					row;
	int					col;

	row = 0;
	while (row < vars->original_map->row)
	{
		col = 0;
		while (col < vars->original_map->col)
		{
			pixel = &screen_datas[row][col];
			if (col + 1 < vars->original_map->col)
				draw_line(*pixel, screen_datas[row][col + 1], vars);
			if (row + 1 < vars->original_map->row)
				draw_line(*pixel, screen_datas[row + 1][col], vars);
			draw_pixel(pixel, vars);
			++col;
		}
		++row;
	}
}
