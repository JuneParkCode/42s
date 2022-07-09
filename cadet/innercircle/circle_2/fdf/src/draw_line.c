/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:00:23 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/09 20:06:07 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "fdf.h"

#define LINE_COLOR 0xff0000

static int	get_df(int a, int b)
{
	if ((b - a) < 0)
		return (-1);
	else
		return (1);
}

void	draw_line(const t_pixel pixel1, const t_pixel pixel2, const t_vars *vars)
{
	const int		dx = get_df(pixel1.x, pixel2.x);
	const int		dy = get_df(pixel1.y, pixel2.y);
	const double	dy_dx = ((double)pixel2.y - pixel1.y) / ((double)pixel2.x - pixel1.x);
	const double	dx_dy = ((double)pixel2.x - pixel1.x) / ((double)pixel2.y - pixel1.y);
	t_pixel		pixel_pos;

	pixel_pos.x = pixel1.x;
	pixel_pos.y = pixel1.y;
	while (pixel_pos.x != pixel2.x)
	{
		mlx_pixel_put(vars->mlx_info->mlx_ptr, vars->mlx_info->win_ptr,\
						pixel_pos.x, pixel_pos.y, (0xffffff >> (pixel2.color % 32)));
		pixel_pos.x += dx;
		pixel_pos.y = dy_dx * (pixel_pos.x - pixel1.x) + pixel1.y;
	}
	pixel_pos.x = pixel1.x;
	pixel_pos.y = pixel1.y;
	while (pixel_pos.y != pixel2.y)
	{
		mlx_pixel_put(vars->mlx_info->mlx_ptr, vars->mlx_info->win_ptr,\
						pixel_pos.x, pixel_pos.y, (0xffffff >> (pixel2.color % 32)));
		pixel_pos.y += dy;
		pixel_pos.x = dx_dy * (pixel_pos.y - pixel1.y) + pixel1.x;
	}
}
