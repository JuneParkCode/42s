/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:28:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 16:53:24 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

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
