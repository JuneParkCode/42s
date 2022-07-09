/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:28:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/09 15:15:03 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
/*
static double	get_x_axis_angle(const t_vector rotation_vector)
{
	const double	width = rotation_vector.y;
	const double	height = rotation_vector.z;

	if (width == 0)
	{
		if (height < 0)
			return (-M_PI_2);
		else
			return (M_PI_2);
	}
	return (atan(height / width));
}

static double	get_y_axis_angle(const t_vector rotation_vector)
{
	const double	width = rotation_vector.x;
	const double	height = rotation_vector.z;

	if (width == 0)
	{
		if (height < 0)
			return (-M_PI_2);
		else
			return (M_PI_2);
	}
	return (atan(height / width));
}

static double	get_z_axis_angle(const t_vector rotation_vector)
{
	const double	width = rotation_vector.y;
	const double	height = rotation_vector.x;

	if (width == 0)
	{
		if (height < 0)
			return (-M_PI_2);
		else
			return (M_PI_2);
	}
	return (atan(height / width));
}
*/
t_vector	rotate_vector(const t_vector vector, const t_camera *cam)
{
	const double	x_axis_rotation_angle = cam->x_axis_angle;
	const double	y_axis_rotation_angle = cam->y_axis_angle;
	const double	z_axis_rotation_angle = cam->z_axis_angle;
	t_vector		result_vector;

	result_vector = vector;
	result_vector = rotate_x_axis(result_vector, x_axis_rotation_angle);
	result_vector = rotate_y_axis(result_vector, y_axis_rotation_angle);
	result_vector = rotate_z_axis(result_vector, z_axis_rotation_angle);
	return (result_vector);
}
