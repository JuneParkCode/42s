/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:27:09 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 01:30:05 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	idx_byte;
	char	*dest;
	char	*source;

	idx_byte = 0;
	dest = (char *)dst;
	source = (char *)src;
	while (idx_byte < n)
	{
		dest[idx_byte] = source[idx_byte];
		++idx_byte;
	}
	return (dst);
}
