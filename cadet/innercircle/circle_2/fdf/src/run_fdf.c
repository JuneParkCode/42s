/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:21:35 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 19:27:23 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_status	run_fdf(int argc, char **argv)
{
	t_map_info	*map_info;

	if (read_and_check_file(argv[1], &map_info) == FAILED)
		return (FAILED);
	return (SUCCESS);
}
