/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:27:09 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 14:42:44 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* Function		:	ft_memcpy
 * Description	:	copy length byte string to dest
 * 					(if src and dst is overlapped, behaviour is undefined)
 * Param		
 * 			dst	:	address to copy
 * 			src	:	source of copy bytes 
 * 			n	:	length of byte to copy
 * Return Value	:	original value of dst
 */
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	idx_byte;
	char	*dest;
	char	*source;

	if (dst == src)
		return (dst);
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
