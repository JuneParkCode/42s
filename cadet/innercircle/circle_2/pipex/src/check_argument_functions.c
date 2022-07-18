/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:50:04 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 11:12:12 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"

t_bool	is_valid_argument(const int argc, char **argv)
{
	int	infile_fd;

	if (argc <= 3)
		return (FALSE);
	infile_fd = open(argv[2], O_RDONLY);
	if (infile_fd == FAILED)
		put_error_and_exit();
	if (close(infile_fd) == FAILED)
		put_error_and_exit();
	return (TRUE);
}
