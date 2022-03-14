/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:31:46 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/14 16:05:04 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* Function		:	ft_strjoin
 * Description	:	Allocates and returns a new string, which is the result of
 * 					the concatenation of ’s1’ and ’s2’.
 * Param		
 * 			s1	:	The prefix string.
 * 			s2	:	The suffix string.
 * Return Value	:	address of joined string
 * 					NULL : Memory allocation error
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	idx_s1;
	size_t	idx_s2;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	idx_s1 = 0;
	idx_s2 = 0;
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, len_s1 + len_s2 + 1);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy(res + len_s1, s2, len_s2);
	return (res);
}
