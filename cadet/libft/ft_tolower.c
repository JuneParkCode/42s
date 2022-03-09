/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:04:32 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/09 19:09:36 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

/* Function		:	ft_tolower
 * Description	:	convert lower case to upper case letter
 * Param		
 * 			c	:	letter to convert
 * Return Value	:	converted letter c
 */
int	ft_tolower(int c)
{
	if (isupper(c))
		return (c + 'a' - 'A');
	return (c);
}
