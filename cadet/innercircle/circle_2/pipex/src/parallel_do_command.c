/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_do_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:28:09 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/19 22:33:28 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"

static int	get_number_of_cmds(int argc)
{
	return (argc - FIRST_CMD_IDX);
}

static int	**create_pipe_by_process(int number_of_commands)
{
	int	**pipe_lines;
	int	idx;

	idx = 0;
	pipe_lines = error_exit_malloc(sizeof(int *) * (number_of_commands));
	while (idx < number_of_commands)
	{
		pipe_lines[idx] = error_exit_malloc(sizeof(int) * 2);
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

int	build_pipe_and_fork_process_parallel(int argc, char **argv)
{	
	const int	number_of_commands = get_number_of_cmds(argc);
	int			**pipe_lines;
	int			idx;
	pid_t		pid;
	char		**new_argv;

	pipe_lines = create_pipe_by_process(number_of_commands);	
	idx = 0;
	while (idx < number_of_commands)
	{
		pid = fork();
		if (pid == FAILED)
			put_error_and_exit();
		if (pid == CHILD_PROCESS_PID)
		{
			close_child_pipelines(pipe_lines, idx);
			if (idx > 0 
				&& dup2(pipe_lines[idx - 1][PIPE_INDEX_READ], STDIN_FILENO) == FAILED)
				put_error_and_exit();
			if (idx + 1 < number_of_commands 
				&& dup2(pipe_lines[idx][PIPE_INDEX_WRITE], STDOUT_FILENO) == FAILED)
				put_error_and_exit();
			new_argv = get_command_argument(argv[idx + FIRST_CMD_IDX]);
			execute_command(new_argv[0], new_argv);
			break ;
		}
		++idx;
	}
	if (pid != CHILD_PROCESS_PID)
	{
		close_parent_pipelines(pipe_lines, number_of_commands);
		waitpid(pid, NULL, 0);
	}
	return (SUCCESS);
}
