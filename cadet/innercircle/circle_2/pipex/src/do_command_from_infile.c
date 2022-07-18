/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command_from_infile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:26:38 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 19:22:57 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"


void	set_outlet_pipe(char *outfile_name)
{
	const int	fd = open(outfile_name, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);

	if (fd == FAILED)
		put_error_and_exit();
	if (dup2(fd, STDOUT_FILENO) == FAILED)
		put_error_and_exit();
}

t_status	do_command_from_infile(const int argc, char **argv)
{
	char	**new_argv;
	int		pid;

	pid = build_pipe_and_fork_process();
	if (pid == CHILD_PROCESS_PID)
	{
		do_command(argc, argv, argc - 3);
	}
	else
	{
		set_outlet_pipe(argv[argc - 1]);
		new_argv = get_command_option(argv[argc - 2]);
		execve(new_argv[0], new_argv, NULL);
		wait(NULL);
		free(new_argv);
	}
	return (SUCCESS);
}
