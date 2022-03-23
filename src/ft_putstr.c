/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:08:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/23 16:08:50 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/libft_printf.h"

int	ft_putstr(const char *str)
{
	const size_t	len = ft_strlen(str);

	write(1, str, len);
	return (len);
}
