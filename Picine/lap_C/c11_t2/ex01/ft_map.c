/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:33:28 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 17:58:28 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	idx;
	int	*res;

	idx = 0;
	res = malloc(sizeof(int) * length);
	if (!res || !tab)
		return (0);
	while (idx < length)
	{
		res[idx] = f(tab[idx]);
		++idx;
	}
	return (res);
}
