/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:21:35 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/05 14:03:40 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_status	run_fdf(const char *file_name)
{
	t_map_info	*map_info;

	if (read_and_check_file(file_name, &map_info) == FAILED)
		return (FAILED);
	return (SUCCESS);
}
