/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:45:34 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/19 16:37:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"
#include "libft.h"

t_status	execute_command(const char *command_path, char **argv)
{
	if (access(command_path, X_OK) == FAILED)
		put_error_and_exit();
	if (execve(command_path, argv, NULL) == FAILED)
		put_error_and_exit();
	return (SUCCESS);
}
