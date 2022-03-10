/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:09 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 15:24:07 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem_b;
	unsigned char	fill_value;
	size_t			idx_memb;

	mem_b = (unsigned char *) b;
	fill_value = (unsigned char) c;
	idx_memb = 0;
	while (idx_memb < len)
	{
		mem_b[idx_memb] = fill_value;
		++idx_memb;
	}
	return (b);
}

/* Function		:	ft_calloc
 * Description	:	 contigously allocates enough space for count objects 
 * 					that are size bytes of memory each and returns a poin
 * 					ter to the allocated memory.
 * 					 The allocated memory is filled with bytes of value 0
 * Param		
 * 		count	:	number of memory to be allocated	
 * 		size	:	bytes of memory
 * Return Value	:	address of allocated memory
 * 					NULL : allocation does not work normally
 */
void	*ft_calloc(size_t count, size_t size)
{
	size_t	idx_byte;
	void	*res;

	res = malloc(count * size);
	ft_memset(res, 0, count * size);
	return (res);
}
