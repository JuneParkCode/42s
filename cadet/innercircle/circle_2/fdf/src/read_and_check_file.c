/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:27:32 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 19:29:10 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"

t_status	read_and_check_file(const char *file_name, t_map_info **map_info)
{
	char	**raw_string_file_data;
	
	raw_string_file_data = read_file(file_name);
	if (is_all_digits(raw_string_file);
	return (SUCCESS);
}
