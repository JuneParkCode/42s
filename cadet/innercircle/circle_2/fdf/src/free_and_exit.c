/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:54:14 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/10 19:34:20 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

static void	free_original_map(t_vars *vars)
{
	int	row;

	row = 0;
	while (row <= vars->original_map->row)
	{
		free(vars->original_map->data[row]);
		++row;
	}
	free(vars->original_map->data);
	free(vars->original_map);
}

static void	free_screen_data(t_vars *vars)
{
	int	row;

	row = 0;
	while (row < vars->original_map->row)
	{
		free(vars->screen_data[row]);
		++row;
	}
	free(vars->screen_data);
}

void	free_splited_string(char **splited_string)
{
	int	idx;

	idx = 0;
	if (splited_string == NULL)
		return ;
	while (splited_string[idx] != NULL)
	{
		free(splited_string[idx]);
		++idx;
	}
	free(splited_string);
}

void	free_and_exit(t_vars *vars)
{
	free_screen_data(vars);
	free_original_map(vars);
	exit(0);
}
