/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:51:23 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 19:01:17 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	init_cam(t_camera *camera)
{
	camera->x_axis_angle = 0;
	camera->y_axis_angle = 0;
	camera->z_axis_angle = 0;
	camera->zoom = 1;
}

void	set_isometric_cam(t_camera *camera)
{
	camera->x_axis_angle = M_PI / 4;
	camera->y_axis_angle = M_PI / 6;
	camera->z_axis_angle = M_PI / 6;
}

void	set_parallel_cam(t_camera *camera)
{
	camera->x_axis_angle = M_PI_2;
	camera->y_axis_angle = 0;
	camera->z_axis_angle = 0;
}
