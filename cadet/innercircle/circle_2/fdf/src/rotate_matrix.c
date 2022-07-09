/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:47:52 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/09 12:29:24 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_vector	rotate_x_axis(const t_vector v, const double theta)
{
	const double	cos_value = cos(theta);
	const double	sin_value = sin(theta);
	const double	matrix[3][3] = {
		{1, 0 ,0},
		{0, cos_value, -sin_value},
		{0, sin_value, cos_value},
	};
	t_vector		result_vector;

	result_vector.x = v.x;
	result_vector.y = v.y * matrix[1][1] + v.z * matrix[1][2];
	result_vector.z = v.y * matrix[2][1] + v.z * matrix[2][2];
	return (result_vector);
}

t_vector	rotate_y_axis(const t_vector v, const double theta)
{
	const double	cos_value = cos(theta);
	const double	sin_value = sin(theta);
	const double	matrix[3][3] = {
		{cos_value, 0 ,sin_value},
		{0, 1, 0},
		{-sin_value, 0, cos_value},
	};
	t_vector		result_vector;

	result_vector.x = v.x * matrix[0][0] + v.z * matrix[0][2];
	result_vector.y = v.y ;
	result_vector.z = v.x * matrix[2][0] * v.z * matrix[2][2];
	return (result_vector);
}

t_vector	rotate_z_axis(const t_vector v, const double theta)
{
	const double	cos_value = cos(theta);
	const double	sin_value = sin(theta);
	const double	matrix[3][3] = {
		{cos_value, sin_value ,0},
		{-sin_value, cos_value, 0},
		{0, 0, 1},
	};
	t_vector		result_vector;

	result_vector.x = v.x * matrix[0][0] + v.y * matrix[0][1];
	result_vector.y = v.x * matrix[1][0] + v.y * matrix[1][1];
	result_vector.z = v.z;
	return (result_vector);
}
