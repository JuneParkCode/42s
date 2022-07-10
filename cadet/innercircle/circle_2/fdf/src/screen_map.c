/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:51:35 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 18:02:09 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

static t_screen_data	init_screen_datas(t_map_info *original_map)
{
	const size_t	size = sizeof(t_pixel *) * original_map->row;
	t_screen_data	new_screen;
	int				row;
	int				col;

	new_screen = malloc(size);
	row = 0;
	while (row < original_map->row)
	{
		col = 0;
		new_screen[row] = malloc(sizeof(t_pixel) * original_map->col);
		while (col < original_map->col)
		{
			new_screen[row][col].x = col;
			new_screen[row][col].y = row;
			new_screen[row][col].color \
			= get_color(original_map->data[row][col]);
			++col;
		}
		++row;
	}
	return (new_screen);
}

static t_vector	get_new_vector(const double x, const double y, const double z)
{
	t_vector	new_vector;

	new_vector.x = x;
	new_vector.y = y;
	new_vector.z = z;
	return (new_vector);
}

static void	upate_column_pixels(\
	const int row, \
	t_screen_data screen_datas, \
	t_map_info *original_map, \
	t_camera *cam)
{
	int			z_value;
	int			col;
	t_vector	target_vector;
	t_vector	rotated_vector;
	t_pixel		*pixel;

	col = 0;
	while (col < original_map->col)
	{
		z_value = original_map->data[row][col];
		pixel = &screen_datas[row][col];
		target_vector = \
		get_new_vector(col * cam->zoom, row * cam->zoom, z_value * cam->zoom);
		rotated_vector = rotate_vector(target_vector, cam);
		*pixel = vector_projection_to_pixel(rotated_vector, get_color(z_value));
		++col;
	}
}

void	update_screen_data_in_new_cam(t_vars *vars)
{
	int	row;

	row = 0;
	while (row < vars->original_map->row)
	{
		upate_column_pixels(\
		row, \
		vars->screen_data, \
		vars->original_map, \
		vars->camera);
		++row;
	}
}

t_screen_data	get_new_screen_data(t_map_info *original_map)
{
	t_screen_data	screen_datas;

	screen_datas = init_screen_datas(original_map);
	return (screen_datas);
}
