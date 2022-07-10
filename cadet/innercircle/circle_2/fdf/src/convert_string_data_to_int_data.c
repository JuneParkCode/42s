/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_data_to_int_data.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:02:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 18:13:16 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static int	get_number_of_strings(char **splited_strings)
{
	int	size;

	size = 0;
	while (splited_strings[size])
		++size;
	return (size);
}

static int	*convert_string_to_int_arr(const char *str)
{
	char	**splited_strings;
	char	*trimmed_string;
	int		*result_arr;
	int		idx;

	if (str == NULL)
		return (NULL);
	trimmed_string = ft_strtrim(str, "\n ");
	splited_strings = ft_split(trimmed_string, ' ');
	result_arr = malloc(sizeof(int) * get_number_of_strings(splited_strings));
	idx = 0;
	while (splited_strings[idx] != NULL)
	{
		result_arr[idx] = ft_atoi(splited_strings[idx]);
		++idx;
	}
	free_splited_string(splited_strings);
	free(trimmed_string);
	return (result_arr);
}

static int	get_map_col(char **string_map_data)
{
	char	**splited_strings;
	char	*trimmed_string;
	int		result;

	trimmed_string = ft_strtrim(string_map_data[0], "\n ");
	splited_strings = ft_split(trimmed_string, ' ');
	result = get_number_of_strings(splited_strings);
	free_splited_string(splited_strings);
	free(trimmed_string);
	return (result);
}

int	**convert_string_data_to_int_data(\
	char **string_map_data, int *row, int *col)
{
	const int	malloc_size = get_number_of_strings(string_map_data) + 1;
	int			**result;
	int			row_idx;

	result = malloc(sizeof(int *) * (malloc_size));
	row_idx = 0;
	while (row_idx < malloc_size)
	{
		result[row_idx] = convert_string_to_int_arr(string_map_data[row_idx]);
		++row_idx;
	}
	*row = malloc_size - 1;
	*col = get_map_col(string_map_data);
	return (result);
}
