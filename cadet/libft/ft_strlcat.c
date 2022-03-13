/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:45:51 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/13 19:59:37 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i_dest;
	size_t	i_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i_dest = len_dest;
	i_src = 0;
	while (i_src < len_src && i_dest + 1 < size)
		dest[i_dest++] = src[i_src++];
	dest[i_dest] = 0;
	if (len_dest > size)
		return (size + len_src);
	return (len_dest + len_src);
}
