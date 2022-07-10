/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:20:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 19:20:50 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "fdf.h"

static void	open_window(t_mlx_info *mlx_info)
{
	mlx_info->mlx_ptr = mlx_init();
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr, 1920, 1080, "FDF");
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
	set_isometric_cam(&camera);
	open_window(&mlx_info);
	update_screen_data_in_new_cam(&vars);
	draw_screen(&vars);
	mlx_key_hook(mlx_info.win_ptr, key_hook_funcs, &vars);
	mlx_loop(mlx_info.mlx_ptr);
	return (SUCCESS);
}
