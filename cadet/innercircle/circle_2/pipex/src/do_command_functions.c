/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:04:17 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 19:34:57 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "pipex.h"

char	**get_command_option(char *command)
{
	char	**splitted_string;

	splitted_string = ft_split(command, ' ');
	return (splitted_string);
}


char	**get_inlet_argv(char **argv)
{
	char	**inlet_argv;

	inlet_argv = error_exit_malloc(sizeof(char *) * 4);
	inlet_argv[0] = "/bin/cat";
	inlet_argv[1] = "-e";
	inlet_argv[2] = "build_pipe_functions.c";
	inlet_argv[3] = NULL;
	return (inlet_argv);
}

t_status	do_command(const int argc, char **argv, const int no_cmd)
{
	char	**new_argv;
	pid_t	pid;

	if (no_cmd == 2)
	{
		new_argv = get_inlet_argv(argv);
		// ACCESS VERIFY CODE
		execve(new_argv[0], new_argv, NULL);
		free_splitted_array(new_argv);
		free(new_argv);
	}
	else
	{
		pid = build_pipe_and_fork_process();
		if (pid == 0)
			do_command(argc, argv, no_cmd - 1);
		else
		{
			new_argv = get_command_option(argv[no_cmd]);
			// ACCESS VERIFY CODE
			execve(new_argv[0], new_argv, NULL);
			wait(NULL);
			free_splitted_array(new_argv);
			free(new_argv);
		}
	}
	return (SUCCESS);
}
