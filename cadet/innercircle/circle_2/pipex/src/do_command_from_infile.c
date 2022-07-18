/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command_from_infile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:26:38 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 17:43:07 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include "pipex.h"
#include "libft.h"

const char	**get_commands(const int argc, char **argv)
{
	const int	number_of_commands = argc - 3;
	const char	**commands = error_exit_malloc(number_of_commands);
	int			idx;

	idx = 0;
	while (idx < number_of_commands)
	{
		commands[idx] = argv[idx + 2];
		++idx;
	}
	return (commands);
}

static int	get_sizeof_splited_string(char **splitted_string)
{
	int	len;

	len = 0;
	while (splitted_string[len])
		++len;
	return (len);
}

char	**get_command_option(char *command)
{
	char	**splitted_string;

	splitted_string = ft_split(command, ' ');
	return (splitted_string);
}

t_status	do_command_from_infile(const int argc, char **argv)
{
	char	**new_argv;
	int		pid;
	int		no_cmd;

	no_cmd = argc - 2;
	pid = build_pipe_and_fork_process();
	if (pid == CHILD_PROCESS_PID)
	{
		new_argv = get_command_option(argv[no_cmd]);
		execve(new_argv[0], new_argv, NULL);
		wait(NULL);
		free(new_argv);
	}
	else
	{
		new_argv = get_command_option(argv[no_cmd]);
		execve(new_argv[0], new_argv,  NULL);
		wait(NULL);
		free(new_argv);
	}
	return (SUCCESS);
}
