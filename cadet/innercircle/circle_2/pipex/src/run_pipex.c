/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:16:40 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 13:30:31 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"
#include "libft.h"

t_status	run_pipex(const int argc, char **argv)
{
	const char	*outfile_name = argv[argc - 1];
	const int	number_of_commands = argc - 3;
	pid_t		pid;

	if (ft_strncmp(argv[1], "heredoc", -1) == 0)
		heredoc_mode(argc, argv);
	else
		do_command_from_infile(argc, argv);
	return (SUCCESS);
}
