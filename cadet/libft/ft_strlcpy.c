/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:57:56 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 03:46:40 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

/* Function		:	ft_strlcpy
 * Description	:	size-bounded string copying
 * 					(more safer than strcpy)
 * Param		
 * 			dst	:	destination address to copy
 * 			src	:	source address to copy
 * 		dstsize	:	size of destination size
 * Return Value	:	original value of dst
 */
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, \
		size_t dst_size)
{
	size_t	idx_byte;
	size_t	len_src;

	idx_byte = 0;
	len_src = strlen(src);
	if (dst_size == 0)
		return (len_src);
	while (idx_byte + 1 < dst_size && src[idx_byte])
	{
		dst[idx_byte] = src[idx_byte];
		++idx_byte;
	}
	dst[idx_byte] = 0;
	return (len_src);
}
