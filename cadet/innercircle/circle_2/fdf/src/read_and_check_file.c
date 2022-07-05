/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:27:32 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/05 13:51:16 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"

static t_bool	free_raw_map(char **raw_map)
{
	int	idx;

	idx = 0;
	if (raw_map == NULL)
		return (TRUE);
	while (raw_map[idx] != NULL)
	{
		free(raw_map[idx]);
		++idx;
	}
	free(raw_map);
	return (TRUE);
}

static int	get_number_of_line_of_file(const char *file_name)
{
	const int	fd = open(file_name, O_RDONLY);
	int			number;

	number = 0;
	while (ft_get_next_line(fd) != NULL)
		++number;
	return (number);
}

static char	**read_file(const char *file_name)
{
	const int	fd = open(file_name, O_RDONLY);
	const int	size = get_number_of_line_of_file(file_name) + 1;
	char		**result;
	int			idx;

	result = malloc(sizeof(char *) * size);
	idx = 0;
	while (idx < size)
	{
		result[idx] = ft_get_next_line(fd);
		++idx;
	}
	return (result);
}

t_map_info	*create_map_info(int **map_data, const int row, const int col)
{
	t_map_info	*map;

	map = malloc(sizeof(t_map_info));
	map->data = map_data;
	map->row = row;
	map->col = col;
	return (map);
}

t_status	read_and_check_file(const char *file_name, t_map_info **map_info)
{
	char	**string_map_data;
	int		**map_data;
	int		row;
	int		col;

	string_map_data = read_file(file_name);
	if (is_valid_map_data(string_map_data) == FALSE)
	{
		ft_putstr_fd("Invalid map data!\n", FD_STDERR);
		free_raw_map(string_map_data);
		return (FAILED);
	}
	map_data = convert_string_data_to_int_data(string_map_data, &row, &col);
	*map_info = create_map_info(map_data, row, col);
	return (SUCCESS);
}
