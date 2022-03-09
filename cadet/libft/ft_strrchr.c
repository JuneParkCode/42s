/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:33:33 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 02:23:59 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* Function		:	ft_strrchr
 * Description	:	locate last character c in string
 * Param		
 * 			c	:	number to compute
 * Return Value	:	address of located last character c in string
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	idx_byte;
	size_t	idx_find;
	
	idx_byte = 0;
	idx_find = -1;
	while (s[idx_byte])
	{
		if ((unsigned char)c == (unsigned char)s[idx_byte])
			idx_find = idx_byte;
		++idx_byte;
	}
	if (c == 0)
		idx_find = idx_byte;
	if (idx_find >= 0 && (unsigned char) c == (unsigned char) s[idx_find])
		return ((char *) (s + idx_find));
	else
		return (NULL);
}
