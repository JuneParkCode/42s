/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:39:17 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/16 09:39:19 by sungjpar         ###   ########.fr       */
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

int	ft_get_total_length(int total_length, int size, char **strs)
{
	int	i;

	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		++i;
	}
	return (total_length);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_empty_case(void)
{
	char	*result;

	result = malloc(1);
	result[0] = 0;
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		idx_strs;
	int		total_length;
	char	*result;
	char	*cur;

	if (size <= 0)
		return (ft_empty_case());
	total_length = (size - 1) * ft_strlen(sep);
	total_length = ft_get_total_length(total_length, size, strs) + 1;
	result = malloc((total_length) * sizeof(char));
	cur = result;
	idx_strs = 0;
	while (idx_strs < size)
	{
		ft_strcpy(cur, strs[idx_strs]);
		cur += ft_strlen(strs[idx_strs]);
		if (cur == result + total_length - 1)
			break ;
		ft_strcpy(cur, sep);
		cur += ft_strlen(sep);
		idx_strs++;
	}
	result[total_length - 1] = 0;
	return (result);
}
