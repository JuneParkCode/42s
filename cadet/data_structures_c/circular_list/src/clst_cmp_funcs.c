/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_cmp_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:44 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:54:31 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "circular_list.h"

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
