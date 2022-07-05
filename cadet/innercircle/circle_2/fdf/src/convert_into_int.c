/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_into_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:02:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/05 14:06:33 by sungjpar         ###   ########.fr       */
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
	int		*result_arr;
	int		idx;

	if (str == NULL)
		return (NULL);
	splited_strings = ft_split(str, ' ');
	result_arr \
		 = malloc(sizeof(int) * (get_number_of_strings(splited_strings)));
	idx = 0;
	while (splited_strings[idx] != NULL)
	{
		result_arr[idx] = ft_atoi(splited_strings[idx]);
		++idx;
	}
	free(splited_strings);
	return (result_arr);
}

static int	get_map_col(char **string_map_data)
{
	char	**splited_strings;
	int		result;

	splited_strings = ft_split(string_map_data[0], ' ');
	result = get_number_of_strings(splited_strings);
	free(splited_strings);
	return (result);
}

int	**convert_string_map_data_to_int_arrs\
		(char **string_map_data, int *row, int *col)
{
	const int	size = get_number_of_strings(string_map_data) + 1;
	int			**result;
	int			row_idx;

	result = malloc(sizeof(int *) * (size));
	row_idx = 0;
	while (row_idx < size)
	{
		result[row_idx] \
			= convert_string_to_int_arr(string_map_data[row_idx]);
		++row_idx;
	}
	*row = row_idx;
	*col = get_map_col(string_map_data);
	return (result);
}
