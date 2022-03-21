/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:38:49 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/16 09:49:08 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	while (src[i])
	{
		res[i] = src[i];
		++i;
	}
	res[i] = 0;
	return (res);
}
