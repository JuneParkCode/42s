/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:20:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/09 15:59:27 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "fdf.h"

void	plot_test(t_mlx_info *mlx_info, t_map_info *map_info, t_screen_data screen_datas)
{
	int	row, col;

	row = 0;
	while (row < map_info->row)
	{
		col = 0;
		while (col < map_info->col)
		{
			int x = screen_datas[row][col].x;
			int y = screen_datas[row][col].y;
			int color = screen_datas[row][col].color;
			//printf("%d %d %d\n", x, y, color);
			mlx_pixel_put(mlx_info->mlx_ptr,\
				mlx_info->win_ptr,\
				x * 10 + 1000,\
				y * 10 + 500,\
				0xffffff >> (color % 6));
			++col;
		}
		++row;
	}
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
		cam->z_axis_angle -= M_PI / 10;
	}
	else if(key_code == 13)
	{
		printf("w\n");
		cam->y_axis_angle += M_PI / 10;
	}
	else if (key_code == 1)
	{
		printf("s\n");
		cam->z_axis_angle += M_PI / 10;
	}
	else if (key_code == 2)
	{
		printf("d\n");
		cam->y_axis_angle -= M_PI / 10;
	}
	printf("UPDATE SCREEN\n");
	update_screen_data_in_new_cam(screen_datas, map_info, cam);
	mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	plot_test(mlx_info, map_info, screen_datas);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx_info		mlx_info;
	t_map_info		*map_info;
	t_screen_data	screen_datas;
	t_camera		camera;
	t_vars			vars;

	if (argc != 2 || is_valid_file_name(argv[1]) == FALSE)
		return (FAILED);
	map_info = get_map_info(argv[1]);
	screen_datas = get_new_screen_data(map_info);
	open_window(&mlx_info);
	vars.mlx_info = &mlx_info;
	vars.original_map = map_info;
	vars.screen_data = screen_datas;
	vars.camera = &camera;
	camera.x_axis_angle = 0;
	camera.y_axis_angle = 0;
	camera.z_axis_angle = 0;
	camera.distance = 1;
	plot_test(&mlx_info, map_info, screen_datas);
	mlx_key_hook(mlx_info.win_ptr, key_hook, &vars);
	mlx_loop(mlx_info.mlx_ptr);
	return (SUCCESS);
}
