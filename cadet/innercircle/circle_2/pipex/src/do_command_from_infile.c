/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command_from_infile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:26:38 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 14:32:21 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft.h"
#include "pipex.h"

t_status	do_command_from_infile(const int argc, char **argv)
{
	char	**new_argv;
	int		pid;
	int		backup_stdin;

	backup_stdin = dup(STDIN_FILENO);
	pid = build_pipe_and_fork_process();
	waitpid(pid, NULL, 0);
	if (pid == CHILD_PROCESS_PID)
	{
		do_command(argc, argv, argc - 3);
	}
	else
	{
		set_outlet_pipe(argv[argc - 1]);
		new_argv = get_command_argument(argv[argc - 2]);
		execute_command(new_argv[CMD_PATH_IDX], new_argv);
		free_splitted_array(new_argv);
	}
	return (SUCCESS);
}
