/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:23:01 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/10 16:56:56 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	idx_str;

	str = s;
	idx_str = 0;
	while (idx_str < n)
	{
		str[idx_str] = 0;
		++idx_str;
	}
}
