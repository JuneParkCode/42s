/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:28:01 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/24 10:50:45 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../include/ft_printf.h"

/* Function 	: 	ft_strlen
 * Description	:	computes length of string s
 * Param		:
 * 			s	:	address of first character of string to test
 * return value	:	characters that precede the terminating NUL charcter
 */
size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}
