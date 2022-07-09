/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:20:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/09 20:32:52 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "fdf.h"

void	plot_test(t_vars *vars)
{
	t_map_info	*map_info = vars->original_map;
	t_screen_data	screen_datas = vars->screen_data;
	t_mlx_info	*mlx_info = vars->mlx_info;
	int	row, col;

	row = 0;
	while (row + 1 < map_info->row)
	{
		col = 0;
		while (col + 1 < map_info->col)
		{
			int x = screen_datas[row][col].x;
			int y = screen_datas[row][col].y;
			int color = screen_datas[row][col].color;
			//printf("pos1 : %d, %d | pos2 : %d, %d\n", pos1.x, pos2.y, pos2.x, pos2.y);
			draw_line(screen_datas[row][col], screen_datas[row][col + 1], vars); 
			draw_line(screen_datas[row][col], screen_datas[row + 1][col], vars); 
			mlx_pixel_put(mlx_info->mlx_ptr,\
				mlx_info->win_ptr,\
				x,\
				y,\
				0xffffff >> (color % 32));
			++col;
		}
		++row;
	}
}

static void	init_cam(t_camera *camera)
{
	camera->x_axis_angle = 0;
	camera->y_axis_angle = 0;
	camera->z_axis_angle = 0;
	camera->zoom = 1;
}

void	open_window(t_mlx_info *mlx_info)
{
	mlx_info->mlx_ptr = mlx_init();
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr, 1920, 1080, "FDF");
}

int	key_hook(int key_code, t_vars *vars)
{
	t_mlx_info		*mlx_info = vars->mlx_info;
	t_map_info		*map_info = vars->original_map;
	t_screen_data	screen_datas = vars->screen_data;
	t_camera		*cam = vars->camera;

	printf("key_hook %d\n", key_code);
	if (key_code == 0)
	{
		printf("a\n");
		cam->z_axis_angle -= M_PI / ROTATION_UNIT;
	}
	else if(key_code == 13)
	{
		printf("w\n");
		cam->y_axis_angle += M_PI / ROTATION_UNIT;
	}
	else if (key_code == 1)
	{
		printf("s\n");
		cam->y_axis_angle -= M_PI / ROTATION_UNIT;
	}
	else if (key_code == 2)
	{
		printf("d\n");
		cam->z_axis_angle += M_PI / ROTATION_UNIT;
	}
	else if (key_code == 6)
	{
		printf("z\n");
		cam->x_axis_angle -= M_PI / ROTATION_UNIT;
	}
	else if (key_code == 7)
	{
		printf("x\n");
		cam->x_axis_angle += M_PI / ROTATION_UNIT;
	}
	else if (key_code == 53)
	{
		printf("EXIT\n");
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		exit(0);
	}
	else if (key_code == 27)
	{
		printf("-\n");
		cam->zoom /= 2;
		if (cam->zoom == 0)
			cam->zoom = 1;
	}
	else if (key_code == 24)
	{
		printf("+\n");
		cam->zoom *= 2;
	}
	else if (key_code == 123)
	{
		printf("move left\n");
		cam->margin_x -= MOVE_MARGIN_UNIT;
	}
	else if (key_code == 124)
	{
		printf("move right\n");
		cam->margin_x += MOVE_MARGIN_UNIT;
	}
	else if (key_code == 126)
	{
		printf("move up\n");
		cam->margin_y -= MOVE_MARGIN_UNIT;
	}
	else if (key_code == 125)
	{
		printf("move down\n");
		cam->margin_y += MOVE_MARGIN_UNIT;
	}
	else if (key_code == 34)
	{
		init_cam(cam);
	}
	printf("UPDATE SCREEN\n");
	update_screen_data_in_new_cam(screen_datas, map_info, cam);
	mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	plot_test(vars);
	return (0);
}


int	main(int argc, char *argv[])
{
	t_mlx_info		mlx_info;
	t_camera		camera;
	t_vars			vars;

	if (argc != 2 || is_valid_file_name(argv[1]) == FALSE)
		return (FAILED);
	vars.original_map = get_map_info(argv[1]);
	vars.screen_data = get_new_screen_data(vars.original_map);
	vars.camera = &camera;
	vars.mlx_info = &mlx_info;
	init_cam(&camera);
	open_window(&mlx_info);
	mlx_key_hook(mlx_info.win_ptr, key_hook, &vars);
	mlx_loop(mlx_info.mlx_ptr);
	return (SUCCESS);
}
