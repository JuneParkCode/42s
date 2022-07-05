/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:27:32 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/05 11:57:24 by sungjpar         ###   ########.fr       */
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

static t_bool	free_map_data(int **map_data)
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
	free(map_data);
	return (TRUE);
}

static int	get_number_of_line(const char *file_name)
{
	const int	fd = open(file_name, O_RDONLY);
	int			number;

	number = 0;
	while (ft_get_next_line(fd) != NULL)
		++number;
	return (number);
}

char	**read_file(const char *file_name)
{
	const int	fd = open(file_name, O_RDONLY);
	const int	size = get_number_of_line(file_name);
	t_bool		is_eof;
	char		**result;
	int			idx;

	is_eof = FALSE;
	result = malloc(sizeof(char *) * (size + 1));
	idx = 0;
	while (!is_eof)
	{
		result[idx] = ft_get_next_line(fd);
		is_eof = (result[idx] == NULL);
		++idx;
	}
	return (result);
}

t_status	read_and_check_file(const char *file_name, t_map_info **map_info)
{
	char	**raw_string_file_data;
	int		**map_data;

	raw_string_file_data = read_file(file_name);
	if (is_valid_string(raw_string_file_data) == FALSE)
	{
		free_raw_map(raw_string_file_data);
		return (FAILED);
	}
	map_data = convert_into_int(raw_string_file_data);
	(*map_info) \
		= get_map_data(map_data, get_map_row(map_data), get_map_col(map_data));
	return (SUCCESS);
}
