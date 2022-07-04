/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:40:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 10:21:18 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	if (push_swap(argc, argv) == FAILED)
		ft_printf("Error\n");
	return (0);
}
