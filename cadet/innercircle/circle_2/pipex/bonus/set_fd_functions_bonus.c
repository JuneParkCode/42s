/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:05:08 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/22 18:28:48 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipex_bonus.h"
#include "libft.h"

void	set_inlet_fd(char *infile_name)
{
	const int	open_option = O_RDONLY;
	const int	fd = open(infile_name, open_option);

	if (fd == FAILED)
		put_error_and_exit();
	if (dup2(fd, STDIN_FILENO) == FAILED)
		put_error_and_exit();
}

void	set_outlet_fd_trunc(char *outfile_name)
{
	const int	open_option = O_WRONLY | O_TRUNC | O_CREAT;
	const int	open_mode = S_IREAD | S_IWRITE;
	const int	fd = open(outfile_name, open_option, open_mode);

	if (fd == FAILED)
		put_error_and_exit();
	if (dup2(fd, STDOUT_FILENO) == FAILED)
		put_error_and_exit();
}

void	set_outlet_fd_append(char *outfile_name)
{
	const int	open_option = O_WRONLY | O_APPEND | O_CREAT;
	const int	open_mode = S_IREAD | S_IWRITE;
	const int	fd = open(outfile_name, open_option, open_mode);

	if (fd == FAILED)
		put_error_and_exit();
	if (dup2(fd, STDOUT_FILENO) == FAILED)
		put_error_and_exit();
}

void	set_process_to_process_fd(\
	const int no_cmd, const int number_of_commands,
	int pipelines[2][2], char **argv)
{
	const int	outfile_idx = number_of_commands + FIRST_CMD_IDX;
	const int	in_idx = no_cmd & 1;
	const int	out_idx = (in_idx + 1) % 2;

	if (no_cmd != 0)
	{
		close_errctl(pipelines[in_idx][PIPE_INDEX_WRITE]);
		if (dup2(pipelines[in_idx][PIPE_INDEX_READ], STDIN_FILENO) == FAILED)
			put_error_and_exit();
	}
	else
		set_inlet_fd(argv[INFILE_IDX]);
	if (no_cmd + 1 != number_of_commands)
	{
		close_errctl(pipelines[out_idx][PIPE_INDEX_READ]);
		if (dup2(pipelines[out_idx][PIPE_INDEX_WRITE], STDOUT_FILENO) == FAILED)
			put_error_and_exit();
	}
	if (no_cmd + 1 == number_of_commands)
	{
		if (ft_strncmp(TMP_FILE_NAME, argv[1], -1) == 0)
			set_outlet_fd_append(argv[outfile_idx]);
		else
			set_outlet_fd_trunc(argv[outfile_idx]);
	}
}
