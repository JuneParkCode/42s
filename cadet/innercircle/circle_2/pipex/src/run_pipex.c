/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:16:40 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 17:57:14 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"
#include "libft.h"

t_status	run_pipex(const int argc, char **argv)
{
	const char	*outfile_name = argv[argc - 1];

	if (ft_strncmp(argv[1], "heredoc", -1) == 0)
		heredoc_mode(argc, argv);
	else
		do_command_from_infile(argc, argv);
	return (SUCCESS);
}
