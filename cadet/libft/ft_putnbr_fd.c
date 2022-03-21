/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:39:43 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/21 13:31:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* Function		:	ft_putnbr_fd
 * Description	:	Outputs the number n to the given file descriptor.
 * Param		
 * 			n	:	The integer to output.
 * 			fd	:	The file descriptor on which to write.
 * Return Value	:	NONE
 */
void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	size_t			idx_nums;
	unsigned int	nb;

	idx_nums = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	c = nb % 10 + '0';
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	write(fd, &c, 1);
}
