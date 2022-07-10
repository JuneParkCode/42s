/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:53:28 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 19:06:37 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

int	key_hook_zoom(int key_code, t_vars *vars)
{
	const t_mlx_info	*mlx_info = vars->mlx_info;
	t_camera			*cam;

	cam = vars->camera;
	if (key_code == KEY_MINUS)
	{
		cam->zoom /= 2;
		if (cam->zoom == 0)
			cam->zoom = 1;
	}
	else if (key_code == KEY_PLUS)
		cam->zoom *= 2;
	else if (key_code == KEY_I)
		set_isometric_cam(cam);
	else if (key_code == KEY_P)
		set_parallel_cam(cam);
	else
		return (0);
	update_screen_data_in_new_cam(vars);
	mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	draw_screen(vars);
	return (0);
}

int	key_hook_move(int key_code, t_vars *vars)
{
	const t_mlx_info	*mlx_info = vars->mlx_info;
	t_camera			*cam;

	cam = vars->camera;
	if (key_code == KEY_LEFT)
		cam->margin_x -= MOVE_MARGIN_UNIT;
	else if (key_code == KEY_RIGHT)
		cam->margin_x += MOVE_MARGIN_UNIT;
	else if (key_code == KEY_UP)
		cam->margin_y -= MOVE_MARGIN_UNIT;
	else if (key_code == KEY_DOWN)
		cam->margin_y += MOVE_MARGIN_UNIT;
	else
		return (0);
	update_screen_data_in_new_cam(vars);
	mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	draw_screen(vars);
	return (0);
}

int	key_hook_exit(int key_code, t_vars *vars)
{
	const t_mlx_info	*mlx_info = vars->mlx_info;
	t_camera			*cam;

	cam = vars->camera;
	if (key_code == KEY_ESC)
	{
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		free_and_exit(vars);
	}
	return (0);
}

int	key_hook_rotation(int key_code, t_vars *vars)
{
	const t_mlx_info	*mlx_info = vars->mlx_info;
	t_camera			*cam;

	cam = vars->camera;
	if (key_code == KEY_A)
		cam->z_axis_angle -= M_PI / ROTATION_UNIT;
	else if (key_code == KEY_W)
		cam->y_axis_angle += M_PI / ROTATION_UNIT;
	else if (key_code == KEY_S)
		cam->y_axis_angle -= M_PI / ROTATION_UNIT;
	else if (key_code == KEY_D)
		cam->z_axis_angle += M_PI / ROTATION_UNIT;
	else if (key_code == KEY_Z)
		cam->x_axis_angle -= M_PI / ROTATION_UNIT;
	else if (key_code == KEY_X)
		cam->x_axis_angle += M_PI / ROTATION_UNIT;
	else
		return (0);
	update_screen_data_in_new_cam(vars);
	mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	draw_screen(vars);
	return (0);
}

int	key_hook_funcs(int key_code, t_vars *vars)
{
	key_hook_zoom(key_code, vars);
	key_hook_move(key_code, vars);
	key_hook_rotation(key_code, vars);
	key_hook_exit(key_code, vars);
	return (0);
}
