/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_pipe_line_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:28:09 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 17:58:38 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"

#include "libft.h"

static void	close_unused_pipe(int no_cmd, int pipelines[2][2])
{
	if (no_cmd < 2)
	{
		return ;
	}
	else
	{
		error_controlled_close(pipelines[no_cmd & 1][PIPE_INDEX_READ]);
		error_controlled_close(pipelines[no_cmd & 1][PIPE_INDEX_WRITE]);
	}
}

static void	do_child_process(
	char **argv, int pipelines[2][2],
	const int no_cmd, const int number_of_commands)
{
	const int	out_file_idx = number_of_commands + FIRST_CMD_IDX;
	char		**new_argv;

	set_process_to_process_fd(no_cmd, number_of_commands, pipelines);
	if (no_cmd == 0)
	{
		new_argv = get_inlet_argv(argv);
	}
	else
	{
		new_argv = get_command_argument(argv[no_cmd + FIRST_CMD_IDX]);
	}
	if (no_cmd + 1 == number_of_commands)
	{
		set_outlet_fd(argv[out_file_idx]);
	}
	execute_command(new_argv[0], new_argv);
}

static pid_t	build_pipe_and_fork(
	int no_cmd, int pipelines[2][2], const int number_of_commands, char **argv)
{
	pid_t	pid;

	close_unused_pipe(no_cmd, pipelines);
	error_controlled_pipe(pipelines[no_cmd & 1]);
	pid = error_controlled_fork();
	if (pid == CHILD_PROCESS_PID)
	{
		do_child_process(argv, pipelines, no_cmd, number_of_commands);
		return (pid);
	}
	return (pid);
}

t_status	do_commands(int argc, char **argv)
{
	const int	number_of_commands = argc - FIRST_CMD_IDX - 1;
	int			pipelines[2][2];
	int			no_cmd;
	pid_t		pid;

	no_cmd = number_of_commands - 1;
	while (no_cmd >= 0)
	{
		pid = build_pipe_and_fork(no_cmd, pipelines, number_of_commands, argv);
		if (pid == CHILD_PROCESS_PID)
			return (SUCCESS);
		--no_cmd;
	}
	waitpid(pid, NULL, 0);
	return (SUCCESS);
}
