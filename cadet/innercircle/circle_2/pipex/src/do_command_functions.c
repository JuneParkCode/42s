/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:04:17 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/19 18:02:38 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "pipex.h"

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

static char	**get_inlet_argv(char **argv)
{
	char	**inlet_argv;
	char	**command_argv;
	int		sizeof_command_argv;

	command_argv = get_command_argument(argv[FIRST_CMD_IDX]);
	sizeof_command_argv = get_splitted_arr_size(command_argv);
	inlet_argv = error_exit_malloc(sizeof(char *) * (sizeof_command_argv + 2));
	inlet_argv = copy_array(command_argv, inlet_argv);
	inlet_argv = append_array(inlet_argv, argv[INFILE_IDX]);
	free_splitted_array(command_argv);
	return (inlet_argv);
}

t_status	do_command(const int argc, char **argv, const int no_cmd)
{
	char	**new_argv;
	pid_t	pid;

	if (no_cmd == FIRST_CMD_IDX)
	{
		new_argv = get_inlet_argv(argv);
		execute_command(new_argv[CMD_PATH_IDX], new_argv);
		free_splitted_array(new_argv);
	}
	else
	{
		pid = build_pipe_and_fork_process();
		if (pid == 0)
			do_command(argc, argv, no_cmd - 1);
		else
		{
			new_argv = get_command_argument(argv[no_cmd]);
			execute_command(new_argv[CMD_PATH_IDX], new_argv);
			wait(NULL);
			free_splitted_array(new_argv);
		}
	}
	return (SUCCESS);
}
