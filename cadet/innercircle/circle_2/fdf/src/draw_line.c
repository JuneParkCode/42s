/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:00:23 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 19:29:16 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fdf.h"

static int	get_df(int a, int b)
{
	if ((b - a) < 0)
		return (-1);
	else
		return (1);
}

static int	get_larger_color(const t_pixel *p1, const t_pixel *p2)
{
	int	color1;
	int	color2;

	if (p1->color < 0)
		color1 = -(p1->color);
	else
		color1 = p1->color;
	if (p2->color < 0)
		color2 = -(p2->color);
	else
		color2 = p2->color;
	if (color1 > color2)
		return (p1->color);
	else
		return (p2->color);
}

void	draw_line(\
		const t_pixel pixel1, \
		const t_pixel pixel2, \
		const t_vars *vars)
{
	const int		dx = get_df(pixel1.x, pixel2.x);
	const int		dy = get_df(pixel1.y, pixel2.y);
	const double	dy_dx = \
		((double)pixel2.y - pixel1.y) / ((double)pixel2.x - pixel1.x);
	const double	dx_dy = \
		((double)pixel2.x - pixel1.x) / ((double)pixel2.y - pixel1.y);
	t_pixel			line_pixel;

	line_pixel = pixel1;
	line_pixel.color = get_larger_color(&pixel1, &pixel2);
	while (line_pixel.x != pixel2.x)
	{
		draw_pixel(&line_pixel, vars);
		line_pixel.x += dx;
		line_pixel.y = round(dy_dx * (line_pixel.x - pixel1.x) + pixel1.y);
	}
	line_pixel = pixel1;
	line_pixel.color = get_larger_color(&pixel1, &pixel2);
	while (line_pixel.y != pixel2.y)
	{
		draw_pixel(&line_pixel, vars);
		line_pixel.y += dy;
		line_pixel.x = round(dx_dy * (line_pixel.y - pixel1.y) + pixel1.x);
	}
}
