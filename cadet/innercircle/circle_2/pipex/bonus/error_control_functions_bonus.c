/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control_functions_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:03:59 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 19:55:34 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pipex_bonus.h"

void	put_error_and_exit(void)
{
	perror(NULL);
	exit(errno);
}

void	*malloc_errctl(const size_t malloc_size)
{
	void	*ptr;

	ptr = malloc(malloc_size);
	if (ptr == NULL)
		put_error_and_exit();
	return (ptr);
}

pid_t	fork_errctl(void)
{
	const pid_t	pid = fork();

	if (pid == FAILED)
		put_error_and_exit();
	return (pid);
}

void	pipe_errctl(int pipeline[2])
{
	if (pipe(pipeline) == FAILED)
		put_error_and_exit();
}

void	close_errctl(int fd)
{
	if (close(fd) == FAILED)
		put_error_and_exit();
}
