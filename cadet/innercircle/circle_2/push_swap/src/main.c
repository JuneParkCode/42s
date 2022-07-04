/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:40:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 17:15:51 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		return (FAILED);
	if (push_swap(argc, argv) == FAILED)
	{
		ft_putstr_fd("Error\n", FD_STDERR);
		return (FAILED);
	}
	return (SUCCESS);
}
