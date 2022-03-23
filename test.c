/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:43:41 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/23 15:49:37 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*test;

	test = malloc(1);
	ft_printf("Hello world\n\n addr : %p\n", NULL);
}
