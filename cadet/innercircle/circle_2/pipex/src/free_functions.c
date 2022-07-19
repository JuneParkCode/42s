/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:23:37 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/19 15:21:05 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

void	free_splitted_array(char **ptr)
{
	int	idx;

	idx = 0;
	while (ptr[idx])
		free(ptr[idx++]);
	free(ptr[idx]);
	free(ptr);
}
