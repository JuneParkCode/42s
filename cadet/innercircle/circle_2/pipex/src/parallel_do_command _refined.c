/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_do_command _refined.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:28:09 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 16:32:30 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"

static int	**create_pipe_by_process(int number_of_commands)
{
	const int	fd_arr_size = 2;
	int			**pipe_lines;
	int			idx;

	idx = 0;
	pipe_lines = error_controlled_malloc(sizeof(int *) * (number_of_commands));
	while (idx < number_of_commands)
	{
		pipe_lines[idx] = error_controlled_malloc(sizeof(int) * fd_arr_size);
		if (pipe(pipe_lines[idx]) == FAILED)
			put_error_and_exit();
		++idx;
	}
	return (pipe_lines);
}

static void	close_parent_pipelines(int **pipe_lines, int number_of_commands)
{
	int	idx;

	idx = 0;
	while (idx < number_of_commands)
	{
		close(pipe_lines[idx][PIPE_INDEX_READ]);
		close(pipe_lines[idx][PIPE_INDEX_WRITE]);
		++idx;
	}
}

static void	close_child_pipelines(int **pipe_lines, int child_num)
{
	int	idx;

	idx = 0;
	while (idx < child_num)
	{
		if (idx != child_num)
		{
			if (close(pipe_lines[idx][PIPE_INDEX_WRITE]) == FAILED)
				put_error_and_exit();
		}
		if (idx != child_num - 1)
		{
			if (close(pipe_lines[idx][PIPE_INDEX_READ]) == FAILED)
				put_error_and_exit();
		}
		++idx;
	}
}

static void	set_pipe(int **pipe_lines, int no_cmd, const int number_of_commands)
{
	if (no_cmd > 0
		&& \
		dup2(pipe_lines[no_cmd - 1][PIPE_INDEX_READ], STDIN_FILENO) == FAILED)
	{
		put_error_and_exit();
	}
	if (no_cmd + 1 < number_of_commands
		&& \
		dup2(pipe_lines[no_cmd][PIPE_INDEX_WRITE], STDOUT_FILENO) == FAILED)
	{
		put_error_and_exit();
	}
}

int	build_pipe_and_fork_process_parallel(int argc, char **argv)
{
	const int	number_of_commands = argc - FIRST_CMD_IDX;
	int			**pipe_lines;
	int			idx;
	pid_t		pid;
	char		**new_argv;

	pipe_lines = create_pipe_by_process(number_of_commands);
	idx = 0;
	while (idx < number_of_commands)
	{
		pid = fork_process();
		if (pid == CHILD_PROCESS_PID)
		{
			close_child_pipelines(pipe_lines, idx);
			set_pipe(pipe_lines, idx, number_of_commands);
			new_argv = get_command_argument(argv[idx + FIRST_CMD_IDX]);
			execute_command(new_argv[0], new_argv);
			return (SUCCESS);
		}
		++idx;
	}
	close_parent_pipelines(pipe_lines, number_of_commands);
	waitpid(pid, NULL, 0);
	return (SUCCESS);
}
