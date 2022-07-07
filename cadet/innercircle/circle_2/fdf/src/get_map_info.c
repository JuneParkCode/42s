/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:21:35 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/07 18:39:07 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_info	*get_map_info(const char *file_name)
{
	t_map_info	*map_info;

	if (read_and_check_file(file_name, &map_info) == FAILED)
		return (0x0);
	return (map_info);
}
