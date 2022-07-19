/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pipe_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:09:05 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/19 16:11:02 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "pipex.h"

static void	set_pipe(const pid_t pid, const int pipe_fds[2])
{
	if (pid != CHILD_PROCESS_PID)
	{
		if (close(pipe_fds[PIPE_INDEX_WRITE]) == FAILED)
			put_error_and_exit();
		if (dup2(pipe_fds[PIPE_INDEX_READ], STDIN_FILENO) == FAILED)
			put_error_and_exit();
		close(pipe_fds[PIPE_INDEX_READ]);
	}
	else
	{
		if (close(pipe_fds[PIPE_INDEX_READ]) == FAILED)
			put_error_and_exit();
		if (dup2(pipe_fds[PIPE_INDEX_WRITE], STDOUT_FILENO) == FAILED)
			put_error_and_exit();
		close(pipe_fds[PIPE_INDEX_WRITE]);
	}
}

void	set_outlet_pipe(char *outfile_name)
{
	const int	fd = open(outfile_name, O_WRONLY | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);

	if (fd == FAILED)
		put_error_and_exit();
	if (dup2(fd, STDOUT_FILENO) == FAILED)
		put_error_and_exit();
}

static pid_t	fork_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == FAILED)
		put_error_and_exit();
	return (pid);
}

pid_t	build_pipe_and_fork_process(void)
{
	pid_t	pid;
	int		pipe_fds[2];

	if (pipe(pipe_fds) == FAILED)
		put_error_and_exit();
	pid = fork_process();
	set_pipe(pid, pipe_fds);
	return (pid);
}
