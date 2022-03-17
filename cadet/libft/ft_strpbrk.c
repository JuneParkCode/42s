/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:29:55 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/17 18:34:25 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str, const char *set)
{
	char	*res;

	while (*str)
	{
		res = ft_strchr(set, *str);
		if (res)
			return ((char *)str);
		++str;
	}
	return (NULL);
}
