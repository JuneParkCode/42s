/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:35:53 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/17 18:38:34 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t ft_strcspn(const char* str, const char* set)
{
	size_t	idx_str;
	
	idx_str = 0;
	while (str[idx_str])
	{
		if (ft_strchr(set, str[idx_str]))
			return (idx_str);
	}
	return (idx_str);
}
