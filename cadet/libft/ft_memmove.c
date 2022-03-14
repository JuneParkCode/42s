/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:53:47 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/14 16:18:45 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* Function		:	ft_memmove
 * Description	:	copy length byte string to dest
 * 					(if overlapped, copy is done in a non-destructive manner)
 * Param		
 * 			dst	:	address to copy
 * 			src	:	source of copy bytes 
 * 			len	:	length of byte to copy
 * Return Value	:	original value of dst
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		idx_byte;
	char		*dest;
	const char	*source;

	idx_byte = 0;
	if (src > dst)
	{
		while (idx_byte < len)
		{
			((char *)dst)[idx_byte] = ((char *)src)[idx_byte];
			++idx_byte;
		}
	}
	else if (src < dst)
	{
		dest = (char *) dst + len - 1;
		source = (const char *) src + len - 1;
		while (idx_byte < len)
		{
			dest[-idx_byte] = source[-idx_byte];
			++idx_byte;
		}
	}
	return (dst);
}
