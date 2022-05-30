/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_cmp_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:44 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:37:32 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx_byte;

	idx_byte = 0;
	while ((s1[idx_byte] || s2[idx_byte]) && idx_byte < n)
	{
		if (s1[idx_byte] != s2[idx_byte])
			return ((unsigned char) s1[idx_byte] - \
					(unsigned char) s2[idx_byte]);
		++idx_byte;
	}
	return (0);
}

int	f_ptr_strcmp(void *s1, void *s2)
{
	return (ft_strncmp((char *)s1, (char *)s2, -1));
}

int	f_ptr_intcmp(void *a, void *b)
{
	int	*x;
	int	*y;

	x = (int *)a;
	y = (int *)b;
	return (*x - *y);
}

int	f_ptr_llcmp(void *a, void *b)
{
	long long	*x;
	long long	*y;

	x = (long long *)a;
	y = (long long *)b;
	return (*x - *y);
}
