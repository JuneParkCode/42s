/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:26:49 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/17 18:29:41 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(const char c)
{
	const char	*spaces = "\t\n\r\v\f ";

	while (*spaces)
	{
		if (c == *spaces)
			return (1);
		++spaces;
	}
	return (0);
}
