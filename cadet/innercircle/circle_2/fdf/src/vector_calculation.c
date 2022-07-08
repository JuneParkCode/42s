/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:28:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/08 18:45:46 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static double	rotate_x_elem(t_vector vector, double angle_pi, double theta)
{
	const double	result;

	return (result);
}

static double	rotate_y_elem(t_vector vector, double angle_pi, double theta)
{
	double	result;

	return (result);
}

static double	rotate_z_elem(t_vector vector, double angle_pi, double theta)
{
	double	result;

	return (result);
}

t_vector	rotate_vector(t_vector vector, t_vector rotation_vector)
{
	const double	angle_pi = get_angle_pi(rotation_vector);
	const double	angle_theta = get_angle_theta(rotation_vector);
	t_vector		result_vector;

	result_vector.x = rotate_x_elem(vector, angle_pi, angle_theta);
	result_vector.y = rotate_x_elem(vector, angle_pi, angle_theta);
	result_vector.z = rotate_x_elem(vector, angle_pi, angle_theta);
	return (result_vector);
}
