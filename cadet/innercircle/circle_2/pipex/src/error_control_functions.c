/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:03:59 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 10:57:11 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "pipex.h"

void	put_error_and_exit(void)
{
	perror(strerror(errno));
	exit(errno);
}

void	*error_exit_malloc(const size_t malloc_size)
{
	void	*ptr;

	ptr = malloc(malloc_size);
	if (ptr == NULL)
		put_error_and_exit();
	return (ptr);
}
