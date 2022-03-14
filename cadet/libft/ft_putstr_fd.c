/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:39:43 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/14 16:07:55 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/* Function		:	ft_putstr_fd
 * Description	:	Outputs the string s to the given file descriptor.
 * Param		
 * 			s	:	The string to output.
 * 			fd	:	The file descriptor on which to write.
 * Return Value	:	NONE
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
