/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:39:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/16 15:13:44 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	if (size <= 0)
		return (-1);
	*range = (int *) malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		*(*range + i) = min++;
		++i;
	}
	return (size);
}
