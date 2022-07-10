/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:55:26 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 17:48:43 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static t_bool	is_outside_window(const int x, const int y)
{
	if (x < 0 || x >= WINDOW_SIZE_WIDTH
		|| y < 0 || y >= WINDOW_SIZE_HEIGHT)
		return (TRUE);
	else
		return (FALSE);
}

void	draw_pixel(const t_pixel *pixel, const t_vars *vars)
{
	const int	margin_width = WINDOW_SIZE_WIDTH / 3 + vars->camera->margin_x;
	const int	margin_height = WINDOW_SIZE_HEIGHT / 3 + vars->camera->margin_y;
	const int	x = pixel->x + margin_width;
	const int	y = pixel->y + margin_height;

	if (is_outside_window(x, y))
		return ;
	else
	{
		mlx_pixel_put(\
			vars->mlx_info->mlx_ptr, vars->mlx_info->win_ptr, \
			x, y, \
			pixel->color);
	}
}
