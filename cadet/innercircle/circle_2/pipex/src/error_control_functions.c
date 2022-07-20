/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:03:59 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 16:26:19 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"

void	put_error_and_exit(void)
{
	perror(NULL);
	exit(errno);
}

void	*error_controlled_malloc(const size_t malloc_size)
{
	void	*ptr;

	ptr = malloc(malloc_size);
	if (ptr == NULL)
		put_error_and_exit();
	return (ptr);
}

pid_t	error_controlled_fork(void)
{
	const pid_t	pid = fork();

	if (pid == FAILED)
		put_error_and_exit();
	return (pid);
}

void	error_controlled_pipe(int pipeline[2])
{
	if (pipe(pipeline) == FAILED)
		put_error_and_exit();
}

void	error_controlled_close(int fd)
{
	if (close(fd) == FAILED)
		put_error_and_exit();
}
