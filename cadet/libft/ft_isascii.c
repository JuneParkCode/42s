/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:15:55 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/09 18:45:44 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function		:	ft_isascii
 * Description	:	tests for param 'c' is ascii (0 <= c <= 255) (unsigned case)
 * Param		
 * 			c	:	number to test
 * Return Value	:	1 (TRUE) : c is ascii code
 * 					0 (FALSE) : c is not ascii code
 */
int	ft_isascii(int c)
{
	return (0x0 <= (unsigned char) c && (unsigned char) c <= 0177);
}
