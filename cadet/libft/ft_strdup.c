/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:34:28 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 19:41:18 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

/* Function		:	ft_strdup
 * Description	:	allocates sufficient memory for a copy of the string s1
 * Param		
 * 			s1	: 	string to copy
 * Return Value	:	address of duplicated string
 * 					NULL : no such byte exists whithin n bytes
 */
char	*ft_strdup(const char *s1)
{
	const size_t	len_str = ft_strlen(s1);
	size_t			idx_str;
	char			*res;

	res = malloc((len_str + 1) * sizeof(char));
	ft_memset(res ,0, len_str + 1);
	if (res == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	idx_str = 0;
	while (idx_str < len_str)
	{
		res[idx_str] = s1[idx_str];
		++idx_str;
	}
	return (res);
}
