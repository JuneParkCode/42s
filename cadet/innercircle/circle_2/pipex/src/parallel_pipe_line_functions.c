/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_pipe_line_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:28:09 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/21 14:34:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"

static void	close_unused_pipe(\
	int no_cmd, int pipelines[2][2], const int number_of_commands)
{
	const int	last_second_command_idx = number_of_commands - 2;
	const int	unused_pipe_idx = no_cmd & 1;

	if (no_cmd >= last_second_command_idx)
	{
		return ;
	}
	else
	{
		close_errctl(pipelines[unused_pipe_idx][PIPE_INDEX_READ]);
		close_errctl(pipelines[unused_pipe_idx][PIPE_INDEX_WRITE]);
	}
}

static void	do_child_process_task(
	char **argv, char **envp, const int no_cmd)
{
	char	**new_argv;

	if (no_cmd == 0)
		new_argv = get_inlet_argv(argv, envp);
	else
		new_argv = get_command_argument(argv[no_cmd + FIRST_CMD_IDX], envp);
	execute_command(new_argv[0], new_argv);
	free_splitted_array(new_argv);
}

static pid_t	build_pipe_and_fork(
	int no_cmd, int pipelines[2][2], const int number_of_commands)
{
	pid_t	pid;

	close_unused_pipe(no_cmd, pipelines, number_of_commands);
	pipe_errctl(pipelines[no_cmd & 1]);
	pid = fork_errctl();
	return (pid);
}

t_status	do_commands(int argc, char **argv, char **envp)
{
	const int	number_of_commands = argc - FIRST_CMD_IDX - 1;
	int			pipelines[2][2];
	int			no_cmd;
	pid_t		pid;

	no_cmd = number_of_commands - 1;
	while (no_cmd >= 0)
	{
		pid = build_pipe_and_fork(no_cmd, pipelines, number_of_commands);
		if (pid == CHILD_PROCESS_PID)
		{
			set_process_to_process_fd(\
				no_cmd, number_of_commands, pipelines, argv);
			do_child_process_task(argv, envp, no_cmd);
			return (SUCCESS);
		}
		--no_cmd;
	}
	waitpid(pid, NULL, 0);
	return (SUCCESS);
}
