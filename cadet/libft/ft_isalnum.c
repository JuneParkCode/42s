/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:13:38 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/09 19:10:12 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

static int	isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

/* Function		:	ft_isalnum
 * Description	:	tests for param 'c' that  isalpha or is isdigit is true
 * Param		
 * 			c	:	number to test
 * Return Value	:	1 (TRUE) : c is alphabet or digit
 * 					0 (FALSE) : c is not alphabet and digit
 */
int	ft_isalnum(int c)
{
	return (isalpha(c) || isdigit(c));
}
