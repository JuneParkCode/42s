/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:39:03 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/16 09:49:22 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	arr = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
		arr[i++] = min++;
	return (arr);
}
