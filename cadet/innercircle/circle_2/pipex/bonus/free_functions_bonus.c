/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:23:37 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 19:55:40 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex_bonus.h"

void	free_splitted_array(char **ptr)
{
	int	idx;

	idx = 0;
	while (ptr[idx])
		free(ptr[idx++]);
	free(ptr[idx]);
	free(ptr);
}
