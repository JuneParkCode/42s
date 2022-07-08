/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:20:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/08 18:27:26 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	plot_test(t_mlx_info *mlx_info, t_map_info *map_info)
{
	int	row, col;

	row = 0;
	while (row < map_info->row)
	{
		col = 0;
		while (col < map_info->col)
		{
			mlx_pixel_put(mlx_info->mlx_ptr,\
				mlx_info->win_ptr,\
				col * 10 + 100,\
				row * 10 + 100,\
				0xffffff >> (map_info->data[row][col]));
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

int	main(int argc, char *argv[])
{
	t_mlx_info	mlx_info;
	t_map_info	*map_info;

	if (argc != 2 || is_valid_file_name(argv[1]) == FALSE)
		return (FAILED);
	map_info = get_map_info(argv[1]);
	open_window(&mlx_info);
	plot_test(&mlx_info, map_info);
	mlx_loop(mlx_info.mlx_ptr);
	return (SUCCESS);
}
