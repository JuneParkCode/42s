/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:05:08 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 18:05:08 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"

void	set_process_to_process_fd(\
	const int no_cmd, const int number_of_commands, int pipelines[2][2])
{
	const int	in_idx = no_cmd & 1;
	const int	out_idx = (in_idx + 1) % 2;
	int			status;

	if (no_cmd != 0)
	{
		error_controlled_close(pipelines[in_idx][PIPE_INDEX_WRITE]);
		status = dup2(pipelines[in_idx][PIPE_INDEX_READ], STDIN_FILENO);
		if (status == FAILED)
			put_error_and_exit();
	}
	if (no_cmd + 1 != number_of_commands)
	{
		error_controlled_close(pipelines[out_idx][PIPE_INDEX_READ]);
		status = dup2(pipelines[out_idx][PIPE_INDEX_WRITE], STDOUT_FILENO);
		if (status == FAILED)
			put_error_and_exit();
	}
}

void	set_outlet_fd(char *outfile_name)
{
	const int	open_option = O_WRONLY | O_TRUNC | O_CREAT;
	const int	open_mode = S_IREAD | S_IWRITE;
	const int	fd = open(outfile_name, open_option, open_mode);

	if (fd == FAILED)
		put_error_and_exit();
	if (dup2(fd, STDOUT_FILENO) == FAILED)
		put_error_and_exit();
}
