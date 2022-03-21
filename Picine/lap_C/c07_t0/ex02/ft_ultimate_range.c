/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:39:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/16 09:49:36 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	size = max - min + (min < 0 && max > 0);
	*range = (int *) malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		*(*range + i) = min++;
		++i;
	}
	if (size <= 0)
		return (-1);
	return (size);
}
