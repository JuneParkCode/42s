/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:15 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/11 16:04:08 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putaddr(void *addr, int fd)
{
	if (addr == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	return (ft_puthex_fd((unsigned long long) addr, 0, fd));
}
