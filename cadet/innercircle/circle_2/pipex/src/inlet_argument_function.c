/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inlet_argument_function.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:55:34 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 15:56:53 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static int	get_splitted_arr_size(char **command_argv)
{
	int	size;

	size = 0;
	while (command_argv[size])
		++size;
	++size;
	return (size);
}

static char	**append_array(char **dst, char *str)
{
	int	idx;

	idx = 0;
	while (dst[idx])
		++idx;
	dst[idx++] = str;
	dst[idx++] = NULL;
	return (dst);
}

static char	**copy_array(char **src, char **dst)
{
	int	idx;

	idx = 0;
	while (src[idx])
	{
		dst[idx] = ft_strdup(src[idx]);
		++idx;
	}
	dst[idx] = NULL;
	return (dst);
}

char	**get_inlet_argv(char **argv)
{
	char	**inlet_argv;
	char	**command_argv;
	int		sizeof_cmd_argv;

	command_argv = get_command_argument(argv[FIRST_CMD_IDX]);
	sizeof_cmd_argv = get_splitted_arr_size(command_argv);
	inlet_argv
		= error_controlled_malloc(sizeof(char *) * (sizeof_cmd_argv + 2));
	copy_array(command_argv, inlet_argv);
	append_array(inlet_argv, argv[INFILE_IDX]);
	free_splitted_array(command_argv);
	return (inlet_argv);
}
