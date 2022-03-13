/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:12:58 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/12 16:28:51 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* Function		:	ft_atoi
 * Description	:	Applies the function ’f’ to each character of
 * 					the string ’s’ , and passing its index as first
 * 					argument to create a new string (with malloc(3))
 * 					resulting from successive applications of ’f’.
 * Param		
 * 			s	:	The string on which to iterate.
 * 			f	:	 The function to apply to each character.
 * Return Value	:	The string created from the successive applications
 * 					of ’f’. Returns NULL if the allocation fails.
 * 					NULL 	: allocation error
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const size_t	size = ft_strlen(s);
	size_t			idx_str;
	char			*res;

	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	idx_str = 0;
	while (idx_str < size)
	{
		res[idx_str] = f(idx_str, s[idx_str]);
		++idx_str;
	}
	return (res);
}
