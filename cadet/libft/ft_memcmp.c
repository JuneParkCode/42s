/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:10:17 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 01:38:16 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* Function		:	ft_memcmp
 * Description	:	fill a byte string with a byte value
 * Param		
 * 			b	:	address to fill
 * 			c	:	value of byte
 * 			len	:	length of byte to fill
 * Return Value	:	first argument (b)
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				idx_byte;
	const unsigned char	*str1;
	const unsigned char	*str2;

	idx_byte = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (idx_byte < n && str1[idx_byte] == str2[idx_byte])
		++idx_byte;
	if (idx_byte == n)
		return (0);
	else
		return (str1[idx_byte] - str2[idx_byte]);
}
