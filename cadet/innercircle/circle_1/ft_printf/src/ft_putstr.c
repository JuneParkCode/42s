/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:08:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/24 13:09:33 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/ft_printf.h"

int	ft_putstr(const char *str)
{
	size_t	len;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
