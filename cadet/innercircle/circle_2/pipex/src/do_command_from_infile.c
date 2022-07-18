/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command_from_infile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:26:38 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 19:36:01 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"

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
		// ACCESS VERIFY CODE
		execve(new_argv[0], new_argv, NULL);
		wait(NULL);
		free(new_argv);
	}
	return (SUCCESS);
}
